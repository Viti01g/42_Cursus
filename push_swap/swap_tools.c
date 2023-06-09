/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:41:26 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/23 14:38:36 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_stack *lista)
{
	t_stack	*aux;
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

int	get_max(t_stack *lista)
{
	t_stack		*aux;
	int			max;
	static int	i;

	i = 0;
	aux = lista;
	max = aux->data1;
	while (aux != NULL)
	{
		if (aux->data1 > max)
			max = aux->data1;
		i++;
		aux = aux->next;
	}
	if (i == 20)
		exit(0);
	return (max);
}

int	check_middle(t_stack *lista)
{
	t_stack	*aux;
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
/* 
void	read_list(t_stack *lst)
{
	t_stack	*aux;
	aux = lst;
	
	while (aux)
	{
		printf("Node content: %d	---		Index content: %d\n", aux->data1, aux->index);
		aux = aux->next;
	}
} */

int	get_distance(t_stack **stacks, int index)
{
	t_stack	*head;
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
