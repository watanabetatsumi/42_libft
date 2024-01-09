/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatsumi <tatsumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:41:56 by tatwatan          #+#    #+#             */
/*   Updated: 2024/01/03 01:37:28 by tatsumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*temp;
	char	letter;

	letter = (char)c;
	temp = NULL;
	while (*s != '\0')
	{
		if (*s == letter)
			temp = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (temp);
}

// #include <stdio.h>
// int main(void)
// {
// 	char *letter;

// 	letter = "abcdefg";
// 	printf("%p\n",ft_strrchr(letter, 'e'));
// 	return (0);
// }
