/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:52:05 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/28 00:55:55 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// A 0.2 255,255,255
char	*parser_ambient(char *str, t_world *w)
{
	(void)w;
	(void)str;
	return (NULL);
}

// C -50.0,0,20 0,0,1 70
char	*parser_camera(char *str, t_camera *c)
{
	double	fov;
	t_tuple	origin;
	t_tuple	ortn;

	origin = point(parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(origin, FLAG_DEFAULT))
		return (NULL);
	fov = parser_next_number(&str, END_CHARACTER_BLANK);
	if (parser_valid_number(fov, FLAG_FOV))
		return (NULL);
	ortn = vector(parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(ortn, FLAG_ABS_UNIT))
		return (NULL);
	ortn = tuple_normalize(ortn);
	*c = camera(DEFAULT_CAMERA_WIDTH_HI , DEFAULT_CAMERA_HEIGHT_HI , fov);
	view_transform(c, origin, point(0, 0, 0), ortn);
	return (str);
}

// L -40.0,50.0,0.0 0.6 10,0,255
char	*parser_light(char *str, t_world *w)
{
	t_tuple	origin;
	t_tuple	clr;
	double	brightness;

	origin = point(parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(origin, FLAG_DEFAULT))
		return (NULL);
	brightness = parser_next_number(&str, END_CHARACTER_BLANK);
	if (parser_valid_number(brightness, FLAG_UNIT))
		return (NULL);
	clr = point(brightness * parser_next_number(&str, END_CHARACTER_COMMA),
		brightness * parser_next_number(&str, END_CHARACTER_COMMA),
		brightness * parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(clr, FLAG_DEFAULT))
		return (NULL);
	world_add_light(w, light_point(origin, tmp_pixel(clr.x, clr.y, clr.z, 0)));
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
		return (NULL);
	dmtr = parser_next_number(&str, END_CHARACTER_BLANK);
	if (parser_valid_number(dmtr, FLAG_POSITIVE))
		return (NULL);
	clr = point(parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(clr, FLAG_PIXEL))
		return (NULL);
	transform_sp(sp, matrix_matrix(matrix_scaling(dmtr, dmtr, dmtr),
			matrix_translation(origin.x, origin.y, origin.z), 4));
	sp->mat.color = tmp_pixel(clr.x, clr.y, clr.z, 0);
	return (world_add_sphere(w, sp), str);
}

// pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
char	*parser_plane(char *str, t_world *w)
{
	t_tuple		origin;
	t_tuple		ortn;
	t_tuple		clr;
	t_sphere	*pl;

	pl = plane();
	if (pl == NULL)
		return (NULL);
	origin = point(parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(origin, FLAG_DEFAULT))
		return (NULL);
	ortn = vector(parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(ortn, FLAG_ABS_UNIT))
		return (NULL);
	ortn = tuple_normalize(ortn);
	clr = point(parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_COMMA),
		parser_next_number(&str, END_CHARACTER_BLANK));
	if (parser_valid_tuple(clr, FLAG_PIXEL))
		return (NULL);
	pl->mat.color = tmp_pixel(clr.x, clr.y, clr.z, 0);
	//////////////////////////////////////////////////////////////////
	//// IL FAUT TROUVER LA MATRICE DE TRANSFORMATION POUR PASSER ////
	//// DE (0, 1, 0) A ORTN ET POUR QUE LE PLAN CONTIENNE ORIGIN ////
	transform_pl(pl, matrix_matrix(matrix_rotation(dmtr, dmtr, dmtr),
			matrix_translation(origin.x, origin.y, origin.z), 4));
	//////////////////////////////////////////////////////////////////
	return (world_add_plane(w, pl), str);
}

// cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
char	*parser_cylinder(char *str, t_world *w)
{
	(void)w;
	(void)str;
	return (NULL);
}