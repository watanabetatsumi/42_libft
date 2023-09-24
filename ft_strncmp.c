/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatwatan <tatwatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:52:01 by tatwatan          #+#    #+#             */
/*   Updated: 2023/09/25 06:43:31 by tatwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (--n && *s1 != '\0' && *s2 != '\0' && *(s1++) == *(s2++))
		continue ;
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char letter1[] = "abcde";
// 	char letter2[] = "abde";
// 	int a = ft_strncmp(letter1, letter2, 3);

// 	printf("%d",a);
// 	return (0);
// }
