/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatwatan <tatwatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 22:11:13 by tatwatan          #+#    #+#             */
/*   Updated: 2023/09/25 05:57:42 by tatwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"stddef.h"

void	*ft_memset(void *buf, int c, size_t n)
{
	unsigned char	set;
	unsigned char	*str;

	str = (unsigned char *)buf;
	set = (unsigned char)c;
	while (n--)
	{
		*str = set;
		str++;
	}
	return (buf);
}

// #include        <stdio.h>
// #include        <string.h>

// int main(void)
// {
//         char str[] = "0123456789";
        
//         ft_memset(str+2, '*', 5);
        
//         printf("%s\n",str);

//         return 0;
// }