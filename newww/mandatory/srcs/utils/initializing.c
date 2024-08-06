/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:04:36 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/06 10:04:41 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_pdata(t_cub *cub)
{
	cub->pdata->no = NULL;
	cub->pdata->so = NULL;
	cub->pdata->we = NULL;
	cub->pdata->ea = NULL;
	cub->pdata->floor = -1;
	cub->pdata->ceiling = -1;
	cub->pdata->width = 0;
	cub->pdata->height = 0;
}

void	playercnf(t_cub *cub)
{
	cub->player->x = -1;
	cub->player->y = -1;
	cub->player->ver_dir = 0;
	cub->player->hor_dir = 0;
	cub->player->turndir = 0;
	cub->player->angle = 0;
	cub->player->fov = 60 * (M_PI / 180);
	cub->player->turnspeed = 3 * (M_PI / 180);
	cub->player->movespeed = 5;
	cub->player->plane_dist = (WINDOW_W / 2) / tan(cub->player->fov / 2);
}

void	initialize(t_cub *cub)
{
	cub->cub = malloc(sizeof(t_img));
	cub->images = malloc(sizeof(t_images));
	cub->pdata = malloc(sizeof(t_pdata));
	cub->player = malloc(sizeof(t_player));
	cub->pdata->map = ft_calloc(1, sizeof(char *));
	init_pdata(cub);
	playercnf(cub);
}
