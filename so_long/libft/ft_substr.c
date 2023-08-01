/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:51:45 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/02/06 15:49:44 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			x;
	unsigned int	lens;

	lens = ft_strlen(s);
	if (lens < start)
		len = 0;
	else if (lens + start < len)
		len = ft_strlen(s + start);
	if (!s)
		return (0);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	x = 0;
	while (x < len && start < lens && s[start])
		str[x++] = *(char *)&s[start++];
	str[x] = '\0';
	return (str);
}
/*
int main()
{
	char *result = ft_substr("Mosquito", 's', 4);
	printf("%s", result);
	return (0);
}*/
