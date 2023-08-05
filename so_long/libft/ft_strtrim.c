/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 14:56:04 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/02/01 20:24:10 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static int	ft_start(const char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (i);
		i++;
	}
	return (-1);
}
static int	ft_end(const char *s)
{
	int i;

	i = ft_strlen(s) - 1;
	while (i > 0)
	{
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n')
			return (i);
		i--;
	}
	return (-1);
}*/

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (end > start && ft_strchr(set, s1[start]))
		start++;
	if (end <= start)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	while (ft_strchr(set, s1[end]) && end >= 0)
		end--;
	str = malloc(sizeof(char) * (end - start + 2));
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 2);
	return (str);
}
/*
int main()
{
	char *result = ft_strtrim("", "");
	printf("%s", result);
	return (0);
}*/
