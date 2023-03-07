/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:26:37 by lufelip2          #+#    #+#             */
/*   Updated: 2023/03/06 23:36:23 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECTION_H
# define PROJECTION_H

# include "../cub3d.h"

typedef struct s_hitbox
{
	double	y;
	double	x;
	double	delta_y;
	double	delta_x;
}	t_hitbox;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_fpoint
{
	double	x;
	double	y;
}	t_fpoint;

typedef struct s_hit
{
	double	x;
	double	y;
	int		side;
	double	distance;
}	t_hit;

# define BOX_SIZE 64
# define OUT_OF_LIMITS -1
# define NOT_HIT 1

double		radians(int nbr);
t_fpoint	cast(t_hitbox init_hitbox, t_map *world_map);
t_hit		v_ray(int angle, t_player player, t_map *world_map);
t_hit		h_ray(int angle, t_player player, t_map *world_map);
int			v_side(int y_coordinate);
int			h_side(int y_coordinate);
t_hit		raycast(int direction, t_player player, t_map *world_map);
t_hitbox	next_hhitbox(int angle, t_player player);
t_hitbox	next_vhitbox(int angle, t_player player);
int			what_im_doing(t_screen *screen, t_player player, t_map *world_map);
void		pixel_put(t_img *buffer, int x, int y, int color);
int			pixel_get(t_img *buffer, int x, int y);
int			background(t_img *buffer, t_color ceiling, t_color floor);
int			side_corretion(int angle);
void		wall_pixel_put(t_screen *screen, int x, t_hit *hit, int height);

#endif
