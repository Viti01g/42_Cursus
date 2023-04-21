/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:55:10 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/04/19 13:12:13 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_exit(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_SUCCESS);
}

void	ft_free(t_list *lst)
{
	t_list	*aux;
	t_list	*aux2;

	aux = lst;
	while (aux)
	{
		aux2 = aux->next;
		free(aux);
		aux = aux2;
	}
}
