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
void *ft_memmove(void *dst, const void *src, int len)
{
    unsigned char *d = dst;
    const unsigned char *s = src;
    int i;

    i = len - 1;
    if (s == d || len == 0)
        return (dst);
    if (d < s)
    {
        ft_memcpy(dst, src, len);
    }
    else
    {
        while (i >= 0)
        {
            d[i] = s[i];
            i--;
        }
    }

    return (d);
}



