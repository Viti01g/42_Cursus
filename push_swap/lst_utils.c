/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:25:47 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/04/18 15:30:37 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_listsize(stack *lst)
{
	int		cont;
	stack	*aux;

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

stack	*ft_listlast(stack *lst)
{
	stack	*temp;

	temp = lst;
	while (temp != NULL)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	return (temp);
}

stack	*ft_listindex(stack *lst, int index)
{
	stack	*aux;
	int		i;

	if (index > ft_listsize(lst))
	{
		return (ft_listlast(lst));
	}
	i = 1;
	aux = lst;
	while (i < index)
	{
		aux = aux->next;
		i++;
	}
	return (aux);
}
