/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:59:33 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/17 14:33:58 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int i)
{
	if (i > 31 && i < 127)
		return (1);
	else
		return (0);
}
/*
int main()
{
    int result = ft_isprint(127);
    printf("%d", result);
    return(0);
}*/
