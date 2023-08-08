#ifndef clunk_value_h
#define clunk_value_h

#include "common.h"

typedef double Value;

typedef struct {
    int capacity;
    int count;
    Value* values;
} ValueArray;

void initValueArray(ValueArray* array);
void writeValueArray(ValueArray* array);
void freeValueArray(ValueArray* array);
void printValue(Value value);

#endif