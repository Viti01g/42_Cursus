/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_<10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:13:51 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/04/21 12:46:18 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_3(stack *lista)
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
