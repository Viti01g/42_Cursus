/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_radi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:13:51 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/18 17:32:26 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(t_stack **stacks)
{
	t_stack	*head;
	int		max;
	int		max_bits;

	head = *stacks;
	max = head->data1;
	max_bits = 0;
	while (head)
	{
		if (head->data1 > max)
			max = head->data1;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	i = 0;
	head_a = *stack_a;
	size = ft_listsize(head_a);
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (((head_a->data1 >> i) & 1) == 1)
				swap_ra(stack_a);
			else
				push_b(stack_a, stack_b);
		}
		while (ft_listsize(*stack_b) != 0)
			push_a(stack_b, stack_a);
		i++;
	}
}

/* void	alg_tres(stack *lista)
{
	int		a;
	int		b;
	int		c;
	stack	*aux;

	aux = lista;
	a = aux->data1;
	b = aux->next->data1;
	c = aux->next->next->data1;
	if (b < a && a < c)
		swap_a(lista);
	if (c < b && b < a)
	{
		swap_a(lista);
		swap_rra(&lista);
	}
	if (b < c && c < a)
		swap_ra(&lista);
	if (b > c && c > a)
	{
		swap_a(lista);
		swap_ra(&lista);
	}
	if (b > a && a > c)
		swap_rra(&lista);
} */
/* void	alg_ten(stack *lista_a, stack *lista_b)
{
	int		min;

	while (ft_listsize(lista_a) > 2)
	{
		min = get_min(lista_a);
		if (check_middle(lista_a) == 1)
		{
			while (lista_a->data1 != min)
				swap_ra(&lista_a);
		}
		else if (check_middle(lista_a) == 2)
		{
			while (lista_a->data1 != min)
				swap_rra(&lista_a);
		}
		push_b(&lista_a, &lista_b);
	}
	if (lista_a->data1 < lista_a->next->data1)
		swap_a(lista_a);
	while (lista_b != NULL)
		push_a(&lista_b, &lista_a);
} */
/* void	alg_cien(stack *lista_a, stack *lista_b)
{
	int nbr;
	int	cont;

	nbr = 20;
	cont = 0;
	while (ft_listsize(lista_a) > 2 && nbr <= 100)
	{
		while (cont < nbr)
		{
			if (lista_a->data1 <= nbr)
			{
				push_b(&lista_a, &lista_b);
				cont++;
			}
			else
				swap_rra(&lista_a);		
		}
		nbr += 20;
	}
	while (lista_b != NULL)
		pinturillo(&lista_b, &lista_a);
}

void	alg_quinientos(stack *lista_a, stack *lista_b)
{
	int nbr;
	int	cont;

	nbr = 50;
	cont = 0;
	while (ft_listsize(lista_a) > 2 && nbr <= 500)
	{
		while (cont < nbr)
		{
			if (lista_a->data1 <= nbr)
			{
				push_b(&lista_a, &lista_b);
				cont++;
			}
			else
				swap_rra(&lista_a);		
		}
		nbr += 50;
	}
	while (lista_b != NULL)
		pinturillo(&lista_b, &lista_a);
} */
