/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 19:26:34 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/02/06 16:02:13 by vruiz-go         ###   ########.fr       */
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
/*
static size_t	ContStrings(char const *s, char delim)
{
	size_t	cont;
	size_t	i;

	i = 0;
	cont = 0;
	while (s[i])
	{
		while (s[i] == delim)
			i++;
		if (s[i] == delim)
		{
			cont++;
			i++;
		}
		i++;
	}
	return (cont);
}

static char *ReservaEspacio(char const *s, char delim)
{
	char	*stri;
	size_t	cont;
	size_t	i;
	size_t	j;

	stri = NULL;
	i = 0;
	cont = 0;
	while (s[i])
	{
		if (s[i] == delim)
			i++;
		else if (s[i] != delim)
		{
			while (s[i] != delim)
			{
				i++;
				j++;
			}
			stri[cont] = (char)malloc(sizeof(char) * j + 1);
			if (!stri[cont])
				return (NULL);
			cont++;
			j = 0;
		}
	}
	return (stri);
}

static char	*RellenarMatriz(char **strings, char const *str, char delim)
{
	char	*stri;
	size_t	i;

	i = 0;
	stri = *strings;
	while (str[i])
	{
		if (str[i] == delim)
			i++;
		else if (str[i] != delim)
		{
			while (str[i] != delim)
			{
				stri[i] = str[i];
				i++;
			}
		}
	}
	return (stri);
}

char	**ft_split(char const *s, char c)
{
	char	**matriz;
	size_t	cont;
	size_t	j;

	j = 0;
	cont = ContStrings(s, c);
	matriz = malloc(sizeof(char *) * (cont + 1));
	if (!matriz)
		return (NULL);
	while (matriz[j])
	{
		matriz[j] = ReservaEspacio(s, c);
		matriz[j] = RellenarMatriz(matriz, s, c);
		j++;
	}
	*matriz[j] = '\0';
	return(matriz);
}

int	main()
{
	int		i;
	char	*strin;
	char	**result;

	i = 0;
	strin = "Hola que haces";
	result = ft_split(strin, ' ');
	
	while (result[i])
	{
		printf("%s", result[i]);
		i++;
	}
	
	return (0);
}


static int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}*/
