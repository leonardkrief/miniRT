/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 00:01:41 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/04 14:49:46 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ppm.h"

#define FILENAME "screenshot_01.ppm"
#define MAX_CHARS_ON_LINE 70

int	open_ppm(char *file)
{
	static int	file_number = 1;
	int			fd;
	struct stat	buffer;

	while (file_number < 1000 && stat(file, &buffer) == 0)
	{
		file[11] = '0' + file_number / 10;
		file[12] = '0' + file_number % 10;
		file_number++;
	}
	if (file_number == 1000)
	{
		ft_puterror(NO_FILENAME_AVAILABLE, (char *)__func__);
		return (-1);
	}
	fd = open(file, O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fd == -1)
		ft_puterror(FAILED_OPEN, file);
	return (fd);
}

void	ppm_header(int fd)
{
	ft_putstr_fd("P3\n", fd);
	ft_putnbr_fd(WIDTH, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(HEIGHT, fd);
	ft_putstr_fd("\n255\n", fd);
}

void	ppm_data(int fd, t_image i)
{
	char	*s;
	int		x;
	int		y;
	int		bytes_per_pixel;
	int		c;

	bytes_per_pixel = i.bits_per_pixel / 8;
	s = i.addr;
	c = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH * bytes_per_pixel)
		{
			if (c >= MAX_CHARS_ON_LINE - 4)
				c = ft_putchar_fd('\n', fd) - 1;
			if (x % 4 != 3)
			{
				if (c != 0)
					c += ft_putchar_fd(' ', fd);
				c += ft_putnbr_fd((unsigned char)s[y * i.line_length + x], fd);
			}
		}
	}
}

void	close_ppm(int fd)
{
	if (close(fd) == -1)
		ft_puterror(FAILED_CLOSE, strerror(errno));
}

void	get_ppm(t_image image)
{
	int			fd;
	static char	file[] = FILENAME;

	fd = open_ppm(file);
	if (fd == -1)
		return ;
	ppm_header(fd);
	ppm_data(fd, image);
	close_ppm(fd);
}

#undef FILENAME
#undef MAX_CHARS_ON_LINE