/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 01:46:26 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 00:38:35 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_fd(int n, int fd)
{
	unsigned int	z;
	char			c;
	int				len;

	len = 1;
	z = (-(n < 0) + (n >= 0)) * n;
	if (n < 0)
	{
		write(fd, "-", 1);
		len++;
	}
	c = '0' + z % 10;
	if (z >= 10)
		len += ft_putnbr_fd(z / 10, fd);
	write(fd, &c, 1);
	return (len);
}
