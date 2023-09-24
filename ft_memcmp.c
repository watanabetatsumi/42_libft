/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatwatan <tatwatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 04:46:57 by tatwatan          #+#    #+#             */
/*   Updated: 2023/09/25 07:30:21 by tatwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	while (n--)
	{
		if (*src1 != *src2)
			return (*src1 - *src2);
		src1++;
		src2++;
	}
	return (0);
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_memcmp();
// 	return (0);
// }
