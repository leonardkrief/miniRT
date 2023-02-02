/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:08:50 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/02 19:24:50 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include "miniRT.h"

# define NO_FAILURE			UINT64_C(0)
# define FAILED_MALLOC		UINT64_C(1)
# define LAST_FAILURE		FAILED_MALLOC

static const char	*failure_strings[] = {
	"No failure",
	"Failed malloc"
};

typedef uint64_t failure_t;

// error_handler/error.c
int	ft_putstr_error(const char *s);
const char	*get_failure_string(failure_t failure);
void	ft_puterror(failure_t failure_set, void *args);

#endif
