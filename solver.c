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

void	ft_place_tetri(t_map *map, t_tetri *tetri, int mx, int my, char c)
{
	int x;
	int y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			if (tetri->piece[x][y] != '.')
				map->tab[mx + x][my + y] = c;
	}
}

int		ft_check(t_map *map, t_tetri *tetri, int mx, int my)
{
	int x;
	int y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if(tetri->piece[x][y] != '.' && map->tab[mx + x][y + my] != '.')
				return (0);
		}
	}
	ft_place_tetri(map, tetri, mx, my, tetri->letter);
	return (1);
}

int		ft_solve(t_map *map, t_tetri *tetri, int nb, int mynb)
{
	int x;
	int y;

	if (mynb == nb)
		return (1);
	x = -1;
	while (++x < map->size - 4)
	{
		y = -1;
		while (++y < map->size - 4)
		{
			if (ft_check(map, &tetri[mynb], x, y))
			{
				if (ft_solve(map, tetri, nb, mynb + 1))
					return (1);
				else 
					ft_place_tetri(map, &tetri[mynb], x, y, '.');
			}
		}
	}
	return (0);
}

