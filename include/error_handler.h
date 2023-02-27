/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/28 00:34:05 by lkrief           ###   ########.fr       */
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
	ERROR_PARSING_TYPE,
	ERROR_PARSING_NUMBER,
	ERROR_PARSING_SYNTAX,
	ERROR_PARSING_UNIT,
	ERROR_PARSING_PIXEL,
	ERROR_PARSING_POSITIVE,
	ERROR_PARSING_ABS_UNIT,
	ERROR_PARSING_FOV,
	LAST_FAILURE = ERROR_PARSING_FOV,
}	t_failure;

// utils/error_handler/error.c
int			ft_putstr_error(const char *s);
const char	*get_failure_string(const t_failure failure);
void		ft_puterror(const t_failure failure_set, const void *args);

#endif
