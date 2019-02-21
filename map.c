/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 12:34:15 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/21 22:53:45 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdlib.h>

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
