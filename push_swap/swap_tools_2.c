/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tools_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 16:52:55 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/10 16:59:14 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi_ps(char *str)
{
	int				sign;
	int				i;
	long long int	j;

	i = 0;
	j = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (ft_is_nbr_space_valid(str) == 0)
		ft_error_exit();
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i])
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	if ((sign * j) > 2147483647 || (sign * j) < -2147483648)
		ft_error_exit();
	return (sign * j);
}

int	ft_is_nbr_space_valid(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) > 11)
		ft_error_exit();
	while (str[i])
	{
		if (str[i] == ' ' || ft_isdigit(str[i]) == 1)
			i++;
		else if (i == 0 && ((str[i] == '-' || str[i] == '+')
				&& ft_isdigit(str[i + 1]) == 1))
			i++;
		else
			return (0);
	}
	return (1);
}
