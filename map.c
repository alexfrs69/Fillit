/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:34:15 by afrancoi          #+#    #+#             */
/*   Updated: 2019/03/04 10:00:16 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_map	*ft_new_map(int size)
{
	t_map	*map;
	int		nb;

	nb = size;
	if (!(map = (t_map*)ft_memalloc(sizeof(t_map))))
		return (0);
	map->size = size;
	if (!(map->tab = (char**)ft_memalloc(sizeof(char*) * size)))
		return (0);
	while (nb--)
	{
		if (!(map->tab[nb] = (char*)ft_memalloc(sizeof(char) * size)))
			return (0);
		ft_memset(map->tab[nb], '.', size);
	}
	return (map);
}

void	ft_free_map(t_map *map)
{
	int size;

	size = map->size;
	while (size--)
	{
		free(map->tab[size]);
	}
	free(map->tab);
	free(map);
}

void	ft_print_map(t_map *map)
{
	int x;
	int y;

	x = -1;
	while (++x < map->size)
	{
		y = -1;
		while (++y < map->size)
			ft_putchar(map->tab[x][y]);
		ft_putendl("");
	}
	ft_putendl("");
}
