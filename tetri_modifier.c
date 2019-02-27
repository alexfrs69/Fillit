/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_modifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:53:36 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/24 20:13:50 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

static void		ft_swap_tab_h(char tab[4][4])
{
	char	tmp[4][4];
	int		x;

	x = -1;
	while (++x < 4)
		ft_memcpy(tmp[x], tab[x], 4);
	x = -1;
	while (++x < 4)
		ft_memcpy(tab[x], tmp[(x + 1) % 4], 4);
}

static void		ft_swap_tab_v(char tab[4][4])
{
	char	tmp[4][4];
	int		x;
	int		y;

	x = -1;
	while (++x < 4)
		ft_memcpy(tmp[x], tab[x], 4);
	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			tab[x][y] = tmp[x][(y + 1) % 4];
	}
}

static int	ft_check_v(char tab[4][4])
{
	int x;
	int res;

	x = -1;
	res = 0;
	while (++x < 4)
		if (tab[x][0] == '.')
			res++;
	if (res == 4)
		return (1);
	return (0);
}

void		ft_replace_tetri(t_tetri *tetri, int nb)
{
	int n;

	n = -1;
	while (++n < nb)
	{
		while (ft_strncmp(tetri[n].piece[0], "....", 4) == 0)
			ft_swap_tab_h(tetri[n].piece);
		while (ft_check_v(tetri[n].piece))
			ft_swap_tab_v(tetri[n].piece);
	}
}
