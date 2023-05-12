/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:15:42 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/12 16:46:25 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_algor(stack *lista_a, stack *lista_b)
{
	//printf("hbf: %d\n", ft_listsize(lista_a));
	//printf("first a: %i\n", lista_a->data1);
	//read_list(lista_a);
	if (ft_listsize(lista_a) <= 5)
		algs_cortos(&lista_a, &lista_b);
	else
		radix_sort(&lista_a, &lista_b);
}
