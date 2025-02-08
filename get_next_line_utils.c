/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:41:07 by amarti            #+#    #+#             */
/*   Updated: 2025/02/08 11:03:09 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	while(str[i])
	{
		if(str[i] == (char) c)
			return(&str[i]);
		i++;
	}
	if(str[i] == '\0')
		return(&str[i]);
	return(NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	iv2;
	char	*s3;

	i = 0;
	iv2 = 0;
	s3 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	while(s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while(s2[iv2])
	{
		s3[i] = s2[iv2];
		i++;
		iv2++;
	}
	s3[i] = '\0';
	return(s3);
}