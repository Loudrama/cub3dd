/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:04:46 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/06 10:04:51 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	key_press(int kcode, t_cub *cub)
{
	if (kcode == ESC_KEY)
		exit(EXIT_SUCCESS);
	else if (kcode == W_KEY)
		cub->player->ver_dir = +1;
	else if (kcode == S_KEY)
		cub->player->ver_dir = -1;
	else if (kcode == D_KEY)
		cub->player->hor_dir = +1;
	else if (kcode == A_KEY)
		cub->player->hor_dir = -1;
	else if (kcode == RIGHT_KEY)
		cub->player->turndir = +1;
	else if (kcode == LEFT_KEY)
		cub->player->turndir = -1;
	return (0);
}

int	key_release(int kcode, t_cub *cub)
{
	if (kcode == W_KEY)
		cub->player->ver_dir = 0;
	else if (kcode == S_KEY)
		cub->player->ver_dir = 0;
	else if (kcode == D_KEY)
		cub->player->hor_dir = 0;
	else if (kcode == A_KEY)
		cub->player->hor_dir = 0;
	else if (kcode == RIGHT_KEY)
		cub->player->turndir = 0;
	else if (kcode == LEFT_KEY)
		cub->player->turndir = 0;
	return (0);
}

int	distroy_event(int kcode, t_cub *cub)
{
	(void)cub;
	(void)kcode;
	exit(EXIT_SUCCESS);
}

void	hooks(t_cub *cub)
{
	mlx_hook(cub->win, 2, 0, key_press, cub);
	mlx_hook(cub->win, 3, 0, key_release, cub);
	mlx_hook(cub->win, 17, 0, distroy_event, cub);
}

void	set_cub(t_cub *cub)
{
	cub->cub->width = WINDOW_W;
	cub->cub->height = WINDOW_H;
	cub->cub->img = mlx_new_image(cub->mlx, WINDOW_W, WINDOW_H);
	cub->cub->addr = mlx_get_data_addr(cub->cub->img, &cub->cub->bits_per_pixel,
			&cub->cub->line_length, &cub->cub->endian);
}
