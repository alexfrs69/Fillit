/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:34:15 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/27 22:25:06 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

t_map	*ft_start(t_tetri *tetri, int nb, int size)
{
	t_map	*map;

	if (!(map = ft_new_map(size)))
		return (0);
	while(!ft_solve(map, tetri, nb, 0))
	{
		size++;
		ft_free_map(map);
		if (!(map = ft_new_map(size)))
			return (0);
	}
	return (map);
}
