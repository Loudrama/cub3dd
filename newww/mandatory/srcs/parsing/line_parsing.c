/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:03:32 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/06 10:03:36 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	check_name(char *name)
{
	if (!ft_strncmp(name, "NO", 3))
		return (TOKEN_NO);
	else if (!ft_strncmp(name, "SO", 3))
		return (TOKEN_SO);
	else if (!ft_strncmp(name, "WE", 3))
		return (TOKEN_WE);
	else if (!ft_strncmp(name, "EA", 3))
		return (TOKEN_EA);
	else if (!ft_strncmp(name, "F", 2))
		return (TOKEN_F);
	else if (!ft_strncmp(name, "C", 2))
		return (TOKEN_C);
	else
		return (TOKEN_ERROR);
}

int	get_color(char *line, int *i)
{
	int		j;
	char	*rgb;
	int		color;
	int		k;

	if (line[*i] == ',')
		(*i)++;
	while (line[*i] && line[*i] == ' ')
		(*i)++;
	j = *i;
	while (line[*i] && line[*i] != ',' && line[*i] != ' ')
		(*i)++;
	rgb = ft_substr(line, j, *i - j);
	k = -1;
	while (rgb[++k])
		if (!ft_isdigit(rgb[k]))
			e_exit("Invalid color", line);
	if (!rgb[0])
		(free(rgb), e_exit("Invalid color", line));
	color = ft_atoi(rgb);
	free(rgb);
	if (color < 0 || color > 255)
		e_exit("Some element are out of range", line);
	return (color);
}

void	color_parsing(t_cub *cub, char *line, int token, int i)
{
	int		color[3];
	int		n;

	n = -1;
	while (++n < 3)
	{
		spaces_skip(line, &i);
		color[n] = get_color(line, &i);
	}
	if (line[i])
		e_exit("Invalid color", line);
	check_lenght(line);
	if (token == TOKEN_F && cub->pdata->floor == -1)
		cub->pdata->floor = (color[0] << 16) + (color[1] << 8) + color[2];
	else if (token == TOKEN_C && cub->pdata->ceiling == -1)
		cub->pdata->ceiling = (color[0] << 16) + (color[1] << 8) + color[2];
	else
		e_exit("duplicate color", line);
	free(line);
}

void	texture_parsing(t_cub *cub, char *line, int token, int i)
{
	char	*path;

	spaces_skip(line, &i);
	path = ft_strdup(&line[i]);
	file_checker(path, ".xpm\0");
	if (token == TOKEN_NO && !cub->pdata->no)
		cub->pdata->no = path;
	else if (token == TOKEN_SO && !cub->pdata->so)
		cub->pdata->so = path;
	else if (token == TOKEN_WE && !cub->pdata->we)
		cub->pdata->we = path;
	else if (token == TOKEN_EA && !cub->pdata->ea)
		cub->pdata->ea = path;
	else
		e_exit("Duplicate texture", line);
	free(line);
}

int	line_parsing(t_cub *cub, char *line)
{
	int		i;
	int		j;
	int		token;
	char	*name;

	i = 0;
	if (is_map(line))
		return (1);
	spaces_skip(line, &i);
	j = i;
	while (line[i] && line[i] != ' ' && line[i] != '\t')
		i++;
	name = ft_substr(line, j, i - j);
	token = check_name(name);
	if (token == TOKEN_ERROR)
		e_exit("Invalid Name", name);
	else if (token == TOKEN_F || token == TOKEN_C)
		color_parsing(cub, ft_strtrim(line, "\n"), token, i);
	else
		texture_parsing(cub, ft_strtrim(line, "\n"), token, i);
	free(name);
	return (0);
}
