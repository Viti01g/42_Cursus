/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 18:52:42 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/17 14:38:17 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *str, size_t num)
{
	char	*aux;

	aux = (char *)str;
	while (num > 0)
	{
		aux[num - 1] = '\0';
		num--;
	}
	return (str);
}
/*
int main()
{
    char str[30] = "Mosquito";
    printf("%s", ft_bzero(str, 3));
    return(0);
}*/
