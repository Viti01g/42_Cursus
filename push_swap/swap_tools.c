/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:41:26 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/04 19:51:21 by vruiz-go         ###   ########.fr       */
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
		printf("%d\n", aux->data1);
		i++;
		aux = aux->next;
	}
	printf("num max: %d\n", max);
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

stack	*pinturillo(stack *lista_b, stack *lista_a)
{
	int	max;

	max = get_max(lista_b);
	if (check_middle(lista_b) == 1)
	{
		while (lista_b->data1 != max)
			swap_ra(&lista_b);
	}
	else if (check_middle(lista_b) == 2)
	{
		while (lista_b->data1 != max)
			swap_rra(&lista_b);
	}
	push_a(&lista_b, &lista_a);
	return (lista_b);
}