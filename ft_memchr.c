#include "libft.h"

void *ft_memchr(const void *s, int c, size_t n)
{
    unsigned char   letter;
    unsigned char   *src;

    letter = (unsigned char)c;
    src = (unsigned char *)s;
    while (n--)
    {
        if (*src == letter)
            return ((void *)src);
        src++;
    }
    return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_memchr();
// 	return (0);
// }
