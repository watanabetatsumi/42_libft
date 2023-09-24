#include "stddef.h"

void ft_bzero(void *s, size_t n)
{
    unsigned char	*str;

	str = (unsigned char*)s;
    while (n--)
    {
		*str = '\0';
		str++;
    }
}

#include <strings.h>
// #include <stdio.h>
// int main(void)
// {
// 	ft_bzero();
// 	return (0);
// }
