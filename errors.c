/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrancoi <afrancoi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:58:32 by afrancoi          #+#    #+#             */
/*   Updated: 2019/02/24 20:22:42 by afrancoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <fcntl.h>

/*
** Free the sample, put an error to stdin and return 1
*/

int	ft_error_exit(char *sample)
{
	if (sample)
		free(sample);
	ft_putendl("error");
	return (0);
}

/*
**	If we have 0 or 2+ args or the fd is invalid call error_exit()
*/

int		ft_check_errors(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl("usage : ./fillit file");
		exit(1);
	}
	return (open(argv[1], O_RDONLY));
}
