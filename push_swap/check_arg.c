/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 15:43:37 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/04/26 13:03:27 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_alg(int argc, stack *lista_a, stack *lista_b)
{
	if (argc == 2)
	{
		if (lista_a->data1 < lista_a->next->data1)
			swap_a(lista_a);
	}
	if (argc == 3)
		alg_tres(lista_a);
	if (argc > 3 && argc <= 10)
		alg_ten(lista_a, lista_b);
}
