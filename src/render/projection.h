/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:27:45 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/04/13 15:00:20 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "../cub3d.h"

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define SCREEN_HALF_WIDTH 640
# define SCREEN_HALF_HEIGHT 360

# define RAY_PRECISION 1280

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_vector
{
	double	x;
	double	y;
}	t_vector;

typedef struct s_ray
{
	double	x;
	double	y;
}	t_ray;

typedef struct s_hit
{
	double	x;
	double	y;
	int		side;
	double	distance;
}	t_hit;

typedef struct s_texture
{
	t_img	*wall;
	t_point	start;
	t_hit	*hit;
	int		height;
}	t_texture;

t_screen	init_screen(void);
int			pixel_get(t_img *img, int x, int y);
void		load_hooks(t_cub *rcast);
void		pixel_put(t_img *img, int x, int y, int color);
int			rgb(int r, int g, int b);
void		fill(t_img *img, t_color color);
void		raycasting(t_cub *rcast);
int			render(t_cub *rcast);
void		draw_texture(t_screen *screen, t_texture texture);
void		draw(t_screen *screen, int x, int height, t_hit *hit);
void		draw_line(t_img *img, t_point start, t_point end, int color);
void		fisheye_fix(t_cub *cub, t_hit *hit, double ray_angle);

#endif
