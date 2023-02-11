/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_three_spheres.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 19:11:56 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/11 19:12:24 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_world	world_three_spheres(void)
{
	t_world w;
	t_sphere *sp;

	ft_memset(&w, 0, sizeof(t_world));
	world_add_light(&w, light_point(point(-10, 10, -10), tmp_pixel(TMP_PIXEL_WHITE, 0)));

	// floor
	sp = sphere();
	transform_sp(sp, SCALING(10, 0.01, 10));
	sp->mat.color = tmp_pixel(1, 0.9, 0.9, 0);
	sp->mat.specular = 0;
	world_add_sphere(&w, sp);

	// left_wall
	sp = sphere();
	transform_sp(sp, MUL(MUL(TRANSLATION(0, 0, 5), MUL(ROTATION_Y(-M_PI/4), ROTATION_X(M_PI/2))), SCALING(10, 0.01, 10)));
	sp->mat.color = tmp_pixel(1, 0.9, 0.9, 0);
	sp->mat.specular = 0;
	world_add_sphere(&w, sp);

	// right_wall
	sp = sphere();
	transform_sp(sp, TRANSLATION(0, 0, 5));
	transform_sp(sp, ROTATION_Y(M_PI/4));
	transform_sp(sp, ROTATION_X(M_PI/2));
	transform_sp(sp, SCALING(10, 0.01, 10));
	sp->mat.color = tmp_pixel(1, 0.9, 0.9, 0);
	sp->mat.specular = 0;
	world_add_sphere(&w, sp);

	// big green sphere
	sp = sphere();
	transform_sp(sp, TRANSLATION(-0.5, 1, 0.5));
	sp->mat.color = tmp_pixel(0.1, 1, 0.5, 0);
	sp->mat.diffuse = 0.7;
	sp->mat.specular = 0.3;
	world_add_sphere(&w, sp);

	// small green sphere
	sp = sphere();
	transform_sp(sp, TRANSLATION(1.5, 0.5, -0.5));
	transform_sp(sp, SCALING(0.5, 0.5, 0.5));
	sp->mat.color = tmp_pixel(0.5, 1, 0.1, 0);
	sp->mat.diffuse = 0.7;
	sp->mat.specular = 0.3;
	world_add_sphere(&w, sp);

	// smaller yellow sphere
	sp = sphere();
	transform_sp(sp, TRANSLATION(-1.5, 0.33, -0.75));
	transform_sp(sp, SCALING(0.33, 0.33, 0.33));
	sp->mat.color = tmp_pixel(1, 0.8, 0.1, 0);
	sp->mat.diffuse = 0.7;
	sp->mat.specular = 0.3;
	world_add_sphere(&w, sp);

	return (w);
}