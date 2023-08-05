/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:26:34 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/31 15:19:32 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strcount(char const *s, char c)
{
	int	x;
	int	cont;

	x = 0;
	cont = 0;
	while (s && s[x])
	{
		if (s[x] != c)
		{
			cont++;
			while (s[x] != c && s[x])
				x++;
		}
		else
			x++;
	}
	return (cont);
}

static int	ft_wordsize(char const *s, char c, int x)
{
	int	i;

	i = 0;
	while (s[x] != c && s[x])
	{
		i++;
		x++;
	}
	return (i);
}

static void	ft_free(char **r, int a)
{
	while (a-- > 0)
		free (r[a]);
	free (r);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		x;
	int		i;
	int		k;

	x = 0;
	i = -1;
	str = malloc(sizeof(char *) * (ft_strcount(s, c) + 1));
	if (!str)
		return (NULL);
	while (++i < ft_strcount(s, c))
	{
		while (s[x] == c)
			x++;
		k = ft_wordsize(s, c, x);
		str[i] = ft_substr(s, x, k);
		if (!str[i])
		{
			ft_free(str, i);
			return (NULL);
		}
		x += k;
	}
	str[i] = 0;
	return (str);
}
