/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:55:22 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/04/18 15:30:50 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include<unistd.h>
# include "./libft/libft.h"
# include<fcntl.h>
# include<stdlib.h>
# include<stdio.h>
# include <sys/types.h>
# include <sys/uio.h>

typedef struct picuchillo
{
	int data1;
	struct picuchillo *next;
} stack;

void	swap_a(stack *lista);
void	swap_b(stack *lista);
void	swap_ab(stack *lista_a, stack *lista_b);
void	push_b(stack **lst_a, stack **lst_b);
void	push_a(stack **lst_b, stack **lst_a);
void	swap_ra(stack **lista);
void	swap_rb(stack **lista);
void	swap_rr(stack **lista_a, stack **lista_b);
void	swap_rra(stack **lista);
void	ft_error_exit(void);
void	ft_free(t_list *lst);
int		ft_listsize(stack *lst);
stack	*ft_listlast(stack *lst);
stack	*ft_listindex(stack *lst, int index);

#endif
