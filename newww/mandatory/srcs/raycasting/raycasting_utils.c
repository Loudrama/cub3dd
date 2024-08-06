/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:04:13 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/06 10:04:15 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

float	normalize_angle(float angle)
{
	angle = remainder(angle, (2 * M_PI));
	if (angle < 0)
		angle += (2 * M_PI);
	return (angle);
}

float	dbp(float x1, float y1, float x2, float y2)
{
	return (sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1))));
}

float	get_distance(t_cub *cub, t_cast *dir)
{
	if (dir->wall_hit)
		return (dbp(cub->player->x, cub->player->y,
				dir->xhit, dir->yhit));
	else
		return (INT_MAX);
}

void	get_horz(t_cub *cub, t_cast *horz, int i)
{
	while (horz->touch_x >= 0
		&& horz->touch_x <= cub->pdata->map_width
		&& horz->touch_y >= 0
		&& horz->touch_y <= cub->pdata->map_height)
	{
		if (!movable(cub->pdata, horz->touch_x,
				horz->touch_y - (cub->rays[i].up == true)))
		{
			horz->wall_hit = true;
			horz->xhit = horz->touch_x;
			horz->yhit = horz->touch_y;
			break ;
		}
		else
		{
			horz->touch_x += horz->xstep;
			horz->touch_y += horz->ystep;
		}
	}
}

void	get_vert(t_cub *cub, t_cast	*vert, int i)
{
	while (vert->touch_x >= 0
		&& vert->touch_x <= cub->pdata->map_width
		&& vert->touch_y >= 0
		&& vert->touch_y <= cub->pdata->map_height)
	{
		if (!movable(cub->pdata,
				vert->touch_x - (cub->rays[i].is_facing_left == true),
				vert->touch_y))
		{
			vert->wall_hit = true;
			vert->xhit = vert->touch_x;
			vert->yhit = vert->touch_y;
			break ;
		}
		else
		{
			vert->touch_x += vert->xstep;
			vert->touch_y += vert->ystep;
		}
	}
}
