/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:33:50 by romain            #+#    #+#             */
/*   Updated: 2024/04/12 15:30:02 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minignl_priv.h"

void	cut_buf(char *line, char *buf)
{
	int	i;
	int	j;

	i = 0;
	while (buf[i] != '\n' && buf[i])
	{
		*line = buf[i];
		line++;
		i++;
	}
	i++;
	j = 0;
	while (buf[i])
		buf[j++] = buf[i++];
	while (j < BUFFER_GNL)
		buf[j++] = 0;
}

void	cut_to_buf(char *line, char *buf)
{
	while (*line != '\n')
		line++;
	*line = 0;
	line++;
	while (*line)
	{
		*buf = *line;
		buf++;
		line++;
	}
	buf = 0;
}
