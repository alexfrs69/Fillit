/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 06:49:40 by afrancoi          #+#    #+#             */
/*   Updated: 2018/12/12 07:25:45 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include "get_next_line.h"
#include <stdio.h>

static void		strjoin_free(char **s1, char **s2)
{
	char *tmp;

	tmp = *s1;
	if (!(*s1 = ft_strjoin(*s1, *s2)))
		error_exit();
	ft_strdel(&*s2);
	ft_strdel(&tmp);
	tmp = *s1;
	if (!(*s1 = ft_strjoin(*s1, "\n")))
		error_exit();
	ft_strdel(&tmp);
}

void			read_sample(int fd)
{
	char	*line;
	char	*sample;
	int		gnl;

	sample = ft_strnew(0);
	while ((gnl = get_next_line(fd, &line)) > 0)
	{
		strjoin_free(&sample, &line);
	}
	printf("%s", sample);
	ft_strdel(&sample);
}
