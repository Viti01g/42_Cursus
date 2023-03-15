/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:42:23 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/19 15:38:02 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t num)
{
	char	*aux;
	char	*aus;

	aux = (char *)dest;
	aus = (char *)src;
	if (!aus && !aux)
		return (NULL);
	while (num > 0)
	{
		aux[num - 1] = aus[num - 1];
		num--;
	}
	return (dest);
}
/*
int main()
{
    char destin[50] = "PolillaTraviesa";
    char source[50] = "Mosquito";
    printf("%s", ft_memcpy(destin, source, 7));
    return(0);
}*/
