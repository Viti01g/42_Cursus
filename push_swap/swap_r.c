/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_r.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:22:44 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/04/18 13:27:16 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ra(stack **lista)
{
	stack	*aux;

	if (ft_listsize(*lista) > 1)
	{
		aux = (*lista)->next;
		ft_listlast(*lista)->next = *lista;
		(*lista)->next = NULL;
		*lista = aux;
		write(1, "ra\n", 3);
	}
}

void	swap_rb(stack **lista)
{
	stack *aux;

	if (ft_listsize(*lista) > 1)
	{
		aux = (*lista)->next;
		ft_listlast(*lista)->next = *lista;
		(*lista)->next= NULL;
		*lista = aux;
		write(1, "rb\n", 3);
	}
}

void	swap_rr(stack **lista_a, stack **lista_b)
{
	stack	*aux1;
	stack	*aux2;

	if (ft_listsize(*lista_a) > 1)
	{
		aux1 = (*lista_a)->next;
		ft_listlast(*lista_a)->next = *lista_a;
		(*lista_a)->next = NULL;
		*lista_a = aux1;
	}
	if (ft_listsize(*lista_b) > 1)
	{
		aux2 = (*lista_b)->next;
		ft_listlast(*lista_b)->next = *lista_b;
		(*lista_b)->next = NULL;
		*lista_b = aux2;
	}
	write(1, "rr\n", 3);
}
