/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/14 01:06:40 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include <stdio.h>
# include <stdint.h>
# include "libft.h"

typedef enum e_failure{
	NO_FAILURE,
	FAILED_MALLOC,
	FAILED_OPEN,
	FAILED_CLOSE,
	ERROR_MODULUS,
	ERROR_NORMALIZE,
	ERROR_DOTPROD,
	ERROR_DETERMINANT,
	ERROR_INVERT_MATRIX,
	ERROR_RAY,
	ERROR_SPHERE,
	ERROR_INTERSECTION,
	FALSE_MATRIX_INPUT,
	UNKNOWN_OBJECT,
	FAILED_CREATING_OBJECT,
	NO_FILENAME_AVAILABLE,
	LAST_FAILURE = NO_FILENAME_AVAILABLE,
}	t_failure;

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
};

// utils/error_handler/error.c
int			ft_putstr_error(const char *s);
const char	*get_failure_string(const t_failure failure);
void		ft_puterror(const t_failure failure_set, const void *args);

#endif
