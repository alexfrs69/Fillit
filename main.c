/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:54:00 by afrancoi          #+#    #+#             */
/*   Updated: 2019/03/04 10:01:09 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
	if (!check_link(sample, tetri, 1, nb))
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

	if (!(sample = ft_check_input(argc, argv)))
		return (ft_error_exit(0));
	if (!(nb = ft_parse_input(sample, tetri)))
		return (1);
	if (!ft_start(tetri, nb))
		return (ft_error_exit(sample));
	ft_strdel(&sample);
	return (0);
}
