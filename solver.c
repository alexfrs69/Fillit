/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 00:23:22 by afrancoi          #+#    #+#             */
/*   Updated: 2019/03/04 09:56:56 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_place_tetri(t_map *map, t_tetri *tetri, int mxy[2], char c)
{
	int x;
	int y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if (tetri->piece[x][y] != '.')
				map->tab[mxy[0] + x][mxy[1] + y] = c;
		}
	}
}

int		ft_check(t_map *map, t_tetri *tetri, int mxy[2])
{
	int x;
	int y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if (tetri->piece[x][y] != '.'
			&& map->tab[mxy[0] + x][mxy[1] + y] != '.')
				return (0);
		}
	}
	ft_place_tetri(map, tetri, mxy, tetri->letter);
	return (1);
}

int		ft_solve(t_map *map, t_tetri *tetri, int nb, int mynb)
{
	int xy[2];

	if (mynb == nb)
		return (1);
	xy[0] = -1;
	while (++xy[0] < map->size - tetri[mynb].height + 1)
	{
		xy[1] = -1;
		while (++xy[1] < map->size - tetri[mynb].width + 1)
		{
			if (ft_check(map, &tetri[mynb], xy))
			{
				if (ft_solve(map, tetri, nb, mynb + 1))
					return (1);
				else
					ft_place_tetri(map, &tetri[mynb], xy, '.');
			}
		}
	}
	return (0);
}

int		ft_start(t_tetri *tetri, int nb)
{
	t_map	*map;
	int		size;

	size = ft_sqrt(nb * 4, 0);
	if (!(map = ft_new_map(size)))
		return (0);
	while (!ft_solve(map, tetri, nb, 0))
	{
		size++;
		ft_free_map(map);
		if (!(map = ft_new_map(size)))
			return (0);
	}
	ft_print_map(map);
	ft_free_map(map);
	return (1);
}
