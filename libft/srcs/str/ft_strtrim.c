/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 20:52:44 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/08 20:06:38 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	i;
	size_t	len;
	char	*dst;

	len = ft_strlen(s1);
	i = 0;
	while (len >= i + 1 && ft_strchr(set, s1[len - i - 1]))
		i++;
	len -= 0 + i * (len > 0);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	len -= 0 + i * (len > 0);
	dst = malloc(sizeof(*dst) * ((len > 0) * len + 1));
	if (!dst)
		return (NULL);
	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	dst[len++] = 0;
	while (--len > 0)
		dst[len - 1] = s1[i + len - 1];
	return (dst);
}
