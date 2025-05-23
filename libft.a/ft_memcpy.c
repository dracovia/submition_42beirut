void *ft_memcpy(void *dst, const void *src, int n)
{
    int i;
    unsigned char *p;
    const unsigned char *s;

    i = 0;
    p = (unsigned char *)dst;
    s = (const unsigned char*)src;
    while (i < n)
    {
        p[i] = s[i];
        i++;
    }
    return (dst);
}
