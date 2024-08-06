/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parsing_utls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:03:16 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/06 10:03:24 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	set_lines(t_cub *cub)
{
	if (cub->pdata->no == NULL || cub->pdata->so == NULL
		|| cub->pdata->we == NULL || cub->pdata->ea == NULL
		|| cub->pdata->floor == -1 || cub->pdata->ceiling == -1)
		exit_str("Error: Invalid file");
	return (0);
}
void	free_loop(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

void	check_lenght(char *line)
{
	int		i;
	char	**f;

	i = 0;
	f = ft_split(line, ',');
	if (!f)
		exit_str("Error");
	while (f[i])
		i++;
	if (i != 3)
		e_exit("Invalid color", line);
	free_loop(f);
}
