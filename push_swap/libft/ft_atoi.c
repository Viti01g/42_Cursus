/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:56:31 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/10 16:44:38 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int				a;
	unsigned int	b;
	int				sign;

	a = 0;
	b = 0;
	sign = 0;
	while (str[a] == '\t' || str[a] == '\r' || str[a] == ' ' || str[a] == '\n' \
			|| str[a] == '\f' || str [a] == '\v')
		a++;
	if (str[a] == '+' || str[a] == '-')
	{
		if (str[a++] == '-')
			sign ++;
	}
	while (str[a] >= '0' && str[a] <= '9')
		b = (b * 10) + (str[a++] - '0');
	if (b > 2147483647 && !sign)
		return (-1);
	else if (b > 2147483648 && sign)
		return (0);
	else if (sign)
		return ((int)b * -1);
	return ((int) b);
}
