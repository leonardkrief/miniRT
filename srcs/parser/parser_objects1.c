/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:52:05 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/14 19:47:55 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// A 0.2 255,255,255
char	*parser_ambient(char *str, t_world *w)
{
	double	brt;
	t_tuple	clr;

	if (w->def_ambient)
		return (ft_puterror(ERROR_DEFINED_AMBIENT, (char *)__func__), NULL);
	brt = parser_next_number(&str, END_CHARACTER_BLANK);
	if (parser_valid_number(brt, FLAG_UNIT))
		return (NULL);
	clr = point(parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(clr, FLAG_PIXEL))
		return (NULL);
	w->ambient = pixel_to_tmp_pixel(
			pixel(brt * clr.x, brt * clr.y, brt * clr.z, 0));
	w->def_ambient = 1;
	return (str);
}

// C -50.0,0,20 0,0,1 70
char	*parser_camera(char *str, t_world *w, t_camera *c)
{
	double	fov;
	t_tuple	origin;
	t_tuple	forward;

	if (w->def_camera)
		return (ft_puterror(ERROR_DEFINED_CAMERA, (char *)__func__), NULL);
	origin = point(parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(origin, FLAG_DEFAULT))
		return (NULL);
	forward = vector(parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(forward, FLAG_ABS_UNIT | FLAG_NON_NULL))
		return (NULL);
	fov = parser_next_number(&str, END_CHARACTER_BLANK);
	if (parser_valid_number(fov, FLAG_FOV))
		return (NULL);
	forward = tuple_normalize(forward);
	*c = camera(WINDOW_HEIGHT, WINDOW_WIDTH, fov * M_PI
			/ 180.0);
	view_transform(c, origin, forward, vector(0, 1, 0));
	w->def_camera = 1;
	return (str);
}

// L -40.0,50.0,0.0 0.6 10,0,255
char	*parser_light(char *str, t_world *w)
{
	t_tuple	origin;
	t_tuple	clr;
	double	brt;

	if (w->def_light && BONUS == 0)
		return (ft_puterror(ERROR_DEFINED_LIGHT, (char *)__func__), NULL);
	origin = point(parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(origin, FLAG_DEFAULT))
		return (NULL);
	brt = parser_next_number(&str, END_CHARACTER_BLANK);
	if (parser_valid_number(brt, FLAG_UNIT))
		return (NULL);
	clr = point(parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(clr, FLAG_PIXEL))
		return (NULL);
	world_add_light(w, light_point(origin, pixel_to_tmp_pixel(pixel(brt * clr.x,
					brt * clr.y, brt * clr.z, 0))));
	w->def_light = 1;
	return (str);
}

// sp 0.0,0.0,20.6 12.6 10,0,255
char	*parser_sphere(char *str, t_world *w)
{
	t_tuple		origin;
	t_tuple		clr;
	double		dmtr;
	t_sphere	*sp;

	sp = sphere();
	if (sp == NULL)
		return (NULL);
	origin = point(parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(origin, FLAG_DEFAULT))
		return (free(sp), NULL);
	dmtr = parser_next_number(&str, END_CHARACTER_BLANK);
	if (parser_valid_number(dmtr, FLAG_POSITIVE))
		return (free(sp), NULL);
	clr = point(parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_COMMA),
			parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(clr, FLAG_PIXEL))
		return (free(sp), NULL);
	transform_sp(sp, matrix_matrix(matrix_translation(origin.x, origin.y,
				origin.z), matrix_scaling(dmtr, dmtr, dmtr), 4));
	sp->mat.color = pixel_to_tmp_pixel(pixel(clr.x, clr.y, clr.z, 0));
	return (world_add_sphere(w, sp), str);
}
