/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:55:22 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/18 17:40:04 by vruiz-go         ###   ########.fr       */
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
	int					data1;
	int					value;
	struct picuchillo	*next;
}	t_stack;

void	swap_a(t_stack **lista);
void	swap_b(t_stack **lista);
void	swap_ab(t_stack **lista_a, t_stack **lista_b);
void	push_b(t_stack **lst_a, t_stack **lst_b);
void	push_a(t_stack **lst_b, t_stack **lst_a);
void	swap_ra(t_stack **lista);
void	swap_rb(t_stack **lista);
void	swap_rr(t_stack **lista_a, t_stack **lista_b);
void	swap_rra(t_stack **lista);
void	swap_rrb(t_stack **lista);
void	swap_rrr(t_stack **lista_a, t_stack **lista_b);
void	ft_check_args(int argc, char **argv);
void	check_algor(t_stack **lista_a, t_stack **mlista_b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	ft_liberar(char **str);
int		ft_atoi_ps(char *str);
int		ft_is_nbr_space_valid(char *str);
void	alg_tres(t_stack **stack_a);
void	alg_four(t_stack **stack_a, t_stack **stack_b);
void	alg_five(t_stack **stack_a, t_stack **stack_b);
void	algs_cortos(t_stack **stack_a, t_stack **stack_b);
int		get_distance(t_stack **stacks, int index);
void	check_alg(int argc, t_stack *lista_a, t_stack *lista_b);
int		get_min(t_stack *lista);
int		get_max(t_stack *lista);
int		check_middle(t_stack *lista);
int		dobles(t_stack *lista_a);
void	ft_error_exit(void);
void	ft_free(t_stack *lst);
void	free_stack(t_stack **stacks);
int		ft_listsize(t_stack *lst);
t_stack	*ft_listlast(t_stack *lst);
t_stack	*ft_listindex(t_stack *lst, int index);
void	read_list(t_stack *lst);

#endif
