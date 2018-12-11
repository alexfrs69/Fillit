/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:58:32 by afrancoi          #+#    #+#             */
/*   Updated: 2018/12/11 04:00:06 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdlib.h>

int		check_errors(int argc, char **argv)
{
	int fd;

	if (argc > 2 || argc == 1 || (fd = open(argv[1], O_RDONLY)) <= 0)
	{
		ft_putendl("error");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
