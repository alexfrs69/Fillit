/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 06:49:40 by afrancoi          #+#    #+#             */
/*   Updated: 2019/01/09 00:29:07 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>
#include <unistd.h>

/*
**	Read into fd make checks about the size.
**	Dupe into sample and return it.
**	Return | char* sample
*/

char	*read_sample(int fd)
{
	char	buffer[MAX_TETRI + 1];
	char	*sample;
	int		rd;

	sample = NULL;
	rd = read(fd, buffer, MAX_TETRI + 1);
	if (rd <= 0 || rd > 545)
		error_exit();
	buffer[rd] = '\0';
	sample = ft_strdup(buffer);
	return (sample);
}

/*
**	TODO
**	WIP
*/

void	check_sample(char *sample)
{
	printf("%s", sample);
}
