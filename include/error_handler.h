/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/13 14:18:48 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include <stdio.h>
# include <stdint.h>
# include "libft.h"

typedef enum	e_failure{
	NO_FAILURE,
	FAILED_MALLOC,
	FAILED_OPEN,
	FAILED_CLOSE,
	ERROR_MODULUS, //"Error modulus: non-vector object detected"
	ERROR_NORMALIZE, //"Error normalize: non-vector object detected"
	ERROR_DOTPROD, //"Error dotprod: non-vector objects detected"
	ERROR_DETERMINANT, //"Error determinant: wrong dimension"
	ERROR_INVERT_MATRIX, //"Error invert matrix: det = 0"
	ERROR_RAY, //"Error creating ray"
	ERROR_SPHERE, //"Error creating sphere"
	ERROR_INTERSECTION, //"Error creating intersection"
	FALSE_MATRIX_INPUT, //"Cannot create matrix out of non-vector objects"
	UNKNOWN_OBJECT, //"Unknown geometric shape detected. Failed creating it"
	FAILED_CREATING_OBJECT, //"Unknown geometric shape detected. Failed creating it"
	NO_FILENAME_AVAILABLE, //"No more filenames available. Remove or rename ppm files"
	LAST_FAILURE = NO_FILENAME_AVAILABLE,
}	t_failure;

static const char	*failure_strings[] = {
	"No failure",
	"Failed malloc",
	"Failed open",
	"Failed close",
};

// utils/error_handler/error.c
int	ft_putstr_error(const char *s);
const char	*get_failure_string(const t_failure failure);
void	ft_puterror(const t_failure failure_set, const void *args);

#endif
