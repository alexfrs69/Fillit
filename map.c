/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:34:15 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/24 20:45:43 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

char	**ft_new_map(int size)
{
	char	**map;
	int		nb;

	nb = size;
	if (!(map = (char**)ft_memalloc(sizeof(char*) * size)))
		return (0);
	while (nb--)
	{
		if (!(map[nb] = (char*)ft_memalloc(sizeof(char) * size)))
			return (0);
		ft_memset(map[nb], '.', size);
	}
	return (map);
}

void	ft_free_map(char **map, int size)
{
	while (size--)
		free(map[size]);
	free(map);
}
