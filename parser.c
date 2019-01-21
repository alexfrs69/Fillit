/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 06:49:40 by afrancoi          #+#    #+#             */
/*   Updated: 2019/01/21 23:00:20 by afrancoi         ###   ########.fr       */
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
	char	buffer[545 + 1];
	char	*sample;
	int		rd;

	sample = NULL;
	rd = read(fd, buffer, 545 + 1);
	if (rd <= 0 || rd > 545)
		error_exit();
	buffer[rd] = '\0';
	sample = ft_strdup(buffer);
	if (!sample)
		error_exit();
	return (sample);
}

/*
**	Checks if characters are only # OR . OR \n.
**	nb is the count of line.
**	count is the count of characters.
**	tetri is the count of total tetriminos.
**	Return | (int) Count of tetriminos.
*/

int		check_sample(char *sample)
{
	int		count;
	int		tetri;

	count = 1;
	tetri = 1;
	while (*sample)
	{
		if (count > 1 && count % 5 == 0)
			*sample != '\n' ? error_exit() : NULL;
		else if (count > 20 && count % 21 == 0)
		{
			*sample != '\n' ? error_exit() : NULL;
			count = 1;
			tetri++;
			sample++;
			continue;
		}
		else if (*sample != '#' && *sample != '.')
			error_exit();
		count++;
		sample++;
	}
	if (count != 21)
		error_exit();
	return (tetri);
}

/*
**	Checks links of a individual tetrimino.
**	If the count of links isn't 6 or 8 it will throw an Error.
**	The next tetrimino is called recursivly.
**	We add 21 to sample to get the next.
*/

void	check_link(char *sample, int mynb, int nb)
{
	int	count;
	int	i;
	int width;
	int height;

	width = 0;
	height = 0;
	i = 0;
	count = 0;
	while (sample[i] && i < 19)
	{
		if (sample[i] == '#')
		{
			if (i > 0 && sample[i - 1] == '#')
			{
				count++;
				width++;
			}
			if (i < 18 && sample[i + 1] == '#')
			{
				count++;
				width++;
			}
			if (i < 14 && sample[i + 5] == '#')
			{
				count++;
				height++;
			}
			if (i > 4 && sample[i - 5] == '#')
			{
				height++;
				count++;
			}
		}
		i++;
	}
	if (count != 6 && count != 8)
		error_exit();
	printf("height : %d | width : %d\n", height / 2 + 1, width / 2 + 1);
	if (mynb != nb)
		check_link(sample + 21, mynb + 1, nb);
}
