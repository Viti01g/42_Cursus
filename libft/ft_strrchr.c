/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:04:42 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/01/18 14:16:40 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include<stdio.h>

char	*ft_strrchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
/*
int main()
{
	char sttr[30] = "Mosquiquito";
	printf("%s", ft_strrchr(sttr, 113));
	return(0);
}*/
//#include "libft.h"
/**
 * Locates last occurrence of c in string s.
 * @param s searched string
 * @param c character to search
 * @return Pointer to byte located, or NULL if there is no occurrence
 */
/*char    *ft_strrchr(const char *s, int c)
{
    int     i;
    i = ft_strlen(s);
    while (i >= 0)
    {
        if (s[i] == (char) c)
            return ((char *)s + i);
        i--;
    }
    return (NULL);
}*/