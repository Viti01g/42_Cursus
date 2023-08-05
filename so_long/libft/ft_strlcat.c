/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 17:08:10 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/24 14:46:06 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t	i;
	size_t	k;
	size_t	destlen;

	i = 0;
	destlen = ft_strlen(dest);
	k = destlen;
	if (destlen < destsize - 1 && destsize > 0)
	{
		while (src[i] && destlen + i < destsize - 1)
			dest[k++] = src[i++];
		dest[k] = '\0';
	}
	if (destlen >= destsize)
		destlen = destsize;
	return (destlen + ft_strlen(src));
}
/*
int main()
{
	printf("%d\n", strlcat("Hola", "Adios", 3));
	printf("%d", ft_strlcat("Hola", "Adios", 3));
	return (0);
}*/
