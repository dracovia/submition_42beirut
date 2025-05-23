
#include <stdio.h>

char *ft_strrchr(const char *s, int c) {
	const char *last;

    last = NULL;
	while (*s) {
		if (*s == (char)c)
			last = s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)last);
}
