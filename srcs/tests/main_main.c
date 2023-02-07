/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:48:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/06 23:41:49 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	put_point(t_image *image, t_tuple pix)
{
	int	i;
	int	j;

	pix = point_to_pixel(image, pix.x, pix.y);
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

// ecran dans le plan (1,0,0)(0,1,0) qui contient le point (0,0,-3)
// je me situe en (0,0,-5)
// je dois lancer les rayons avec un angle qui varie:
// direction (0,0,1) qui doit aller toucher chacun des pixels
// i determine l'angle u dans le plan xz
// j determine l'angle v dans le plan yz

void	put_raytracer_to_image(t_image *img, t_raytracer rt, int i, int j)
{
	if (rt.itr_front.t > 0)
		put_pixel(img, i, j, pixel(255, 0, 255, 0));
}

#define MACRO_SIZE 2

int	main(void)
{
	t_tuple a;
	t_sphere	*sp = sphere(point(0, 0, 0), 1);
	t_matrix	m = matrix_matrix(matrix_scaling(1, 0.5, 1), matrix_z_rotation(M_PI / 5), 4);

	transform_sp(sp, &m);
	a = normal_at_sp(sp, point(sqrt(3)/3, sqrt(3)/3, sqrt(3)/3));
	tuple_print(a, "normal: ");
}

// v - 2 * <v,n> n

// int	main(void)
// {
// 	t_raytracer	rt  = raytracer(point(0, 0, -5), vector(0, 0, 1));
// 	t_sphere	*sp;
// 	(void)rt;

// 	sp = sphere(point(0, 0, 0), 1);
// 	sphere_print((const t_sphere) *sp, "S1: ");
// 	t_matrix	m;
// 	(void)m;
// 	// m = matrix_scaling(2, 2, 2);
// 	m = matrix_translation(2, 0, 0);
// 	transform_sp(sp, &m);
// 	sphere_print(*sp, "S2: ");
// 	intersection_sp(&rt, sp);
// 	raytracer_print(rt, "R1: ");
// 	// sp = sphere(point(0, 0, -5), 1);
// 	// intersection_sp(&rt, sp);
// 	// raytracer_print(rt, "R2: ");
// 	// intersection_sp(r, sp);
// 	// printf("%lu %lu %lu\n", sizeof(itr), sizeof(t_cylinder), sizeof(t_triangle));
// }
