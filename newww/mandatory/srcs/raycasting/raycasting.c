/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:04:18 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/06 10:04:20 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_cast	*cast_horz(t_cub *cub, float r_angle, int i)
{
	t_cast	*horz;

	horz = (t_cast *)malloc(sizeof(t_cast));
	horz->wall_hit = false;
	horz->xhit = 0;
	horz->yhit = 0;
	horz->touch_y = floor(cub->player->y / TILE_SIZE) * TILE_SIZE;
	if (cub->rays[i].is_facing_down)
		horz->touch_y += TILE_SIZE;
	horz->touch_x = cub->player->x
		+ (horz->touch_y - cub->player->y) / tan(r_angle);
	horz->ystep = TILE_SIZE;
	if (cub->rays[i].up)
		horz->ystep *= -1;
	horz->xstep = TILE_SIZE / tan(r_angle);
	if (cub->rays[i].is_facing_left && horz->xstep > 0)
		horz->xstep *= -1;
	if (cub->rays[i].is_facing_right && horz->xstep < 0)
		horz->xstep *= -1;
	get_horz(cub, horz, i);
	return (horz);
}

t_cast	*cast_vert(t_cub *cub, float r_angle, int i)
{
	t_cast	*vert;

	vert = (t_cast *)malloc(sizeof(t_cast));
	vert->wall_hit = false;
	vert->xhit = 0;
	vert->yhit = 0;
	vert->touch_x = floor(cub->player->x / TILE_SIZE) * TILE_SIZE;
	if (cub->rays[i].is_facing_right)
		vert->touch_x += TILE_SIZE;
	vert->touch_y = cub->player->y
		+ (vert->touch_x - cub->player->x) * tan(r_angle);
	vert->xstep = TILE_SIZE;
	if (cub->rays[i].is_facing_left)
		vert->xstep *= -1;
	vert->ystep = TILE_SIZE * tan(r_angle);
	if (cub->rays[i].up && vert->ystep > 0)
		vert->ystep *= -1;
	if (cub->rays[i].is_facing_down && vert->ystep < 0)
		vert->ystep *= -1;
	get_vert(cub, vert, i);
	return (vert);
}

void	fill_ray(t_ray *ray, t_cast *dir, int boolean)
{
	ray->xhit = dir->xhit;
	ray->yhit = dir->yhit;
	ray->hit_vertical = boolean;
	ray->distance = dir->hit_distance;
}

void	cast_ray(t_cub *cub, float r_angle, int i)
{
	t_cast	*horz;
	t_cast	*vert;

	r_angle = normalize_angle(r_angle);
	cub->rays[i].is_facing_down = (r_angle > 0 && r_angle < M_PI);
	cub->rays[i].up = !cub->rays[i].is_facing_down;
	cub->rays[i].is_facing_right = (r_angle < 0.5 * M_PI
			|| r_angle > 1.5 * M_PI);
	cub->rays[i].is_facing_left = !cub->rays[i].is_facing_right;
	horz = cast_horz(cub, r_angle, i);
	vert = cast_vert(cub, r_angle, i);
	horz->hit_distance = get_distance(cub, horz);
	vert->hit_distance = get_distance(cub, vert);
	if (vert->hit_distance < horz->hit_distance)
		fill_ray(&cub->rays[i], vert, true);
	else
		fill_ray(&cub->rays[i], horz, false);
	if (cub->rays[i].distance == 0)
		cub->rays[i].distance = 0.0001;
	cub->rays[i].angle = r_angle;
	free(horz);
	free(vert);
}

void	sendrays(t_cub *cub)
{
	int		i;
	float	r_angle;

	i = -1;
	while (++i < WINDOW_W)
	{
		r_angle = cub->player->angle
			+ atan((i - WINDOW_W / 2) / cub->player->plane_dist);
		cast_ray(cub, r_angle, i);
	}
}
