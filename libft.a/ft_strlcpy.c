int  ft_strlen(const char *s)
{
    int  len = 0;
    while (s[len])
        len++;
    return (len);
}

int ft_strlcpy(char *dst, const char *src, int dstsize)
{
    int i = 0;

    if (dstsize > 0)
    {
        while (src[i] && i < dstsize - 1)
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }

    return (ft_strlen(src));
}
