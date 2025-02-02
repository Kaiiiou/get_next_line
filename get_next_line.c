/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarti <amarti@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 00:41:04 by amarti            #+#    #+#             */
/*   Updated: 2025/02/02 10:49:14 by amarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *remplissage_svgrd(int fd, char *svgrd, char *buffer)
{
	
}

char *get_next_line(int fd)
{
	static int svgrd;
	int temp;

	if(fd <= 0 || BUFFER_SIZE <= 0)
		return(NULL);
	
	svgrd = ;
}