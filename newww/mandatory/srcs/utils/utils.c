/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:04:53 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/06 10:04:55 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

float	get_width(char *line)
{
	int	len;

	len = ft_strlen(line);
	return (len * TILE_SIZE);
}

int	movable(t_pdata *pdata, float x, float y)
{
	int	x_index;
	int	y_index;

	x_index = floor(x / TILE_SIZE);
	y_index = floor(y / TILE_SIZE);
	if (y < 0 || y > pdata->map_height)
		return (false);
	if (x < 0 || x > get_width(pdata->map[y_index]))
		return (false);
	if (pdata->map[y_index][x_index] != '1')
		return (true);
	return (false);
}

void	player_movement(t_cub *cub)
{
	float	xstep;
	float	ystep;
	float	ver_step;
	float	hor_step;

	xstep = 0;
	ystep = 0;
	cub->player->angle += cub->player->turndir * cub->player->turnspeed;
	ver_step = cub->player->ver_dir * cub->player->movespeed;
	hor_step = cub->player->hor_dir * (cub->player->movespeed - 2);
	xstep += (cos(cub->player->angle) * ver_step);
	xstep += (cos(cub->player->angle + M_PI / 2) * hor_step);
	ystep += (sin(cub->player->angle) * ver_step);
	ystep += (sin(cub->player->angle + M_PI / 2) * hor_step);
	xstep *= 5;
	ystep *= 5;
	if (movable(cub->pdata, cub->player->x + xstep, cub->player->y))
		cub->player->x += xstep / 5;
	if (movable(cub->pdata, cub->player->x, cub->player->y + ystep))
		cub->player->y += ystep / 5;
}

void	setup(t_cub *cub)
{
	hooks(cub);
	set_cub(cub);
}
