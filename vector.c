#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector VecCreate(size_t typeSize)
{
    Vector vec = {._Data = malloc(typeSize * _InitialVectorCapacity),
                  ._Size = 0,
                  ._Capacity = _InitialVectorCapacity,
                  ._TypeSize = typeSize};

    return vec;
}

void VecFree(Vector* vec)
{
    free(vec->_Data);

    vec->_Data = NULL;
    vec->_Size = 0;
    vec->_Capacity = 0;
    vec->_TypeSize = 0;
}

void VecReserve(Vector* vec, size_t capacity)
{
    if (capacity > vec->_Capacity)
    {
        vec->_Capacity = capacity;
        vec->_Data = realloc(vec->_Data, vec->_Capacity * vec->_TypeSize);
    }
}

void VecRealloc(Vector* vec)
{
    vec->_Capacity *= 2;
    vec->_Data = realloc(vec->_Data, vec->_Capacity * vec->_TypeSize);

    printf("Reallocation\n");
}

void VecAppend(Vector* vec, const void* val)
{
    if (vec->_Size >= vec->_Capacity)
    {
        VecRealloc(vec);
    }

    memcpy((char*)vec->_Data + vec->_Size * vec->_TypeSize, val, vec->_TypeSize);
    vec->_Size++;
}

size_t VecSize(Vector* vec) { return vec->_Size; }

void* VecAt(Vector* vec, size_t index)
{
    return (void*)((char*)vec->_Data + index * vec->_TypeSize);
}

void* VecAtBounds(Vector* vec, size_t index)
{
    if (index < vec->_Size)
    {
        return VecAt(vec, index);
    }

    return NULL;
}
