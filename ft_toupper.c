/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatwatan <tatwatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 03:18:14 by tatwatan          #+#    #+#             */
/*   Updated: 2023/09/25 05:06:37 by tatwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (97 <= c && c<= 122)
		c = c - 32;
	return (c);
}

// #include <stdio.h>
// int main(void)
// {
// 	ft_toupper();
// 	return (0);
// }
