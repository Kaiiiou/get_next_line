/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:41:04 by amarti            #+#    #+#             */
/*   Updated: 2025/02/05 10:43:06 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*char_line_buffer(char *left_c, int fd)
{
	char *buffer;
	char *svgrdmem;
	ssize_t read2;

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
			free(buffer);
			free(left_c);
			return(NULL);
		buffer[read2] = '\0';
		svgrdmem = left_c;
		left_c = ft_strjoin(left_c, buffer);
		free(svgrdmem);
		if(left_c)
			free(buffer);
			return(NULL);
	}
	free
}

char	*get_next_line (int fd)
{
	static char	*left_c;
	int			*line;
	int			*svgrdmem;

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
		left_c = (NULL);
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


