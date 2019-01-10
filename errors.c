/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:58:32 by afrancoi          #+#    #+#             */
/*   Updated: 2018/12/13 04:03:55 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

void	error_exit(void)
{
	ft_putendl("error");
	exit(EXIT_FAILURE);
}

/*
**	If we have 0 or 2+ args or the fd is invalid call error_exit()
*/

int		check_errors(int argc, char **argv)
{
	int fd;

	fd = 0;
	if (argc > 2 || argc == 1 || (fd = open(argv[1], O_RDONLY)) <= 0)
		error_exit();
	return (fd);
}
