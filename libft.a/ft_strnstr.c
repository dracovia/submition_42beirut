#include <stdio.h>

char *ft_strnstr(const char *haystack, const char *needle, int len) 
{
    int i = 0;
    int j;

    if (*needle == '\0')
        return (char *)haystack;

    while (haystack[i] && i < len)
    {
        j = 0; 
        while (haystack[i + j] == needle[j] && (i + j) < len)
        {
            if (needle[j + 1] == '\0')
                return (char *)(haystack + i);
            j++;
        } 
        i++;
    }
    return NULL;
}



