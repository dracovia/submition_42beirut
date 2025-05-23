#include <stdio.h>

void *ft_memchr(const void *s, int c, int n)
{
    int i;
    const unsigned char *s2;
    unsigned char c2;

    i = 0;
    s2 = (const unsigned char *)s;
    c2 = (unsigned char )c;
    while (i < n)
    {
        if (s2[i] == c2)
        {
            return ((void *)&s2[i]);
        }
        i++;
    }
    return (NULL);
}

