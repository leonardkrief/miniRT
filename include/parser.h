/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:54:39 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/01 23:32:58 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "error_handler.h"
# include "world.h"

# if !defined(BONUS)
#  define BONUS 0
# endif

# define MAX_FILESIZE 10000

typedef enum e_flag_valid_number{
	FLAG_DEFAULT	= 0,
	FLAG_UNIT		= 1 << 0,
	FLAG_PIXEL		= 1 << 1,
	FLAG_POSITIVE	= 1 << 2,
	FLAG_ABS_UNIT	= 1 << 3,
	FLAG_FOV		= 1 << 4,
	FLAG_NON_NULL	= 1 << 5,
}	t_flag_valid_number;

typedef enum e_end_character{
	END_CHARACTER_COMMA,
	END_CHARACTER_BLANK,
}	t_end_character;

// parser/handle_file.c
int	check_filename(char *filename);
int	file_to_string(char *filename, char *str);
int	parsing(char *filename, t_world *w, t_camera *c);

// parser/parser_objects2.c
t_matrix	plane_matrix(t_tuple origin, t_tuple ortn);
char	*parser_plane(char *str, t_world *w);

// parser/parser.c
int	parsing(char *filename, t_world *w, t_camera *c);
char	*parser_next_object(char *str, t_world *w, t_camera *c);
double	parser_next_number(char **str, t_end_character end);
int	parser_valid_number(double x, t_flag_valid_number flag);
int	parser_valid_tuple(t_tuple t, t_flag_valid_number flag);

// parser/parser_objects1.c
char	*parser_ambient(char *str, t_world *w);
char	*parser_camera(char *str, t_world *w, t_camera *c);
char	*parser_light(char *str, t_world *w);
char	*parser_sphere(char *str, t_world *w);
char	*parser_cylinder(char *str, t_world *w);

#endif
