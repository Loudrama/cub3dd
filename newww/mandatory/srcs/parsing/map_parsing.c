/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:03:41 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/06 10:03:44 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	check_missing(t_cub *cub)
{
	if (!cub->pdata->no || !cub->pdata->so || !cub->pdata->we || !cub->pdata->ea)
		exit_str("no textures");
	else if (cub->pdata->floor == -1 || cub->pdata->ceiling == -1)
		exit_str("no color");
	else if (!cub->pdata->map[0])
		exit_str("no map");
	else if (cub->player->x == -1 || cub->player->y == -1)
		exit_str("no player");
}

void	add_player(t_cub *cub, char **map, int y, int x)
{
	if (cub->player->x != -1 || cub->player->y != -1)
		exit_str("Duplicate player");
	cub->player->x = (x * TILE_SIZE) + 14;
	cub->player->y = (y * TILE_SIZE) + 14;
	if (map[y][x] == 'N')
		cub->player->angle = 270 * (M_PI / 180);
	else if (map[y][x] == 'S')
		cub->player->angle = 90 * (M_PI / 180);
	else if (map[y][x] == 'W')
		cub->player->angle = 180 * (M_PI / 180);
	else if (map[y][x] == 'E')
		cub->player->angle = 0 * (M_PI / 180);
	cub->pdata->map[y][x] = '0';
}

void	borders_check(char **map)
{
	int	j;
	int	i;

	j = 0;
	i = 0;
	while (map[0][j] == ' ' || map[0][j] == '1')
		j++;
	if (map[0][j] != '\0' && map[0][j] != '1' && map[0][j] != ' ')
		exit_str("Error: Invalid map");
	while (map[i])
	{
		if (map[i][0] == '\t'||
			map[i][0] == '\0' || map[i][0] == '\n')
			exit_str("Error: Invalid map");
		i++;
	}
}

void	checker(t_cub *cub, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (map[++i] && set_lines(cub) == 0)
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' || is_player(map[i][j]))
			{
				if (j > (int)ft_strlen(map[i + 1])
					|| j > (int)ft_strlen(map[i - 1]))
					exit_str("Error: Invalid map");
				if (map[i][j - 1] == ' ' || map[i][j - 1] == '\0'
					|| map[i][j + 1] == ' ' || map[i][j + 1] == '\0'
					|| map[i - 1][j] == ' ' || map[i - 1][j] == '\0'
					|| map[i + 1][j] == ' ' || map[i + 1][j] == '\0')
					e_exit("Invalid map", map[i]);
			}
			if (ft_strchr("NSWE", map[i][j]) != NULL)
				add_player(cub, map, i, j);
		}
	}
}

void	map_parsing(t_cub *cub, char *line, int fd)
{
	char	*tmp;

	while (line)
	{
		if (!is_map(line))
			e_exit("Invalid map", line);
		tmp = ft_strtrim(line, "\n");
		cub->pdata->height++;
		if (cub->pdata->width < (int)ft_strlen(tmp))
			cub->pdata->width = ft_strlen(tmp);
		cub->pdata->map = addx(cub->pdata->map, tmp);
		free(line);
		free(tmp);
		line = get_next_line(fd);
	}
	free(line);
	cub->pdata->map_width = cub->pdata->width * TILE_SIZE;
	cub->pdata->map_height = cub->pdata->height * TILE_SIZE;
}
