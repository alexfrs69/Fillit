/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:32:12 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/24 20:24:43 by afrancoi         ###   ########.fr       */
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

int					ft_check_errors(int argc, char **argv);
char				*ft_read_sample(int fd);
int					ft_check_sample(char *sample);
int					ft_check_link(char *sample, int mynb, int nb);
int					ft_error_exit(char *sample);
void				ft_save_tetri(char *sample, t_tetri *tab, int nb);
char				**ft_new_map(int size);
void				ft_free_map(char **map, int size);
void				ft_replace_tetri(t_tetri *tetri, int nb);
void				ft_display_multitab(char **tab, int size);

#endif
