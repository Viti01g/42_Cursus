/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 19:07:04 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/02/04 20:05:29 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long int n)
{
	int	c;

	c = 0;
	if (n == 0)
		c++;
	if (n < 0)
	{
		n *= -1;
		c++;
	}
	while (n > 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

static char	*gestnum(char *str, long num, int i)
{
	if (num == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (num < 0)
	{
		str[0] = '-';
		num *= -1;
	}
	while (num > 0)
	{
		str[i--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	num;
	int		i;

	num = n;
	i = ft_intlen(num);
	str = malloc(sizeof(char) * (i + 1));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	str = gestnum(str, num, i);
	return (str);
}
