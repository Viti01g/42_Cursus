/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:41:26 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/09 16:49:58 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(stack *lista)
{
	stack	*aux;
	int		min;

	aux = lista;
	min = aux->data1;
	while (aux != NULL)
	{
		if (aux->data1 < min)
			min = aux->data1;
		aux = aux->next;
	}
	return (min);
}

int	get_max(stack *lista)
{
	stack	*aux;
	int		max;
	static int i = 0;

	aux = lista;
	max = aux->data1;
	while (aux != NULL)
	{
		//read_list(lista);
		if (aux->data1 > max)
			max = aux->data1;
		i++;
		aux = aux->next;
	}
	if (i == 20)
		exit(0);
	return (max);
}

int	check_middle(stack *lista)
{
	stack	*aux;
	int		min;
	int		cont;

	cont = 0;
	aux = lista;
	min = get_min(lista);
	while (aux->next != NULL)
	{
		if (aux->data1 == min)
			break ;
		aux = aux->next;
		cont++;
	}
	if (cont < ft_listsize(lista) / 2)
		return (1);
	else
		return (2);
	return (0);
}

void	read_list(stack *lst)
{
	stack	*aux;

	aux = lst;
	while (aux)
	{
		printf("Node content: %d\n", aux->data1);
		aux = aux->next;
	}
}

int	get_distance(stack **stacks, int index)
{
	stack	*head;
	int		distance;

	distance = 0;
	head = *stacks;
	while (head)
	{
		if (head->data1 == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}
