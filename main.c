/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:54:00 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/22 02:21:55 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"


/*
** TODO REMOVE
*/

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

static char	*check_input(int argc, char **argv)
{
	int		fd;
	char	*sample;

	if ((fd = check_errors(argc, argv)) < 0)
		return (0);
	if (!(sample = read_sample(fd)))
		return (0);
	return (sample);
}

static int	parse_input(char *sample, t_tetri *tetri)
{
	int nb;

	if (!(nb = check_sample(sample)))
		return (error_exit(sample));
	if (!check_link(sample, 1, nb))
		return (error_exit(sample));
	save_tetri(sample, tetri, nb);
	replace_tetri(tetri, nb);
	return (1);
}

static char	**init_map(int nb)
{
	int		size;
	char	**map;

	size = (int)ft_sqrt(nb * 4, 0);
	if (!(map = new_map(size)))
		return (0);
	return (map);
}

int			main(int argc, char **argv)
{
	t_tetri tetri[26];
	char	*sample;
	int		nb;
	char	**map;

	if (!(sample = check_input(argc, argv)))
		return (error_exit(0));
	if (!(nb = parse_input(sample, tetri)))
		return (1);
	if (!(map = init_map(nb)))
		return (1);
	free_map(map, (int)ft_sqrt(nb * 4, 0));
	ft_putendl("OK!");
	ft_strdel(&sample);
	return (0);
}

