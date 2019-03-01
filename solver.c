/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:23:22 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/28 06:18:34 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int		ft_next_char(char tab[4][4], int xy[2])
{
	while (xy[0]++ < 4)
	{
		xy[1] = -1;
		while (++xy[1] < 4)
		{
			if (tab[xy[0]][xy[1]] != '.')
				return ();
		}
	}
	return (0);
}

int		ft_check(t_map **map, char tab[4][4], int pos[2])
{
	int xy[2];

	printf("FT_CHECK\n");
	xy[0] = 0;
	xy[1] = 0;
	ft_next_char(tab, xy);
	printf("INIT : x = %d, y = %d\n", xy[0], xy[1]);
	while (pos[0]++ < (*map)->size)
	{
		while (pos[1]++ < (*map)->size)
		{
			if ((*map)->tab[pos[0]][pos[1]] == '.')
			{
				(*map)->tab[pos[0]][pos[1]] = tab[xy[0]][xy[1]];
				ft_putchar((*map)->tab[pos[0]][pos[1]]);
				ft_putendl("");
			}
			printf("BEFORE : x = %d, y = %d\n", xy[0], xy[1]);
			if (!ft_next_char(tab, xy))
				return (1);
			printf("AFTER : x = %d, y = %d\n", xy[0], xy[1]);
		}
	}
	return (0);
}

void	ft_remove_tetri(t_map **map, int c)
{
	char	*del;
	int		x;

	del = NULL;
	x = -1;
	while (++x < (*map)->size)
	{
		while ((del = ft_memchr((*map)->tab[x], c, (*map)->size - 1)))
			*del = '?';
	}
}

int		ft_solve(t_map **map, t_tetri *tetri, int nb, int mynb)
{
	int pos[2];

	pos[0] = -1;
	if (mynb >= nb)
		return (0);
	while (++pos[0] < (*map)->size)
	{
		pos[1] = -1;
		while (++pos[1] < (*map)->size)
		{
			if (ft_check(&*map, tetri[mynb].piece, pos))
				if (ft_solve(&*map, tetri, nb, mynb + 1) > 0)
					return (1);
			ft_remove_tetri(&*map, mynb + 'A');
		}
	}
	return (-1);
}

