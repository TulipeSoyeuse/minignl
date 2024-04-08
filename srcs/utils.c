/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 14:36:28 by romain            #+#    #+#             */
/*   Updated: 2024/04/08 16:49:00 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minignl_priv.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i++])
		;
	return (i);
}

void	cpy(char *target, char *origin)
{
	int	i;

	i = 0;
	while (origin[i])
	{
		target[i] = origin[i];
		i++;
	}
	target[i] = 0;
}

void	reset_buf(char *buf)
{
	int	i;

	i = 0;
	while (i < BUFFER_GNL)
		buf[i++] = 0;
}

char	*realloc_line(char *line)
{
	char	*nl;
	int		l;
	int		i;

	l = ft_strlen(line);
	nl = malloc(l + BUFFER_GNL);
	i = 0;
	while (i < l + BUFFER_GNL)
		nl[i++] = 0;
	cpy(nl, line);
	free(line);
	return (nl);
}
