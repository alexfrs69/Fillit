/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:32:12 by afrancoi          #+#    #+#             */
/*   Updated: 2019/01/21 19:17:58 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

int					check_errors(int argc, char **argv);
char				*read_sample(int fd);
int					check_sample(char *sample);
void				check_link(char *sample, int mynb, int nb);
void				error_exit(void);

typedef	struct		s_tetri {
	char			*piece;
	int				number;
	int				width;
	int				height;
	struct s_tetri	*next;
}					t_tetri;

#endif
