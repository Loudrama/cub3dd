/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:04:05 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/06 10:04:08 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

t_img	*load_sprite(void *mlx, char *path)
{
	t_img	*sprite;

	sprite = malloc(sizeof(t_img));
	sprite->img = mlx_xpm_file_to_image(mlx, path,
			&sprite->width, &sprite->height);
	if (!sprite->img)
		exit_strerr(path, errno);
	sprite->addr = mlx_get_data_addr(sprite->img, &sprite->bits_per_pixel,
			&sprite->line_length, &sprite->endian);
	return (sprite);
}

void	init_textures(t_cub *cub)
{
	cub->images->we = load_sprite(cub->mlx, cub->pdata->we);
	cub->images->ea = load_sprite(cub->mlx, cub->pdata->ea);
	cub->images->no = load_sprite(cub->mlx, cub->pdata->no);
	cub->images->so = load_sprite(cub->mlx, cub->pdata->so);
}

void	draw_wall(t_cub *cub, t_wall wall, t_img *texture, int i)
{
	int		j;
	char	*dst;

	j = 0;
	while (j < wall.top_pixel)
		put_pixel(cub->cub, i, j++, cub->pdata->ceiling);
	while (j < wall.bottom_pixel)
	{
		wall.dft = j + (wall.wall_height / 2) - (WINDOW_H / 2);
		wall.tex_y = (int)(wall.dft
				* (float)texture->height / wall.wall_height)
			% texture->height;
		dst = texture->addr + wall.tex_y * texture->line_length
			+ wall.tex_x * (texture->bits_per_pixel / 8);
		put_pixel(cub->cub, i, j++, *(unsigned int *)dst);
	}
	while (j < WINDOW_H)
		put_pixel(cub->cub, i, j++, cub->pdata->floor);
}

void	render_frame_wall(t_cub *cub, int i, t_wall wall)
{
	t_img	*texture;

	if (cub->rays[i].hit_vertical)
	{
		if (cub->rays[i].is_facing_left)
			texture = cub->images->we;
		else
			texture = cub->images->ea;
		wall.tex_x = (int)(cub->rays[i].yhit
				* texture->width / TILE_SIZE) % texture->width;
	}
	else
	{
		if (cub->rays[i].up)
			texture = cub->images->no;
		else
			texture = cub->images->so;
		wall.tex_x = (int)(cub->rays[i].xhit
				* texture->width / TILE_SIZE) % texture->width;
	}
	draw_wall(cub, wall, texture, i);
}

void	project(t_cub *cub)
{
	int		i;
	t_wall	wall;

	i = -1;
	while (++i < WINDOW_W)
	{
		wall.correct_distance = cub->rays[i].distance
			* cos(cub->rays[i].angle - cub->player->angle);
		cub->player->plane_dist = (WINDOW_W / 2) / tan(cub->player->fov / 2);
		wall.wall_height = (TILE_SIZE / wall.correct_distance)
			* cub->player->plane_dist;
		wall.top_pixel = (WINDOW_H / 2) - (wall.wall_height / 2);
		if (wall.top_pixel < 0)
			wall.top_pixel = 0;
		wall.bottom_pixel = (WINDOW_H / 2) + (wall.wall_height / 2);
		if (wall.bottom_pixel > WINDOW_H)
			wall.bottom_pixel = WINDOW_H;
		render_frame_wall(cub, i, wall);
	}
}
