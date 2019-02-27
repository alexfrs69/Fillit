/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:54:00 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/24 20:49:11 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"


/*
** TODO REMOVE
*/

void		ft_display_multitab(char **tab, int size)
{
	int x;
	int y;

	x = -1;
	while (++x < size)
	{
		y = -1;
		while (++y < size)
			ft_putchar(tab[x][y]);
		ft_putendl("");
	}
	ft_putendl("");
}

static char	*ft_check_input(int argc, char **argv)
{
	int		fd;
	char	*sample;

	if ((fd = ft_check_errors(argc, argv)) < 0)
		return (0);
	if (!(sample = ft_read_sample(fd)))
		return (0);
	return (sample);
}

static int	ft_parse_input(char *sample, t_tetri *tetri)
{
	int nb;

	if (!(nb = ft_check_sample(sample)))
		return (ft_error_exit(sample));
	if (!ft_check_link(sample, 1, nb))
		return (ft_error_exit(sample));
	ft_save_tetri(sample, tetri, nb);
	ft_replace_tetri(tetri, nb);
	return (nb);
}

int			main(int argc, char **argv)
{
	t_tetri tetri[26];
	char	*sample;
	int		nb;
	int		size;
	char	**map;

	if (!(sample = ft_check_input(argc, argv)))
		return (ft_error_exit(0));
	if (!(nb = ft_parse_input(sample, tetri)))
		return (1);
	size = (int)ft_sqrt(nb * 4, 0);
	if (!(map = ft_new_map(size)))
		return (1);
	ft_display_multitab(map, size);
	ft_free_map(map, size);
	ft_putendl("OK!");
	ft_strdel(&sample);
	return (0);
}
