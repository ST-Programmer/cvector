#include "vector.h"
#include <stdio.h>

int main(void)
{
    Vector vec = VecCreate(sizeof(int32_t));
    VecReserve(&vec, 5);

    for (int32_t i = 1; i <= 20; i *= 2)
    {
        VecAppend(&vec, &i);
    }

    for (int i = 0; i < VecSize(&vec); i++)
    {
        printf("%d ", *(int32_t*)VecAt(&vec, i));
    }

    printf("\n");

    return 0;
}
