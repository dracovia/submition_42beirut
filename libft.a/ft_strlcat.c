int  ft_strlen(const char *s)
{
    int  len = 0;
    while (s[len])
        len++;
    return (len);
}

int ft_strlcat(char *dst, const char *src, int dstsize)
{
    int i = 0;
    int j = 0;

    while (i < dstsize && dst[i])
        i++;

    if (i == dstsize)
        return dstsize + strlen(src);

    while (src[j] && (i + j + 1) < dstsize)
    {
        dst[i + j] = src[j];
        j++;
    }

    if (i + j < dstsize)
        dst[i + j] = '\0';

    return i + strlen(src);
}
