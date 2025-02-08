/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:41:01 by amarti            #+#    #+#             */
/*   Updated: 2025/02/08 11:03:57 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

#ifndef	BUFFER_SIZE 42
#define BUFFER_SIZE 42
#endif

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*fill_line_buffer(char *left_c, int fd);
char	*extract_line(char *left_c);
char	*new_left_c(char *left_c);
strdup;
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(const char *s1, const char *s2);
substr ;
size_t	ft_strlen(const char *s);

#endif