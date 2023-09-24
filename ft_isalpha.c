/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tatwatan <tatwatan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 19:05:03 by tatwatan          #+#    #+#             */
/*   Updated: 2023/09/25 05:37:31 by tatwatan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int alpha)
{
	if (65 <= alpha && alpha <= 90)
		return (1);
	if (97 <= alpha && alpha <= 122)
		return (1);
	return (0);
}

// #include <stdio.h>
// #include <ctype.h>

// int main() {
//     char ch = '2';

//     if (ft_isalpha(ch)) {
//         printf("%c はアルファベットの文字です。\n", ch);
//     } else {
//         printf("%c はアルファベットの文字ではありません。\n", ch);
//     }

//     return 0;
// }
