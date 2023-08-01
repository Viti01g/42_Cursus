/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 15:16:41 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/02/07 13:08:14 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;

	if (!*lst || !del || !lst)
		return ;
	while (*lst)
	{
		aux = lst[0]->next;
		ft_lstdelone(*lst, del);
		*lst = aux;
	}
	*lst = NULL;
}
