/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:05:53 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/03/06 15:16:11 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int num)
{
	char	c;

	if (num == -2147483648)
	{
		write(1, "-2", 2);
		num = 147483648;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	if (num < 10)
	{
		c = num + '0';
		write (1, &c, 1);
	}
	else
	{
		ft_putnbr(num / 10);
		ft_putnbr(num % 10);
	}
}
