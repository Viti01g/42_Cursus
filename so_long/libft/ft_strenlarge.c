/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strenlarge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vruiz-go <vruiz-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 16:32:11 by vruiz-go          #+#    #+#             */
/*   Updated: 2023/07/11 16:32:38 by vruiz-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strenlarge(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*s3;
	int		i;

	if (s2 == NULL)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	s3 = (char *)malloc(len_s1 + len_s2 + 1);
	if (s3 == NULL)
		return (NULL);
	while (i < len_s1 || i < len_s2)
	{
		if (i < len_s1)
			s3[i] = s1[i];
		if (i < len_s2)
			s3[i + len_s1] = s2[i];
		i++;
	}
	s3[len_s1 + len_s2] = '\0';
	free(s1);
	free(s2);
	return (s3);
}
