/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:43:37 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/19 14:29:45 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi_ps(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static char	**ft_puebas(char **argv)
{
	int		i;
	char	**args;

	i = 1;
	while (argv[i])
	{
		args = ft_split(argv[i], ' ');
		if (argv[i + 1])
			ft_liberar(args);
		i++;
	}
	return (args);
}

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	if (argc < 2)
		exit(EXIT_FAILURE);
	args = ft_puebas(argv);
	i = 0;
	while (args[i])
	{
		tmp = ft_atoi_ps(args[i]);
		if (!ft_isnum(args[i]))
			ft_error_exit();
		if (ft_contains(tmp, args, i))
			ft_error_exit();
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error_exit();
		i++;
	}
	ft_liberar(args);
}
