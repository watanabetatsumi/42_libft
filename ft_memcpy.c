/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatwatan <tatwatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 23:10:05 by tatwatan          #+#    #+#             */
/*   Updated: 2023/09/25 06:45:53 by tatwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*ds;
	unsigned char	*sr;

	if (dst == '\0' && src == '\0')
		return (NULL);
	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;
	while (n--)
	{
		*ds = *sr;
		ds++;
		sr++;
	}
	return (dst);
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_memcpy();
// 	return (0);
// }
