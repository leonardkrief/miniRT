/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 02:13:39 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/01 01:48:42 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	size_t	j;
	int		sens;

	if (!dst && !src)
		return (NULL);
	i = 0;
	sens = 0;
	while (sens == 0 && i < len)
	{
		if (((unsigned char *)dst) + i == src)
			sens = 1;
		i++;
	}
	i = 0;
	while (i < len)
	{
		j = ((sens == 1) * i) + ((sens != 1) * (len - i - 1));
		((unsigned char *)dst)[j] = ((unsigned char *)src)[j];
		i++;
	}
	return (dst);
}
