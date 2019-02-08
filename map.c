/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:34:15 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/04 18:50:05 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>
#include <stdio.h>

char	**new_map(int size)
{
	char **map;

	if (!(map = (char**)ft_memalloc(sizeof(char*) * size)))
		return (0);
	while (size--)
		if (!(map[size] = (char*)ft_memalloc(sizeof(char) * size)))
			return (0);
	return (map);
}

void	free_map(char **map, int size)
{
	while (size--)
		free(map[size]);
	free(map);
}

void	swap_tab(char tab[4][4], int src, int dst)
{
	char tmp[4];

	ft_memcpy(tmp, tab[dst], 4);
	ft_memcpy(tab[dst], tab[src], 4);
	ft_memcpy(tab[src], tab[dst], 4);
}

void	replace_tetri(t_tetri *tetri, int nb)
{
	int x;
	int y;
	int i;
	int n;

	n = -1;
	while (++n < nb)
	{
		x = -1;
		while (++x < 4)
		{
			y = -1;
			i = 0;
			while (++y < 4)
				if (tetri[n].piece[x][y] == '.')
					++i;
			if (i == 4)
			{
				printf("Swapped %d to 4\n", x);
				swap_tab(tetri[n].piece, x, 4);
			}
		}
	}
}
