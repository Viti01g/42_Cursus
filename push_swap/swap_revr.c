/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_revr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 15:02:20 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/18 17:33:27 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_rra(t_stack **lista)
{
	t_stack	*aux;

	aux = ft_listindex(*lista, ft_listsize(*lista) - 1);
	aux->next->next = *lista;
	*lista = aux->next;
	aux->next = 0;
	write(1, "rra\n", 4);
}

void	swap_rrb(t_stack **lista)
{
	t_stack	*aux;

	aux = ft_listindex(*lista, ft_listsize(*lista) - 1);
	aux->next->next = *lista;
	*lista = aux->next;
	aux->next = 0;
	write(1, "rrb\n", 4);
}

void	swap_rrr(t_stack **lista_a, t_stack **lista_b)
{
	t_stack	*aux;
	t_stack	*temp;

	aux = ft_listindex(*lista_a, ft_listsize(*lista_a) - 1);
	aux->next->next = *lista_a;
	*lista_a = aux->next;
	aux->next = 0;
	temp = ft_listindex(*lista_b, ft_listsize(*lista_b) - 1);
	temp->next->next = *lista_b;
	*lista_b = temp->next;
	temp->next = 0;
	write(1, "rrr\n", 4);
}
