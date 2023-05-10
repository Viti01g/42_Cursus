/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_alg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:15:42 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/09 17:10:42 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_algor(stack *lista_a, stack *lista_b)
{
	if (ft_listsize(lista_a) <= 5)
		algs_cortos(&lista_a, &lista_b);
	else
		radix_sort(&lista_a, &lista_b);
}
