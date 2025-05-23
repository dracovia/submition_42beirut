#include <stdlib.h>

void *ft_calloc(size_t count, size_t size)
{
    void *array;

    if (count == 0 || size == 0)
        return malloc(1);
    array = malloc(size * count);
    if (!array)
        return NULL;
    ft_bzero(array, count * size);
    return array;
}

