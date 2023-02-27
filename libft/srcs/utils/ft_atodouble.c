/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atodouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:10:14 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/27 15:52:33 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	ft_atodouble(char *str, int *p)
{
	double	x;
	int		i;
	int		d;
	int		sign;

	x = 0;
	i = -1;
	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(str[++i]) && x <= __DBL_MAX__ / 1e7)
		x = 10 * x + (str[i] - '0');
	if (str[i] == '.')
	{
		d = i;
		while (ft_isdigit(str[++i]))
			x += (str[i] - '0') / pow(10, i - d);
	}
	*p = i;
	if (x > __DBL_MAX__ / 1e8)
		*p = -1;
	return (sign * x);
}
