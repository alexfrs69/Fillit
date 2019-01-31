/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:32:12 by afrancoi          #+#    #+#             */
/*   Updated: 2019/01/30 12:34:47 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef	struct		s_tetri {
	char			piece[4][4];
	int				number;
	int				width;
	int				height;
}					t_tetri;

int					check_errors(int argc, char **argv);
char				*read_sample(int fd);
int					check_sample(char *sample);
int					check_link(char *sample, int mynb, int nb);
int					error_exit(char *sample);
void				save_tetri(char *sample, t_tetri *tab, int nb);
char				**new_map(int size);
void				free_map(char **map, int size);

#endif
