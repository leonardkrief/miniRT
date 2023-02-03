/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 16:59:43 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include "miniRT.h"

# define NO_FAILURE					UINT64_C(0)
# define FAILED_MALLOC				UINT64_C(1)
# define FAILED_OPEN				UINT64_C(2)
# define FAILED_CLOSE				UINT64_C(3)
# define ERROR_MODULUS				UINT64_C(98) //"Error modulus: non-vector object detected"
# define ERROR_NORMALIZE			UINT64_C(97) //"Error normalize: non-vector object detected"
# define ERROR_DOTPROD				UINT64_C(97) //"Error dotprod: non-vector objects detected"
# define ERROR_DETERMINANT			UINT64_C(97) //"Error determinant: wrong dimension"
# define ERROR_INVERT_MATRIX		UINT64_C(97) //"Error invert matrix: det = 0"
# define FALSE_MATRIX_INPUT			UINT64_C(99) //"Cannot create matrix out of non-vector objects"
# define NO_FILENAME_AVAILABLE		UINT64_C(100) //"No more filenames available. Remove or rename ppm files"
# define LAST_FAILURE				NO_FILENAME_AVAILABLE

static const char	*failure_strings[] = {
	"No failure",
	"Failed malloc",
	"Failed open",
	"Failed close",
	"No more filenames available. Remove or rename ppm files"
};

typedef uint64_t failure_t;

// error_handler/error.c
int	ft_putstr_error(const char *s);
const char	*get_failure_string(failure_t failure);
void	ft_puterror(failure_t failure_set, void *args);

#endif
