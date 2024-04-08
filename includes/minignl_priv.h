/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minignl_priv.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romain <romain@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:29:35 by romain            #+#    #+#             */
/*   Updated: 2024/04/08 16:56:34 by romain           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIGNL_PRIV_H

# define MINIGNL_PRIV_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFER_GNL 50

# define LINE_END 42
# define LINE_END_IN_LINE 43
# define EOF_INSIDE_LINE 44
# define NO_END 45

void	cut_buf(char *line, char *buf);
void	cut_to_buf(char *line, char *buf);
void	cpy(char *target, char *origin);
void	reset_buf(char *buf);
char	*realloc_line(char *line);
int		ft_strlen(char *s);
int		check_read_return_line(char *line);
#endif
