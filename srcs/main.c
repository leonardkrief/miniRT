/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 18:48:55 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/06 17:01:31 by lkrief           ###   ########.fr       */
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

#define MACRO_SIZE 1

void	make_scene(t_canvas *cvs)
{
	int	i, j;
	t_tuple a;
	t_tuple light;
	t_raytracer	rt;
	t_matrix	m = matrix_scaling(MACRO_SIZE, MACRO_SIZE, MACRO_SIZE);
	t_sphere	*sp = sphere(point(0, 0, 0), 1);
	transform_sp(sp, &m);

	light = point(0, 0, -5);
	for(i = 0; i < WIDTH; i++)
	{
		for(j = 0; j < HEIGHT; j++)
		{
			a = pixel_to_point(&cvs->image, i, j);
			a = tuple_sub(a, light);
			a = normalize(a);
			// printf("(i j) = (%2d %2d)     (x y z) = (%.2f %.2f %.2f)\n", i, j, a.x, a.y, a.z);
			rt = raytracer(light, a);
			intersection_sp(&rt, sp);
			if (rt.itr_front.id != 0)
				put_pixel(&cvs->image, i, j, pixel(255, 0, 255, 0));
		}
	}
}

int	main(int ac, char **av)
{
	(void)ac;
	(void)av;

	t_canvas	cvs;
	// t_raytracer	rt  = raytracer(point(0, 0, -5), vector(0, 0, 1));
	t_sphere	*sp = sphere(point(0, 0, 0), 1);
	t_matrix	m;
	// (void)rt;
	(void)cvs;
	(void)sp;
	(void)m;

	canvas(&cvs);
	make_scene(&cvs);
	// sphere_print((const t_sphere) *sp, "S1: ");
	// (void)m;
	// m = matrix_scaling(2, 2, 2);
	// transform_sp(sp, &m);

	mlx_put_image_to_window(cvs.window.mlx, cvs.window.win, cvs.image.img, 0, 0);
	mlx_loop(cvs.window.mlx);
}



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
