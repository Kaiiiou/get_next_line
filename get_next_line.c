/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:41:04 by amarti            #+#    #+#             */
/*   Updated: 2025/02/04 12:00:21 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char *fill_line_buffer(int fd, char *svgrd_c)
// {
// 	ssize_t read;
// 	char *temp;
// 	char *buf;

// 	read = 1;
// 	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
// 	if(!buf)
// 		return(NULL);
// }

// char *get_next_line(int fd)
// {
// 	static int *left_c;
// 	char *temp;
// 	char *line;

// 	if(fd < 0 || BUFFER_SIZE <= 0)
// 		return(NULL);
	
// 	left_c = fill_line_buffer(fd, left_c);
// 	if(!left_c)
// 		return(NULL);

// }

char *get_next_line(int fd)
{
	CHECK MEM + FD

	CALL *fill_line_buffer TO READ --> '\0' || '\n'

	FILL BUFFER_SIZE PER BUFFER_SIZE set_line 

	WHEN set_line IS FULL, line PICK STR WITH THE \n AND LET "surplus" IN set_line COZ static fonction


	LINE PUT \0 AFTER STR AND RETURN IT
}

char *_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	
}



