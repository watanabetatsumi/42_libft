/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatwatan <tatwatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 20:12:41 by tatwatan          #+#    #+#             */
/*   Updated: 2023/09/25 05:37:47 by tatwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stddef.h>

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (*str)
	{
		str++;
		size ++;
	}
	return (size);
}

// #include<stdio.h>
// int	main(void)
// {
// 	char str[] = "abcdefghijk";
// 	int size;

// 	size = ft_strlen(str);
// 	printf("%d",size);
// }
