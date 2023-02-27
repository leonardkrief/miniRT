/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:56:06 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/28 00:33:44 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handler.h"

static const char	*g_failure_strings[] = {
	"No failure",
	"Failed malloc",
	"Failed open",
	"Failed close",
	"Error modulus: non-vector object detected",
	"Error normalize: non-vector object detected",
	"Error dotprod: non-vector objects detected",
	"Error determinant: wrong dimension",
	"Error invert matrix: det = 0",
	"Error creating ray",
	"Error creating sphere",
	"Error creating intersection",
	"Cannot create matrix out of non-vector objects",
	"Unknown geometric shape detected. Failed creating it",
	"Unknown geometric shape detected. Failed creating it",
	"No more filenames available. Remove or rename ppm files",
	"Unrecognized object during file parsing",
	"Number too big for program (max supported is ~10e300). Edit .rt file",
	"Unvalid syntax. Edit .rt file",
	"Unvalid syntax: unit value expected (0 <= x <= 1)",
	"Unvalid syntax. pixel value expected (0 <= x <= 255)",
	"Unvalid syntax. positive value expected (x >= 0)",
	"Unvalid syntax. absolut unit value expected (x >= -1, x <= 1)",
	"Unvalid syntax. fov value expected (x >= 0, x <= 180)",
};

int	ft_putstr_error(const char *s)
{
	return (ft_putstr_fd((char *)s, STDERR_FILENO));
}

const char	*get_failure_string(const t_failure failure)
{
	return (g_failure_strings[failure]);
}

void	ft_puterror(const t_failure failure_set, const void *args)
{
	if (failure_set >= NO_FAILURE && failure_set <= LAST_FAILURE)
	{
		ft_putstr_error(get_failure_string(failure_set));
		if (args)
		{
			ft_putstr_error(" ==> ");
			ft_putstr_error((char *)args);
		}
		ft_putstr_error("\n");
	}
}
