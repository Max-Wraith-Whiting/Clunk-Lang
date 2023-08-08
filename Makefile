# General CLunk Makefile.
#
# MODE :			"debug" or "release" (debug obviously debugs it).
# NAME :			Name of the output .exe (and the .o file directory).
# SOURCE_DIR :		Source directory, where .c and .h files are to be found. 			

NAME := CLunk
MODE := debug
SOURCE_DIR := ./src

CFLAGS := -std=c99 -Wall -Werror

# Mode configuration
ifeq ($(MODE),release)
		CFLAGS += -Wno-unused-parameter -O3 -flto
		BUILD_DIR := build/release

else
		CFLAGS += -O0 -DDEBUG -g
		BUILD_DIR := build/debug

endif

# Files
HEADERS := $(wildcard $(SOURCE_DIR)/*.h)
SOURCES := $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS := $(addprefix $(BUILD_DIR)/$(NAME)/,$(notdir $(SOURCES:.c=.o)))

# --- Targets ---

# Linking
build/$(NAME): $(OBJECTS)
	@printf "%8s %-40s %s\n" $(CC) $@ "$(CFLAGS)"
	@mkdir -p build
	@$(CC) $(CFLAGS) $^ -o $@

# Compile .o files
$(BUILD_DIR)/$(NAME)/%.o: $(SOURCE_DIR)/%.c $(HEADERS)
	@printf "%8s %-40s %s\n" $(CC) $< "$(CFLAGS)"
	@mkdir -p $(BUILD_DIR)/$(NAME)
	@$(CC) -c $(C_LANG) $(CFLAGS) -o $@ $<

.PHONY: default clean run

clean:
	@rm -rvf ./build
	@echo "Build cleaned."

run: $(BUILD_DIR)
	@echo "------ Executing CLunk ------"
	@./build/CLunk

$(BUILD_DIR):
	make

