/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:54:39 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/28 00:29:53 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "error_handler.h"
# include "world.h"

typedef enum e_flag_valid_number{
	FLAG_DEFAULT	= 0,
	FLAG_UNIT		= 1 << 0,
	FLAG_PIXEL		= 1 << 1,
	FLAG_POSITIVE	= 1 << 2,
	FLAG_ABS_UNIT	= 1 << 3,
	FLAG_FOV		= 1 << 4,
}	t_flag_valid_number;

typedef enum e_end_character{
	END_CHARACTER_COMMA,
	END_CHARACTER_BLANK,
}	t_end_character;

// parser/parser_objects.c
char	*parser_ambient(char *str, t_world *w);
char	*parser_camera(char *str, t_camera *c);
char	*parser_light(char *str, t_world *w);
char	*parser_sphere(char *str, t_world *w);
char	*parser_plane(char *str, t_world *w);
char	*parser_cylinder(char *str, t_world *w);

// parser/parser.c
int	parsing(char *str, t_world *w, t_camera *c);
char	*parser_next_object(char *str, t_world *w, t_camera *c);
double	parser_next_number(char **str, t_end_character end);
int	parser_valid_number(double x, t_flag_valid_number flag);
int	parser_valid_tuple(t_tuple t, t_flag_valid_number flag);

#endif