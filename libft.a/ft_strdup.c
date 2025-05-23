#include <stdlib.h>

char *ft_strdup(const char *s1) {

    char *dup;
    int len ;
    int i;

    i = 0;
    len = ft_strlen(s1);
    dup =(char *)malloc(sizeof(char) * (len+1));
    if (!dup)
        return NULL;
    while (s1[i])
    {
        dup[i] = s1[i];
        i++;
    }
    dup[i] = '\0';
    return (dup);
}