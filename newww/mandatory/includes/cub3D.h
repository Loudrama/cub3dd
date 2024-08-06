/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamardou <aamardou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/06 10:02:47 by aamardou          #+#    #+#             */
/*   Updated: 2024/08/06 10:02:48 by aamardou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <math.h>
# include "../libs/libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>

# define ESC_KEY 53
# define A_KEY 0
# define D_KEY 2
# define W_KEY 13
# define S_KEY 1
# define LEFT_KEY 123
# define RIGHT_KEY 124
# define WINDOW_W 1280
# define WINDOW_H 720
# define TILE_SIZE 32

enum e_TOKENS{
	TOKEN_NO,
	TOKEN_SO,
	TOKEN_WE,
	TOKEN_EA,
	TOKEN_F,
	TOKEN_C,
	TOKEN_MAP,
	TOKEN_ERROR,
};

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_player {
	float	x;
	float	y;
	float	angle;
	float	fov;
	int		ver_dir;
	int		hor_dir;
	float	movespeed;
	int		turndir;
	float	turnspeed;
	float	plane_dist;
}	t_player;

typedef struct s_wall
{
	int		dft;
	int		tex_x;
	int		tex_y;
	float	top_pixel;
	float	bottom_pixel;
	float	wall_height;
	float	correct_distance;
}	t_wall;

typedef struct s_cast
{
	float	xstep;
	float	ystep;
	float	xhit;
	float	yhit;
	float	touch_x;
	float	touch_y;
	float	hit_distance;
	int		wall_hit;
}	t_cast;

typedef struct s_ray
{
	float	angle;
	float	xhit;
	float	yhit;
	float	distance;
	int		hit_vertical;
	int		up;
	int		is_facing_down;
	int		is_facing_left;
	int		is_facing_right;
}	t_ray;

typedef struct s_images {
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
}	t_images;

typedef struct s_pdata {
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		map_width;
	int		map_height;
	char	**map;
	int		floor;
	int		ceiling;
	int		width;
	int		height;
}	t_pdata;

typedef struct s_cub {
	t_img		*cub;
	void		*mlx;
	void		*win;
	t_player	*player;
	t_images	*images;
	t_ray		*rays;
	t_pdata		*pdata;
}	t_cub;


void	parsing(t_cub *cub, char *str);
void	file_checker(char *str, char *extension);
void	file_parsing(t_cub *cub, int fd);
int		line_parsing(t_cub *cub, char *line);
void	color_parsing(t_cub *cub, char *line, int token, int i);
void	texture_parsing(t_cub *cub, char *line, int token, int i);
void	map_parsing(t_cub *cub, char *line, int fd);
void	spaces_skip(char *s, int *i);
int		is_map(char *line);
int		check_name(char *name);
int		argslen(char **args);
char	**addx(char **strs, char *arg);
void	check_missing(t_cub *cub);
void	add_player(t_cub *cub, char **map, int y, int x);
void	borders_check(char **map);
void	check_lenght(char *line);
int		set_lines(t_cub *cub);
int		is_player(char c);
void	checker(t_cub *cub, char **map);
void	init_pdata(t_cub *cub);
void	initialize(t_cub *cub);
void	playercnf(t_cub *cub);
void	init_window(t_cub *cub);
void	init_textures(t_cub *cub);
void	setup(t_cub *cub);
void	hooks(t_cub *cub);
void	set_cub(t_cub *cub);
void	update_frame(t_cub *cub);
void	render_frame(t_cub *cub);
void	project(t_cub *cub);
void	render_frame_wall(t_cub *cub, int i, t_wall wall);
void	draw_wall(t_cub *cub, t_wall wall, t_img *texture, int i);
void	sendrays(t_cub *cub);
void	cast_ray(t_cub *cub, float r_angle, int i);
void	fill_ray(t_ray *ray, t_cast *dir, int boolean);
t_cast	*cast_vert(t_cub *cub, float r_angle, int i);
t_cast	*cast_horz(t_cub *cub, float r_angle, int i);
float	normalize_angle(float angle);
float	get_distance(t_cub *cub, t_cast *dir);
float	dbp(float x1, float y1, float x2, float y2);
void	get_horz(t_cub *cub, t_cast *horz, int i);
void	get_vert(t_cub *cub, t_cast *vert, int i);
int		key_press(int kcode, t_cub *cub);
int		key_release(int kcode, t_cub *cub);
int		destroy_event(int kcode, t_cub *cub);
int		loop_hook(t_cub *cub);
t_img	*load_sprite(void *mlx, char *path);
void	put_pixel(t_img *img, int x, int y, int color);
void	player_movement(t_cub *cub);
int		movable(t_pdata *pdata, float x, float y);
float	get_width(char *line);
void	free_loop(char **args);
void	exit_str(char *str);
void	s_exit(char *str);
void	e_exit(char *str, char *err);
void	exit_strerr(char *str, int err);

#endif
