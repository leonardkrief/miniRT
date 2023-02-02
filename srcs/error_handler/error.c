/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:56:06 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/01 14:44:15 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	ft_putstr_error(const char *s)
{
	return (fprintf(stderr, "%s", s));
}

const char	*get_failure_string(failure_t failure)
{
	return (failure_strings[failure]);
}

void	ft_puterror(failure_t failure_set, void *args)
{
	if (failure_set == NO_FAILURE || failure_set > LAST_FAILURE)
	{
		ft_putstr_error(get_failure_string(failure_set));
		if (args)
			ft_putstr_error((char *)args);
		ft_putstr_error("\n");
	}
}
