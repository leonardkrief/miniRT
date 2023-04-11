/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:20:17 by lkrief            #+#    #+#             */
/*   Updated: 2023/04/01 23:34:29 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_filename(char *filename)
{
	int		len;

	len = ft_strlen(filename);
	if (len < 3)
		return (ft_puterror(ERROR_FILE_EXTENSION, (char *)__func__), -1);
	if (!(filename[len - 1] == 't' && filename[len - 2] == 'r'
			&& filename[len - 3] == '.'))
		return (ft_puterror(ERROR_FILE_EXTENSION, (char *)__func__), -1);
	return (0);
}

int	file_to_string(char *filename, char *str)
{
	int		fd;
	int		r;

	if (check_filename(filename))
		return (-1);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_puterror(ERROR_FILE_OPEN, (char *)__func__), -1);
	r = read(fd, str, MAX_FILESIZE + 1);
	if (r == -1)
		return (ft_puterror(ERROR_FILE_READ, (char *)__func__), -1);
	else if (r > MAX_FILESIZE)
		return (ft_puterror(ERROR_FILE_TOO_BIG, (char *)__func__), -1);
	str[r] = '\0';
	if (close(fd) == -1)
		return (ft_puterror(ERROR_FILE_CLOSE, (char *)__func__), -1);
	return (0);
}

int	parsing(char *filename, t_world *w, t_camera *c)
{
	char	file[MAX_FILESIZE + 2];
	char	*str;

	if (file_to_string(filename, file) == -1)
		return (-1);
	str = file;
	while (*str)
	{
		str = parser_next_object(str, w, c);
		if (str == NULL)
		{
			free_world(w);
			return (-1);
		}
	}
	return (0);
}
