/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:54:00 by afrancoi          #+#    #+#             */
/*   Updated: 2019/01/30 12:18:41 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*sample;
	t_tetri tetri[26];
	int		nb;

	if ((fd = check_errors(argc, argv)) < 0)
		return (error_exit(0));
	if (!(sample = read_sample(fd)))
		return (error_exit(sample));
	if (!(nb = check_sample(sample)))
		return (error_exit(sample));
	if (!check_link(sample, 1, nb))
		return (error_exit(sample));
	save_tetri(sample, (t_tetri*)&tetri, nb);
	ft_putendl("OK!");
	ft_strdel(&sample);
	return (0);
}
