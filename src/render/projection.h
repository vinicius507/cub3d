/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:27:45 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/19 19:12:24 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RCAST_H
# define RCAST_H

# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define SCREEN_HALF_WIDTH 640
# define SCREEN_HALF_HEIGHT 360

# define RAY_PRECISION 1024
# include <stdlib.h>
# include "../cub3d.h"

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

t_screen	init_screen(void);
int			pixel_get(t_img *img, int x, int y);
void		load_hooks(t_cub *rcast);
void		pixel_put(t_img *img, int x, int y, int color);
int			rgb(int r, int g, int b);
void		fill(t_img *img, t_color color);
void		raycasting(t_cub *rcast);
int			render(t_cub *rcast);

#endif // !RCAST_H
