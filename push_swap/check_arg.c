/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:43:37 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/09 13:29:32 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
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

void	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;	

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		tmp = ft_atoi(args[i]);
		if (!ft_isnum(args[i]))
			ft_error_exit();
		if (ft_contains(tmp, args, i))
			ft_error_exit();
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error_exit();
		i++;
	}
	if (argc == 2)
		ft_liberar(args);
}
/* void	check_alg(int argc, stack *lista_a, stack *lista_b)
{
	if (argc == 2)
	{
		if (lista_a->data1 < lista_a->next->data1)
			swap_a(lista_a);
	}
	if (argc == 3)
		alg_tres(lista_a);
	if (argc > 3 && argc <= 10)
		alg_ten(lista_a, lista_b);
} */
