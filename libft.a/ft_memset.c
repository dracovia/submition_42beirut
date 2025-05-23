void *ft_memset(void *b, int c,int len) {
    int i;
    unsigned char *p = (unsigned char *)b;

    i = 0 ;
    while (i < len)
    {
       p[i] = (unsigned char)c;    
       i++;
    }
    return (b);
}

