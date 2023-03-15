/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 16:33:00 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/03/10 12:56:06 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <limits.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(char const *str, ...);
int		ft_print_char(char c);
void	ft_print_str(char *str, int *len);
void	ft_print_num(int num, int *len);
int		ft_print_pointer(unsigned long int nbr, char *base);
void	ft_upn_base(unsigned long int nbr, char *base, int *len);

#endif
