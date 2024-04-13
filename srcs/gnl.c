/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:33:59 by romain            #+#    #+#             */
/*   Updated: 2024/04/12 16:03:21 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minignl_priv.h"

char	*concat_lines(char *buf, char *line)
{
	int		i;
	char	*new_line;

	i = 0;
	if (buf[i] == 0)
		return (line);
	new_line = malloc(2 * BUFFER_GNL);
	while (i < 2 * BUFFER_GNL)
		new_line[i++] = 0;
	i = 0;
	while (buf[i])
	{
		new_line[i] = buf[i];
		buf[i++] = 0;
	}
	free(line);
	return (new_line);
}

int	check_read_return_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (LINE_END_IN_LINE);
		i++;
	}
	if (line[i] == '\n')
		return (LINE_END);
	return (NO_END);
}

char	*write_line(const int fd, char *buf, char *line)
{
	int	r;
	int	p;

	p = 0;
	if (check_read_return_line(buf) == LINE_END_IN_LINE)
	{
		cut_buf(line, buf);
		return (line);
	}
	line = concat_lines(buf, line);
	if (line[0] == 0)
		p = 1;
	while (1)
	{
		if (read(fd, &line[gnl_strlen(line) - 1], BUFFER_GNL - 1) == 0)
		{
			if (p)
				break ;
			return (line);
		}
		r = check_read_return_line(line);
		if (r == LINE_END)
			return (line);
		if (r == EOF_INSIDE_LINE || r == LINE_END_IN_LINE)
		{
			cut_to_buf(line, buf);
			return (line);
		}
		else
			line = realloc_line(line);
	}
	free(line);
	return (NULL);
}

char	*get_next_line(const int fd)
{
	static char	buf[BUFFER_GNL];
	char		*line;
	int			i;

	line = malloc(BUFFER_GNL);
	i = 0;
	while (i < BUFFER_GNL)
	{
		line[i] = 0;
		i++;
	}
	return (write_line(fd, buf, line));
}
