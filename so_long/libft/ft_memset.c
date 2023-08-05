/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:57:32 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/17 14:36:55 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t num)
{
	char	*aux;

	aux = (char *)str;
	while (num > 0)
	{
		aux[num - 1] = c;
		num--;
	}
	return (str);
}
/*
int main()
{
    char str[50] = "Piña con pizza";
    printf("%s", ft_memset(str, 't', 2));
    return(0);
}*/
