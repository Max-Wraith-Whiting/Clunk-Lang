#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "common.h"
#include "chunk.h"
#include "debug.h"
#include "vm.h"

static void repl() {
    char line[1024];
    for (;;) {
        printf("> ");

        if (!fgets(line, sizeof(line), stdin)) {
            printf("\n");
            break;
        }

        interpret(line);
    }
}

static char* readFile(const char* path) {
    FILE* file = fopen(path, "rb");
    
    fseek(file, 0L, SEEK_END); // Puts file pointer at the end of the file.
    size_t fileSize = ftell(file); // Returns current position in the file (i.e. file size).
    rewind(file); // Put the pointer at the beginning of the file.

    char* buffer = (char*)malloc(fileSize + 1); // Allocate correct amount of memory for source code.
    size_t bytesRead = fread(buffer, sizeof(char), fileSize, file); // Read the binary source from file.
    buffer[bytesRead] = '\0'; // Add terminator at the end of the source code.

    fclose(file);
    return buffer;
}

static void runFile(const char* path) {
    char* source = readFile(path);
    InterpretResult result = interpret(source);
    free(source);

    if (result == INTERPRET_COMPILE_ERROR) exit(65);
    if (result == INTERPRET_RUNTIME_ERROR) exit(70);
}

int main(int argc, const char* argv[]) {
    initVM();

    if (argc == 1) {
        repl();
    } else if (argc == 2) {
        runFile(argv[1]);
    } else {
        fprintf(stderr, "Usage: clunk [path]\n");
        exit(64);
    }

    freeVM();
    return 0;
}