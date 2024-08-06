/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:03:58 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/06 10:04:00 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	file_checker(char *str, char *extension)
{
	char	*ext;

	ext = ft_strrchr(str, '.');
	if (!ext || ft_strncmp(ext, extension, 5))
		e_exit("File extension doesnt match", ext);
}

void	file_parsing(t_cub *cub, int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line)
	{
		if (line[0] != '\n')
		{
			if (line_parsing(cub, line))
			{
				map_parsing(cub, line, fd);
				return ;
			}
		}
		free(line);
		line = get_next_line(fd);
	}
}

void	parsing(t_cub *cub, char *str)
{
	int		fd;

	file_checker(str, ".cub\0");
	fd = open(str, O_RDONLY);
	if (fd == -1)
		exit_strerr(str, errno);
	initialize(cub);
	file_parsing(cub, fd);
	close(fd);
	checker(cub, cub->pdata->map);
	check_missing(cub);
	borders_check(cub->pdata->map);
}
