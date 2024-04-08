/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:33:50 by romain            #+#    #+#             */
/*   Updated: 2024/04/08 15:57:41 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minignl_priv.h"

void	cut_buf(char *line, char *buf)
{
	int	i;

	i = 0;
	while (buf[i] != '\n')
	{
		*line = buf[i];
		line++;
		i++;
	}
	i++;
	while (buf[i])
	{
		*buf = buf[i++];
		buf++;
	}
	*buf = 0;
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
