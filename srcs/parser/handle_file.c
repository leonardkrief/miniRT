/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 18:20:17 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/28 19:11:31 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "parser.h"

int	file_to_string(char *file, char *str)
{
	int		fd;
	int		r;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (ft_puterror(ERROR_FILE_OPEN, (char *)__func__), -1);
	r = read(fd, str, MAX_FILESIZE + 1);
	if (r > MAX_FILESIZE)
		return (ft_puterror(ERROR_FILE_TOO_LONG, (char *)__func__), -1);
	str[r] = '\0';
	return (0);
}
