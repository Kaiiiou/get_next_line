/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:41:04 by amarti            #+#    #+#             */
/*   Updated: 2025/02/10 16:46:33 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line_buffer(char *left_c, int fd)
{
	char *buffer;
	char *svgrdmem;
	ssize_t read2; 
	read2 = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
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
		{
			free(buffer);
			return(NULL);
		}
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
	while (left_c[i] && left_c[i] != '\n')
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

	iv2 = 0;
	i = 0;
	while (left_c[i] && left_c[i] != '\n')
		i++;
	if (!left_c[i])
	{
		free(left_c);
		return (NULL);
	}
	i++;
	new_left = (char *)malloc(sizeof(char) * (ft_strlen(left_c) - i + 1));
	if (!new_left)
		return (NULL);
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
		left_c = NULL;
		return(NULL);
	}
	left_c = fill_line_buffer(left_c, fd);
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

int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("Erreur d'ouverture");
        return (1);
    }

    while ((line = get_next_line(fd)))
    {
        if (line)
        {
            printf("Ligne lue : %s", line);
            free(line);
        }
    }

    close(fd);
    return (0);
}