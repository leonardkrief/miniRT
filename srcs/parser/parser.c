/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:52:05 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/24 19:56:14 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser	parser_new(char *str)
{
	t_parser	new;

	new.str = str;
	new.len = -1;
	new.type = -1;
	return (new);
}

int	parser_type(t_parser *ps)
{
	while (ft_isblank(*ps->str))
		ps->str++;
	if (!ft_strncmp(ps->str, "A", 1))
		ps->type = AMBIENT_LIGHTNING;
	else if (!ft_strncmp(ps->str, "C", 1))
		ps->type = CAMERA;
	else if (!ft_strncmp(ps->str, "L", 1))
		ps->type = LIGHT;
	else if (!ft_strncmp(ps->str, "sp", 2))
		ps->type = SPHERE;
	else if (!ft_strncmp(ps->str, "pl", 2))
		ps->type = PLANE;
	else if (!ft_strncmp(ps->str, "cy", 2))
		ps->type = CYLINDER;
	else
		return (ft_puterror(ERROR_PARSING_TYPE, (char *)__func__), -1);
	if (ps->type == SPHERE || ps->type == PLANE || ps->type == CYLINDER)
		ps->str += 2;
	else
		ps->str += 1;
	if (!ft_isblank(*ps->str))
		return (ft_puterror(ERROR_PARSING_TYPE, (char *)__func__), -1);
	while (ft_isblank(*ps->str))
		ps->str++;
	return (0);
}

// A 0.2 255,255,255
int	parser_ambient_lightning(t_parser *ps)
{
	
}

// C -50.0,0,20 0,0,1 70
int	parser_camera(t_parser *ps)
{
	
}

// L -40.0,50.0,0.0 0.6 10,0,255
int	parser_light(t_parser *ps)
{
	
}

// sp 0.0,0.0,20.6 12.6 10,0,255
int	parser_sphere(t_parser *ps)
{
	
}

// pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
int	parser_plane(t_parser *ps)
{
	
}

// cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255
int	parser_cylinder(t_parser *ps)
{
	
}