/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_nums.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:07:24 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/06/27 16:27:49 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_num(int num, int *len)
{
	if (num == -2147483648)
	{
		write(1, "-2", 2);
		num = 147483648;
		(*len) += 2;
	}
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
		(*len)++;
	}
	if (num < 10)
		(*len) += ft_print_char(num + '0');
	else
	{
		ft_print_num(num / 10, len);
		(*len) += ft_print_char(num % 10 + '0');
	}
}

static size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_upn_base(unsigned long int nbr, char *base, int *len)
{
	unsigned int	j;
	unsigned int	lenght;

	lenght = ft_strlen(base);
	j = nbr;
	if (j >= lenght)
		ft_upn_base(j / lenght, base, len);
	(*len) += ft_print_char(base[j % lenght]);
}

int	ft_print_pointer(unsigned long int nbr, char *base)
{
	int				j;
	unsigned int	lenght;

	lenght = ft_strlen(base);
	j = 0;
	if (nbr >= lenght)
		j += ft_print_pointer(nbr / lenght, base);
	j += ft_print_char(base[nbr % lenght]);
	return (j);
}
