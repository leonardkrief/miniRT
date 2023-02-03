/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:48:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/03 01:53:57 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	t_canvas	cvs;

	canvas(&cvs);
	int	i = -1;
	while (++i <= WIDTH)
	{
		int	j = -1;
		while (++j <= HEIGHT)
			put_pixel(cvs.image, i, j, pixel(255, 0, 255, 0));
	}
	mlx_put_image_to_window(cvs.window.mlx, cvs.window.win, cvs.image.img, 0, 0);
	get_ppm(cvs.image);
	get_ppm(cvs.image);
	// mlx_loop(cvs.window.mlx);
}
