/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:04:59 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/06 10:05:01 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_window(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		e_exit("mlx_init", "mlx not working");
	cub->win = mlx_new_window(cub->mlx,
			WINDOW_W, WINDOW_H, "cub");
	cub->rays = malloc(sizeof(t_ray) * WINDOW_W);
}

int	loop_hook(t_cub *cub)
{
	if (cub == NULL)
		s_exit("ERROR");
	player_movement(cub);
	sendrays(cub);
	project(cub);
	mlx_put_image_to_window(cub->mlx,
		cub->win, cub->cub->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_cub	*cub;

	if (ac != 2)
		s_exit("Usage: ./cub3D <map.cub>");
	cub = (t_cub *)malloc(sizeof(t_cub));
	parsing(cub, av[1]);
	init_window(cub);
	init_textures(cub);
	setup(cub);
	mlx_loop_hook(cub->mlx, loop_hook, cub);
	mlx_loop(cub->mlx);
	return (0);
}
