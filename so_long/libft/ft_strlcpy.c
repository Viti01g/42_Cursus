/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 16:29:58 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/26 16:14:13 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	num;
	size_t	src_lem;

	src_lem = 0;
	num = 0;
	while (src[src_lem])
		src_lem++;
	if (destsize == 0)
		return (src_lem);
	while (*(src + num) && --destsize)
	{
		*dest++ = *(src + num++);
	}
	*dest = '\0';
	while (*(src + num))
	{
		num++;
	}
	return (num);
}
/*
int main()
{
    char dest[30] = "Derrota";
    char src[20] = "Victoria";
    printf("%zu", ft_strlcpy(dest, src, 2));
    return(0);
}*/
