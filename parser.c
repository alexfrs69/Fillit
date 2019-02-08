/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 06:49:40 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/04 18:31:17 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*
**	Read into fd make checks about the size.
**	Dupe into sample and return it.
**	Return | char* sample
*/

char		*read_sample(int fd)
{
	char	buffer[546];
	int		rd;

	rd = read(fd, buffer, 546);
	if (rd < 20 || rd > 545)
		return (0);
	buffer[rd] = '\0';
	return (ft_strdup(buffer));
}

static	int	check_one(char *sample)
{
	unsigned int i;

	i = 0;
	while (sample[i] && i < 21)
	{
		if (sample[i] != '#' && sample[i] != '.' && sample[i] != '\n')
			return (0);
		if (sample[i] == '\n' && i % 5 != 4 && i < 20)
			return (0);
		if (sample[i] != '\n' && i % 5 == 4)
			return (0);
		if (sample[i] != '\n' && i == 20)
			return (0);
		++i;
	}
	return (1);
}

/*
**	Checks if characters are only # OR . OR \n.
**	nb is the count of line.
**	count is the count of characters.
**	tetri is the count of total tetriminos.
**	Return | (int) Count of tetriminos.
*/

int			check_sample(char *sample)
{
	unsigned int nb;

	nb = 0;
	while (*sample)
	{
		if (!check_one(sample))
			return (0);
		nb++;
		if (ft_strlen(sample) >= 21)
			sample += 21;
		else
			sample += ft_strlen(sample);
	}
	if (sample[-1] == '\n' && sample[-2] == '\n')
		return (0);
	return (nb);
}

/*
**	Checks links of a individual tetrimino.
**	If the count of links isn't 6 or 8 it will throw an Error.
**	The next tetrimino is called recursivly.
**	We add 21 to sample to get the next.
*/

int			check_link(char *sample, int mynb, int nb)
{
	int	count;
	int	i;
	int width;
	int height;
	int htag;

	width = 0;
	height = 0;
	i = -1;
	count = 0;
	htag = 0;
	while (sample[++i] && i < 19)
	{
		if (sample[i] != '#')
			continue ;
		++htag;
		width += (i > 0 && sample[i - 1] == '#' && ++count)
				+ (i < 18 && sample[i + 1] == '#' && ++count);
		height += (i < 14 && sample[i + 5] == '#' && ++count)
				+ (i > 4 && sample[i - 5] == '#' && ++count);
	}
	if ((count != 6 && count != 8) || htag != 4)
		return (0);
	return (mynb != nb ? check_link(sample + 21, mynb + 1, nb) : 1);
}

void		save_tetri(char *sample, t_tetri *tab, int nb)
{
	int i;
	int x;

	i = -1;
	while (++i < nb)
	{
		x = -1;
		while (++x < 20)
			if (x / 5 != 4 && x % 5 != 4)
				tab[i].piece[x / 5][x % 5] = sample[x] == '#' ? 'A' + i : '.';
		sample += 21;
	}
}
