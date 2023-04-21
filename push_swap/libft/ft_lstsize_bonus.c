/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 17:39:28 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/04/17 13:13:40 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		cont;
	t_list	*aux;

	aux = lst;
	cont = 0;
	if (!lst)
		return (0);
	while (aux)
	{
		aux = aux->next;
		cont++;
	}
	return (cont);
}
