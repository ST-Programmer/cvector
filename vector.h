#pragma once

#include <stdlib.h>
#include <string.h>

#define _InitialVectorCapacity 2
typedef struct
{
    void* _Data;
    size_t _Size;
    size_t _Capacity;
    size_t _TypeSize;
} Vector;

Vector VecCreate(size_t typeSize);
void VecFree(Vector* vec);
void VecReserve(Vector* vec, size_t capacity);
void VecRealloc(Vector* vec);
void VecAppend(Vector* vec, const void* val);
size_t VecSize(Vector* vec);
void* VecAt(Vector* vec, size_t index);
void* VecAtBounds(Vector* vec, size_t index);
