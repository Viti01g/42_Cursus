/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:55:10 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/09 13:29:02 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_SUCCESS);
}

void	ft_free(stack *lst)
{
	stack	*aux;
	stack	*aux2;

	aux = lst;
	while (aux)
	{
		aux2 = aux->next;
		free(aux);
		aux = aux2;
	}
}

int	is_sorted(stack **stacks)
{
	stack	*head;

	head = *stacks;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}

void	free_stack(stack **stacks)
{
	stack	*head;
	stack	*tmp;

	head = *stacks;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stacks);
}

void	ft_liberar(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}
