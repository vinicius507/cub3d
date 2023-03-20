/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:39:36 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/19 20:31:24 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <mlx.h>
# include <math.h>
# include <X11/keysym.h>
# include <stdio.h>
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720

enum e_wall_direction
{
	W_NO,
	W_SO,
	W_WE,
	W_EA,
	W_COUNT,
};

typedef struct s_img
{
	void	*ptr;
	char	*data;
	int		bpp;
	int		line_len;
	int		endianess;
	int		width;
	int		height;
}	t_img;

typedef union u_color
{
	unsigned int	hex;
	unsigned char	rgb[4];
}	t_color;

typedef struct s_screen
{
	void		*mlx;
	void		*window;
	float		angle_rays;
	float		projection_distance;
	t_img		buffer;
	t_color		floor;
	t_color		ceiling;
	t_img		walls[W_COUNT];
}	t_screen;

typedef struct s_map
{
	char	**rows;
	size_t	width;
	size_t	height;
}	t_map;

typedef struct s_player
{
	double			x;
	double			y;
	double		angle;
	int			fov;
}	t_player;

typedef struct s_cub
{
	t_map		map;
	t_screen	screen;
	t_player	player;
}	t_cub;

void	errmsg(const char *eror);
char	*parse_args(int argc, char **argv);
int	rgb(int r, int g, int b);
void	free_str_array(char **config);
int		str_is_whitespace_only(char *line);
int		cub_load_config(t_cub *cub, const char *filename);
int		render(t_cub *cub);
int		cub_exit(t_cub *cub);
void	cub_init(t_cub *cub);
int		handle_mouse(int x, int y, t_cub *cub);
int		handle_keyboard(int keysym, t_cub *cub);
void	move_up(t_cub *cub);
void	move_down(t_cub *cub);
void	move_left(t_cub *cub);
void	move_right(t_cub *cub);
void	move(t_cub *cub, double x, double y);

#endif
