/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 06:49:40 by afrancoi          #+#    #+#             */
/*   Updated: 2019/01/11 02:05:56 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <unistd.h>
#include <stdio.h>

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
	char	*ptr;
	int		nb;
	int		count;

	ptr = sample;
	nb = 0;
	count = 1;
	while (*ptr)
	{
		if (nb > 0 && nb % 4 == 0)
		{
			if (*ptr != '\n')
				error_exit();
			nb = 0;
			count--;
		}
		else if (count > 1 && count % 5 == 0)
		{
			if (*ptr != '\n')
				error_exit();
			nb++;
		}
		else if (*ptr != '#' && *ptr != '.')
			error_exit();
		count++;
		ptr++;
	}
}
