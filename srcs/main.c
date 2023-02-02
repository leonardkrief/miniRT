/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:48:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/02 23:48:45 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	t_canvas	cvs;
	t_pixel		pix;

	canvas(&cvs);
	int	i = -1;
	while (++i <= WIDTH)
	{
		int	j = -1;
		v_pixel(&pix, i * j, i + j, j - i);
		while (++j <= HEIGHT)
			put_pixel(&cvs.image, i, j, pix);
	}
	mlx_put_image_to_window(cvs.window.mlx, cvs.win.win, cvs.image.img, 0, 0);
	mlx_loop(cvs.window.mlx);
}
