/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ppm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 00:01:41 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 02:01:34 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

#define FILENAME "screen_capture_01.ppm"
#define MAX_CHARS_ON_LINE 70

int	open_ppm()
{
	static int	file_number = 1;
	char		file[22] = FILENAME;
	int			fd;
	struct stat	buffer;

	while (file_number < 1000 && stat(file, &buffer) == 0)
	{
		file[15] = '0' + file_number / 10;
		file[16] = '0' + file_number % 10;
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

void	ppm_data(int fd, t_image image)
{
	char	*dst;
	int		x;
	int		y;
	int		bytes_per_pixel;
	int		chars;

	bytes_per_pixel = image.bits_per_pixel / 8;
	dst = image.addr;
	chars = 0;
	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH * bytes_per_pixel)
		{
			if (chars >= MAX_CHARS_ON_LINE - 4)
				chars = ft_putchar_fd('\n', fd) - 1;
			if (x % 4 != 3)
			{
				if (chars != 0)
					chars += ft_putchar_fd(' ', fd);
				chars += ft_putnbr_fd((unsigned char)dst[y * image.line_length + x], fd);
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
	int	fd;

	fd = open_ppm();
	if (fd == - 1)
		return ;
	ppm_header(fd);
	ppm_data(fd, image);
	close_ppm(fd);
}