/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_lessten.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:13:51 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/04 19:55:15 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	alg_tres(stack *lista)
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
}
void	alg_ten(stack *lista_a, stack *lista_b)
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
}
void	alg_100(stack *lista_a, stack *lista_b)
{
	int nbr;
	int	cont;
	//int	max;

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
		read_list(lista_b);
		printf("Numeros en b: %d\n", ft_listsize(lista_b));
		printf("el maximo de la lista b es: %d\n", get_max(lista_b));
	while (lista_b != NULL)
	{
		lista_b = pinturillo(lista_b, lista_a);
	}
		printf("Lista a\n");
		read_list(lista_a);
/* 	max = get_max(lista_b);
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
		push_a(&lista_b, &lista_a);*/
}
