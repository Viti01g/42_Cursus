/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:26:24 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/20 18:29:05 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	x;
	size_t	i;

	i = ft_strlen(s1);
	str = malloc(sizeof(char) * i + 1);
	if (!str)
		return (NULL);
	x = 0;
	while (x < i)
	{
		str[x] = s1[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}
/*
int main ()
{
	char *s = "lorem ipsum dolor sit amet";
	char 	*p;

	p = ft_strdup(s);
	
	printf("%s", p);
	return (0);
}*/