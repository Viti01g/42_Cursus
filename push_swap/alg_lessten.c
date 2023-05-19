/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_lessten.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:12:42 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/18 17:36:16 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_tres(t_stack **lista)
{
	int		a;
	int		b;
	int		c;
	t_stack	**aux;

	aux = lista;
	a = (*aux)->data1;
	b = (*aux)->next->data1;
	c = (*aux)->next->next->data1;
	if (b < a && a < c)
		swap_a(lista);
	if (c < b && b < a)
	{
		swap_a(lista);
		swap_rra(lista);
	}
	if (b < c && c < a)
		swap_ra(lista);
	if (b > c && c > a)
	{
		swap_a(lista);
		swap_ra(lista);
	}
	if (b > a && a > c)
		swap_rra(lista);
}

void	alg_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	while ((*stack_a)->data1 != min)
	{
		if (check_middle(*stack_a) == 1)
			swap_ra(stack_a);
		else
			swap_rra(stack_a);
	}
	push_b(stack_a, stack_b);
	alg_tres(stack_a);
	push_a(stack_b, stack_a);
}

void	alg_five(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	while ((*stack_a)->data1 != min)
	{
		if (check_middle(*stack_a) == 1)
			swap_ra(stack_a);
		else
			swap_rra(stack_a);
	}
	push_b(stack_a, stack_b);
	alg_four(stack_a, stack_b);
	push_a(stack_a, stack_b);
}

void	algs_cortos(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_listsize(*stack_a);
	if (ft_listsize(*stack_a) == 0 || ft_listsize(*stack_a) == 1)
		return ;
	if (size == 2)
	{	
		if ((*stack_a)->data1 > (*stack_a)->next->data1)
			swap_a(stack_a);
	}
	else if (size == 3)
		alg_tres(stack_a);
	else if (size == 4)
	{
		alg_four(stack_a, stack_b);
	}
	else if (size == 5)
		alg_five(stack_a, stack_b);
}
