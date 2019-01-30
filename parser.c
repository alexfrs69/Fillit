/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 06:49:40 by afrancoi          #+#    #+#             */
/*   Updated: 2019/01/30 02:27:33 by afrancoi         ###   ########.fr       */
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
	char	buffer[546];
	int		rd;

	rd = read(fd, buffer, 546);
	if (rd < 20 || rd > 545)
		return (0);
	buffer[rd] = '\0';
	return (ft_strdup(buffer));
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
		{
			if (*sample != '\n')
				return (0);
		}
		else if (count > 20 && count % 21 == 0)
		{
			if (*sample != '\n')
				return (0);
			count = 1;
			tetri++;
			sample++;
			continue;
		}
		else if (*sample != '#' && *sample != '.')
			return (0);
		count++;
		sample++;
	}
	if (count != 21)
		return (0);
	return (tetri);
}

/*
**	Checks links of a individual tetrimino.
**	If the count of links isn't 6 or 8 it will throw an Error.
**	The next tetrimino is called recursivly.
**	We add 21 to sample to get the next.
*/

int	check_link(char *sample, int mynb, int nb)
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

void	save_tetri(char *sample, t_tetri *tab, int nb)
{
	int i;

	i = 0;
	while (i < nb)
	{
		ft_memcpy(tab[nb].piece, sample + 20, 20);
		ft_memcpy(&tab[nb].number, &i, sizeof(int));
		++i;
	}
}
