/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatsumi <tatsumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 20:06:45 by tatwatan          #+#    #+#             */
/*   Updated: 2024/01/12 05:32:18 by tatsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// size_t    ft_strlen(const char *str)
// {
//     size_t    size;

//     size = 0;
//     while (*str++)
//         size++;
//     return (size);
// }

char    *ft_strnstr(const char *s1, const char *s2, size_t len)
{
    size_t    index;
    size_t    extra;
    size_t    len_s2;

    index = 0;
    extra = 0;
    len_s2 = ft_strlen(s2);
    if ((len == 0 && len_s2 != 0) || (len == 0 && s1 == NULL))
        return (NULL);
    if (len_s2 == 0 || len == 0)
        return ((char *)s1);
    while ((len - index) >= len_s2)
    {
        while (s1[index + extra] == s2[extra])
        {
            extra++;
            if (s2[extra] == '\0')
                return ((char *)&s1[index]);
        }
        extra = 0;
        index ++;
    }
    return (NULL);
}

// #include <string.h>
// int main(void)
// {
//     char *str1 = "fake";
//     char *str2 = "";
//     // size_t size = ft_strlen(str1);
//     size_t size = 3;
//     //n=0の時は0を返す・・未実装
//     // printf("%p\n",strnstr(str1,str2,size));
//     printf("%p\n",ft_strnstr(str1,str2,size));
//     return (0);
// }