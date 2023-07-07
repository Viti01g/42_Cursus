/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:58:59 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/19 15:27:08 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return ((char *)&str[i]);
	return (NULL);
}
/*
int main()
{
	char sttr[30] = "Mosquito";
	char *res = ft_strchr(sttr, 113);
	printf("%c", ft_strchr(sttr, 113));
	//write(1, "\n", 1);
	//write(1, *res, 1);
	return(0);
}*/