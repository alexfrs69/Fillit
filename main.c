/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:54:00 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/04 18:49:16 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

void	ft_display_multitab(char tab[4][4])
{
	int x;
	int y;

	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
			ft_putchar(tab[x][y]);
		ft_putendl("");
	}
	ft_putendl("");
}

int		main(int argc, char **argv)
{
	t_tetri tetri[26];
	int		fd;
	char	*sample;
	int		nb;
	int		size;
	char	**map;

	if ((fd = check_errors(argc, argv)) < 0)
		return (error_exit(0));
	if (!(sample = read_sample(fd)))
		return (error_exit(sample));
	if (!(nb = check_sample(sample)))
		return (error_exit(sample));
	if (!check_link(sample, 1, nb))
		return (error_exit(sample));
	save_tetri(sample, tetri, nb);
	ft_display_multitab(tetri[0].piece);
	replace_tetri(tetri, nb);
	ft_display_multitab(tetri[0].piece);
	size = (int)ft_sqrt(nb * 4, 0);
	map = new_map(size);
	free_map(map, size);
	ft_putendl("OK!");
	ft_strdel(&sample);
	return (0);
}

