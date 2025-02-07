/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:41:04 by amarti            #+#    #+#             */
/*   Updated: 2025/02/07 13:15:47 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line_buffer(char *left_c, int fd)
{
	char *buffer;	// stock par iteration de buffersize
	char *svgrdmem;
	ssize_t read2; // nombre de caracteres lu par read sert de repere

	read2 = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return(NULL);
	if(!left_c)
		left_c = ft_strdup("");
	if(!left_c)
	{
		free(buffer);
		return(NULL);
	}
	while(read2 > 0 && !ft_strchr(left_c, '\n'))
	{
		read2 = read(fd, buffer, BUFFER_SIZE);
		if(read2 == -1)
		{
			free(buffer);
			free(left_c);
			return(NULL);
		}
		buffer[read2] = '\0';
		svgrdmem = left_c;
		left_c = ft_strjoin(left_c, buffer);
		free(svgrdmem);
		if(!left_c)
			free(buffer);
			return(NULL);
	}
	free (buffer);
	return (left_c);
}

char	*extract_line(char *left_c)
{
	char	*line;
	int		i;

	i = 0;
	if(!left_c[0])
		return(NULL);
	if(!left_c[i] && left_c[i] != '\n')
		i++;
	if(left_c[i] == '\n')
		i++;
	line = ft_substr(left_c, 0, i);
	return (line);
}

char	*new_left_c(char *left_c)
{
	char	*new_left;
	int		i;
	int		iv2;

	i = 0;
	while (left_c[i] && left_c[i] != '\n')
		i++;
	if (!left_c[i])
		return (NULL);
	i++;
	new_left = (char *)malloc(sizeof(char) * (ft_strlen(left_c) - i + 1));
	if (!new_left)
		return (NULL);
	iv2 = 0;
	while (left_c[i])
		new_left[iv2++] = left_c[i++];
	new_left[iv2] = '\0';
	return (new_left);
}

char	*get_next_line (int fd)
{
	static char	*left_c;
	char		*line;
	char		*svgrdmem;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(left_c);
		left_c = (NULL);
		return(NULL);
	}
	left_c = fill_line_buffer(fd, left_c);
	if(!left_c)
		return(NULL);
	line = extract_line(left_c);
	if(!line)
	{
		free(left_c);
		left_c = (NULL);new_left_c;
		return(NULL);
	}
	svgrdmem = left_c;
	left_c = new_left_c(left_c);
	free(svgrdmem);
	return(line);
}

// char *get_next_line(int fd)
// {
// 	CHECK MEM + FD

// 	CALL *fill_line_buffer TO READ --> '\0' || '\n'

// 	FILL BUFFER_SIZE PER BUFFER_SIZE set_line 

// 	WHEN set_line IS FULL, line PICK STR WITH THE \n AND LET "surplus" IN set_line COZ static fonction


// 	LINE PUT \0 AFTER STR AND RETURN IT
// }


