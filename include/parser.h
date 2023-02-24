/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:54:39 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/24 19:40:02 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "error_handler.h"

typedef enum e_type{
	AMBIENT_LIGHTNING,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}	t_type;

typedef struct s_parser{
	char	*str;
	int		len;
	t_type	type;
}	t_parser;

// parser/parser.c
t_parser	parser_new(char *str);
int			parser_type(t_parser *ps);

#endif