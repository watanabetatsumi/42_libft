/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatwatan <tatwatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:13:06 by tatwatan          #+#    #+#             */
/*   Updated: 2023/09/25 05:00:19 by tatwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stddef.h"

void	ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ds;
	unsigned char	*sr;

	ds = (unsigned char *)dst;
	sr = (unsigned char *)src;

	if (dst > src)
	{
		while (len--)
			ds[len] = sr[len];
	}
	if (dst < src)
	{
		while (len--)
		{
		*ds = *sr;
		ds++;
		sr++;
		}
	}
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_memmove();
// 	return (0);
// }
