/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:39:36 by lufelip2          #+#    #+#             */
/*   Updated: 2023/02/21 12:47:50 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>
# include <mlx.h>

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
	t_img		buffer;
	t_color		floor;
	t_color		ceiling;
	t_img		walls[W_COUNT];
}	t_screen;

typedef struct s_cub
{
	t_screen	screen;
}	t_cub;

void	errmsg(const char *eror);

char	*parse_args(int argc, char **argv);

t_color	rgb(char r, char g, char b);

void	free_str_array(char **config);

int		cub_load_config(t_cub *cub, const char *filename);

int		render(t_cub *cub);

int		cub_exit(t_cub *cub);

void	cub_init(t_cub *cub);

#endif
