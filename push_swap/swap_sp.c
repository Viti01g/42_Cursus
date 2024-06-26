/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_sp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 14:56:29 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/18 17:33:39 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **lista)
{
	long	temp;

	if (!*lista || !((*lista)->next))
		return ;
	temp = (*lista)->data1;
	(*lista)->data1 = (*lista)->next->data1;
	(*lista)->next->data1 = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_stack **lista)
{
	long	temp;

	if (!*lista || !((*lista)->next))
		return ;
	temp = (*lista)->data1;
	(*lista)->data1 = (*lista)->next->data1;
	(*lista)->next->data1 = temp;
	write(1, "sb\n", 3);
}

void	swap_ab(t_stack **lista_a, t_stack **lista_b)
{
	long	aux;
	long	aux2;

	aux = (*lista_a)->data1;
	(*lista_a)->data1 = (*lista_a)->next->data1;
	(*lista_a)->next->data1 = aux;
	aux2 = (*lista_b)->data1;
	(*lista_b)->data1 = (*lista_b)->next->data1;
	(*lista_b)->next->data1 = aux2;
	write(1, "ss\n", 3);
}

void	push_b(t_stack **lst_a, t_stack **lst_b)
{
	t_stack	*aux;

	if (*lst_a)
	{
		aux = (*lst_a)->next;
		(*lst_a)->next = *lst_b;
		*lst_b = *lst_a;
		*lst_a = aux;
		write(1, "pb\n", 3);
	}
}

void	push_a(t_stack **lst_b, t_stack **lst_a)
{
	t_stack	*aux;

	if (*lst_b)
	{
		aux = (*lst_b)->next;
		(*lst_b)->next = *lst_a;
		*lst_a = *lst_b;
		*lst_b = aux;
		write(1, "pa\n", 3);
	}
}
