/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:48:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/06 03:32:22 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	put_point(t_image image, t_tuple pix)
{
	int	i;
	int	j;

	pix = point_to_pixel(&image, pix.x, pix.y);
	i = pix.x - 6;
	while (++i < pix.x + 5)
	{
		if (i >= 0 && i < WIDTH)
		{
			j = pix.y - 6;
			while (++j < pix.y + 5)
			{
				if (j >= 0 && j < HEIGHT)
					put_pixel(image, i, j, pixel(255, 0, 255, 0));
			}
		}
	}
}

// int	main(int ac, char **av)
// {
// 	(void)ac;
// 	(void)av;

// 	t_canvas	cvs;
	
// 	canvas(&cvs);
// 	mlx_put_image_to_window(cvs.window.mlx, cvs.window.win, cvs.image.img, 0, 0);
// 	mlx_loop(cvs.window.mlx);

	// t_tuple		a;
	// t_tuple		b;
	// t_tuple		c;
	// t_tuple		d;
	// int			dim = 4;

	// (void)a;
	// (void)b;
	// (void)c;
	// (void)d;
	// a = tuple(8, -5, 9, 2);
	// b = tuple(7, 5, 6, 1);
	// c = tuple(-6, 0, 9, 6);
	// d = tuple(-3, 0, -9, -4);

	// t_matrix t;
	// t_tuple origin;

	// origin = origin
	// t = translation(1, 2, 3);
// }

int	main(void)
{
	t_ray			r  = ray(point(0, 0, 5), vector(0, 0, 1));
	const t_sphere	*sp = sphere(point(0, 0, 0), 3);

	intersection_sp(&r, sp);
	// sphere_print(sp, "S: ");
	ray_print(r, "R: ");
	// intersection_sp(r, sp);
	// printf("%lu %lu %lu\n", sizeof(itr), sizeof(t_cylinder), sizeof(t_triangle));
}
