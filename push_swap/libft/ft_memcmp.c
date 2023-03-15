/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:27:32 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/20 13:12:32 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t num)
{
	unsigned char	*aux1;
	unsigned char	*aux2;

	aux1 = (unsigned char *)s1;
	aux2 = (unsigned char *)s2;
	while (num)
	{
		if (*aux1 != *aux2)
			return (*aux1 - *aux2);
		num--;
		aux1++;
		aux2++;
	}
	return (0);
}
