/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 22:56:06 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/05 14:23:08 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_handler.h"

int	ft_putstr_error(const char *s)
{
	return (ft_putstr_fd((char *)s, STDERR_FILENO));
}

const char	*get_failure_string(t_failure failure)
{
	return (failure_strings[failure]);
}

void	ft_puterror(t_failure failure_set, void *args)
{
	if (failure_set == NO_FAILURE || failure_set > LAST_FAILURE)
	{
		ft_putstr_error(get_failure_string(failure_set));
		if (args)
			ft_putstr_error((char *)args);
		ft_putstr_error("\n");
	}
}
