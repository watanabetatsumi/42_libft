/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatwatan <tatwatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:26:29 by tatwatan          #+#    #+#             */
/*   Updated: 2023/09/25 06:56:52 by tatwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	letter;

	letter = (char)c;
	while (*s != '\0')
	{
		if (*s == letter)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_strchr();
// 	return (0);
// }
