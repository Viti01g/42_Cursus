/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:32:46 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/03/10 12:59:13 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_params(char s, va_list args, int *len, int *i)
{
	if (s == 's')
		ft_print_str(va_arg(args, char *), len);
	else if (s == 'd')
		ft_print_num(va_arg(args, int), len);
	else if (s == 'c')
		(*len) += ft_print_char(va_arg(args, int));
	else if (s == 'p')
	{
		write(1, "0x", 2);
		(*len) += 2;
		(*len) += ft_print_pointer(va_arg
				(args, unsigned long int), "0123456789abcdef");
	}
	else if (s == 'i')
		ft_print_num(va_arg(args, int), len);
	else if (s == 'u')
		ft_upn_base(va_arg(args, int), "0123456789", len);
	else if (s == 'x')
		ft_upn_base(va_arg(args, int), "0123456789abcdef", len);
	else if (s == 'X')
		ft_upn_base(va_arg(args, int), "0123456789ABCDEF", len);
	else if (s == '%')
		(*len) += ft_print_char('%');
	else
		(*i)--;
}

int	ft_printf(char const *str, ...)
{
	int		i;
	int		len;
	va_list	args;

	va_start(args, str);
	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			check_params(str[i], args, &len, &i);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
/*
int main()
{
	int x;
	//int i = -1;
	char str[] = "Julio";
	x = ft_printf("%p\n%s\n", str, str);
	//j = printf("%p\n", str);
	ft_printf("%d\n", x);
	
	return(0);
}*/
