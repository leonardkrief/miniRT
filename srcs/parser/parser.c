/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 18:52:05 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/01 23:39:31 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*parser_next_object(char *str, t_world *w, t_camera *c)
{
	static bool	first = true;
	bool		newline;

	newline = false;
	while (ft_isblank(*str))
	{
		if (*(str++) == '\n')
			newline = true;
	}
	if (!first && !newline)
		return (ft_puterror(ERROR_PARSING_SYNTAX, (char *)__func__), NULL);
	if (*str == '\0')
		return (str);
	else if (!ft_strncmp(str, "A", 1))
		str = parser_ambient(str + 1, w);
	else if (!ft_strncmp(str, "C", 1))
		str = parser_camera(str + 1, w, c);
	else if (!ft_strncmp(str, "L", 1))
		str = parser_light(str + 1, w);
	else if (!ft_strncmp(str, "sp", 2))
		str = parser_sphere(str + 2, w);
	else if (!ft_strncmp(str, "pl", 2))
		str = parser_plane(str + 2, w);
	else if (!ft_strncmp(str, "cy", 2))
		str = parser_cylinder(str + 2, w);
	else
		return (ft_puterror(ERROR_PARSING_TYPE, (char *)__func__), NULL);
	first = false;
	return (str);
}

double	parser_next_number(char **str, t_end_character end)
{
	double	x;
	int		p;

	if (**str == '\0')
		return (ft_puterror(ERROR_PARSING_SYNTAX,
				(char *)__func__), __DBL_MAX__);
	while (ft_isblank(**str))
		(*str)++;
	x = ft_atodouble(*str, &p);
	if (p == -1)
		return (ft_puterror(ERROR_PARSING_NUMBER,
				(char *)__func__), __DBL_MAX__);
	if (end == END_CHARACTER_COMMA && (*str)[p++] != ',')
		return (ft_puterror(ERROR_PARSING_SYNTAX,
				(char *)__func__), __DBL_MAX__);
	else if (end == END_CHARACTER_BLANK && !ft_isblank((*str)[p])
			&& (*str)[p] != '\0')
		return (ft_puterror(ERROR_PARSING_SYNTAX,
				(char *)__func__), __DBL_MAX__);
	*str += p;
	return (x);
}

int	parser_valid_number(double x, t_flag_valid_number flag)
{
	if (x > __DBL_MAX__ / 1e8)
		return (-1);
	if ((flag & FLAG_UNIT) && !(x >= 0 && x <= 1))
		return (ft_puterror(ERROR_PARSING_UNIT, NULL), -1);
	if ((flag & FLAG_PIXEL) && !(x >= 0 && x <= 255))
		return (ft_puterror(ERROR_PARSING_PIXEL, NULL), -1);
	if ((flag & FLAG_POSITIVE) && !(x >= 0))
		return (ft_puterror(ERROR_PARSING_POSITIVE, NULL), -1);
	if ((flag & FLAG_ABS_UNIT) && !(x >= -1 && x <= 1))
		return (ft_puterror(ERROR_PARSING_ABS_UNIT, NULL), -1);
	if ((flag & FLAG_FOV) && !(x >= 0 && x <= 180))
		return (ft_puterror(ERROR_PARSING_FOV, NULL), -1);
	return (0);
}

int	parser_valid_tuple(t_tuple t, t_flag_valid_number flag)
{
	if (parser_valid_number(t.x, flag) || parser_valid_number(t.y, flag)
		|| parser_valid_number(t.z, flag) || parser_valid_number(t.w, flag))
		return (-1);
	else if ((flag & FLAG_NON_NULL) && (!t.x && !t.y && !t.z))
		return (ft_puterror(ERROR_PARSING_NON_NULL, NULL), -1);
	return (0);
}
