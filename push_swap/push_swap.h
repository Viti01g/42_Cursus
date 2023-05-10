/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:55:22 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/09 17:22:08 by vruiz-go         ###   ########.fr       */
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
	int	value;
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
void	ft_check_args(int argc, char **argv);
void	check_algor(stack *lista_a, stack *lista_b);
void	radix_sort(stack **stack_a, stack **stack_b);
int		is_sorted(stack **stacks);
void	ft_liberar(char **str);
void	alg_tres(stack **stack_a);
void	alg_four(stack **stack_a, stack **stack_b);
void	alg_five(stack **stack_a, stack **stack_b);
void	algs_cortos(stack **stack_a, stack **stack_b);
int		get_distance(stack **stacks, int index);
void	alg_ten(stack *lista_a, stack *lista_b);
void	alg_cien(stack *lista_a, stack *lista_b);
void	alg_quinientos(stack *lista_a, stack *lista_b);
void	check_alg(int argc, stack *lista_a, stack *lista_b);
int		get_min(stack *lista);
int		get_max(stack *lista);
int		check_middle(stack *lista);
void	pinturillo(stack **lista_b, stack **lista_a);
int 	dobles(stack *lista_a);
void	ft_error_exit(void);
void	ft_free(stack *lst);
int		ft_listsize(stack *lst);
stack	*ft_listlast(stack *lst);
stack	*ft_listindex(stack *lst, int index);
void	read_list(stack *lst);

#endif
