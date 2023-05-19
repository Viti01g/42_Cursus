/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:55:10 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/19 14:26:25 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free(t_stack *lst)
{
	t_stack	*aux;
	t_stack	*aux2;

	aux = lst;
	while (aux)
	{
		aux2 = aux->next;
		free(aux);
		aux = aux2;
	}
}

int	is_sorted(t_stack **stacks)
{
	t_stack	*head;

	head = *stacks;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	free_stack(t_stack **stacks)
{
	t_stack	*tmp;
	t_stack	*aux;

	tmp = *stacks;
	while (tmp)
	{
		aux = tmp;
		tmp = tmp->next;
		free(aux);
	}
}

void	ft_liberar(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
