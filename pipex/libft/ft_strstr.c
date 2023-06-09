/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 15:34:27 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/05/31 15:58:55 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *haystack, char *needle)
{
	int	i;
	int	j;

	if (needle[0] == '\0')
		return (haystack);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j])
			{
				j++;
				if (!needle[j])
					return (&haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
