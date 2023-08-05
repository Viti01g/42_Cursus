/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:51:01 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/17 14:28:08 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int i)
{
	if ((i >= '0' && i <= '9'))
		return (1);
	else
		return (0);
}
/*
int main()
{
    int result = ft_isdigit(50);
    printf("%d", result);
    return(0);
}*/
