/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:55:22 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/03/29 12:17:22 by vruiz-go         ###   ########.fr       */
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

typedef struct odor
{
    int data1;
    struct odor *next;
    struct odor *anterior;
} stack_a;

typedef struct picuchillo
{
    int data2;
    struct picuchillo *next;
    struct picuchillo *anterior;
} stack_b;




#endif
