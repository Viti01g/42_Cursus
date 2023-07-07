/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:03:10 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/19 15:44:00 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*aux;
	size_t			i;

	aux = (unsigned char *)str;
	i = 0;
	while (i < n)
	{
		if (aux[i] == (unsigned char)c)
			return ((unsigned char *)&str[i]);
		i++;
	}
	return (NULL);
}
/*
int main()
{
	char destin[] = "Bonjorno";
	printf("%s", ft_memchr(destin, 'n', 2));
	return (0);
}*/