/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:09:43 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/24 15:24:27 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t num)
{
	while (*s1 == *s2 && num > 0)
	{
		if (!*s1 && !*s2)
			return (0);
		num--;
		s1++;
		s2++;
	}
	if (num == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
/*
int main()
{
	//char s1[] = "Hola";
	//char s2[] = "";
	//unsigned int n = 3;

	int result = ft_strncmp("test\200", "test\0", 6);
	printf("%d", result);
}*/