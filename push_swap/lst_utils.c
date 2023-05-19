/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:25:47 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/18 17:32:23 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_listsize(t_stack *lst)
{
	int		cont;
	t_stack	*aux;

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

t_stack	*ft_listlast(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	while (temp != NULL)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	return (temp);
}

t_stack	*ft_listindex(t_stack *lst, int index)
{
	t_stack	*aux;
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
