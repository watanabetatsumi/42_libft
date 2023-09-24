/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatwatan <tatwatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:41:56 by tatwatan          #+#    #+#             */
/*   Updated: 2023/09/25 04:57:27 by tatwatan         ###   ########.fr       */
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
// 	ft_strrchr();
// 	return (0);
// }
