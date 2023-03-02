/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:55:18 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/02 01:33:56 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "config/config.h"
#include <errno.h>
#include <fcntl.h>
#include <mlx.h>
#include <string.h>
#include <unistd.h>

char line_0[] = {1, 1, 1, 1, 1, 1, 1};
char line_1[] = {1, 0, 0, 0, 0, 0, 1};
char line_2[] = {1, 0, 0, 0, 0, 0, 1};
char line_3[] = {1, 0, 0, 0, 0, 0, 1};
char line_4[] = {1, 0, 0, 0, 0, 0, 1};
char line_5[] = {1, 0, 0, 0, 0, 0, 1};
char line_6[] = {1, 1, 1, 1, 1, 1, 1};

char *worldMapp[] = {
	line_0,
	line_1,
	line_2,
	line_3,
	line_4,
	line_5,
	line_6
};

static void	init_mlx(t_cub *cub)
{
	cub->screen.mlx = mlx_init();
	cub->screen.buffer.ptr = mlx_new_image(
			cub->screen.mlx,
			SCREEN_WIDTH,
			SCREEN_HEIGHT);
	cub->screen.buffer.data = mlx_get_data_addr(
			cub->screen.buffer.ptr,
			&cub->screen.buffer.bpp,
			&cub->screen.buffer.line_len,
			&cub->screen.buffer.endianess);
}

int	cub_load_config(t_cub *cub, const char *filename)
{
	int		fd;
	size_t	lineno;
	char	**lines;

	ft_bzero(cub, sizeof(t_cub));
	init_mlx(cub);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		errmsg(strerror(errno));
		return (1);
	}
	lines = read_config_file(fd);
	close(fd);
	if (lines == NULL)
		return (1);
	lineno = 0;
	if ((parse_options(cub, lines, &lineno) != 0)
		|| (parse_map(cub, lines, &lineno) != 0))
	{
		free_str_array(lines);
		return (1);
	}
	free_str_array(lines);
	return (0);
}

int	cub_exit(t_cub *cub)
{
	if (cub->screen.buffer.ptr != NULL)
		mlx_destroy_image(cub->screen.mlx, cub->screen.buffer.ptr);
	if (cub->screen.walls[W_NO].ptr != NULL)
		mlx_destroy_image(cub->screen.mlx, cub->screen.walls[W_NO].ptr);
	if (cub->screen.walls[W_SO].ptr != NULL)
		mlx_destroy_image(cub->screen.mlx, cub->screen.walls[W_SO].ptr);
	if (cub->screen.walls[W_WE].ptr != NULL)
		mlx_destroy_image(cub->screen.mlx, cub->screen.walls[W_WE].ptr);
	if (cub->screen.walls[W_EA].ptr != NULL)
		mlx_destroy_image(cub->screen.mlx, cub->screen.walls[W_EA].ptr);
	if (cub->screen.window != NULL)
		mlx_destroy_window(cub->screen.mlx, cub->screen.window);
	if (cub->screen.mlx != NULL)
		free(cub->screen.mlx);
	if (cub->map.rows != NULL)
		free_str_array(cub->map.rows);
	ft_bzero(cub, sizeof(t_cub));
	exit(EXIT_SUCCESS);
}

void	cub_init(t_cub *cub)
{
	cub->screen.window = mlx_new_window(
			cub->screen.mlx,
			SCREEN_WIDTH,
			SCREEN_HEIGHT,
			"Cub3D");
	cub->player.x = 224;
	cub->player.y = 300;
	cub->player.angle = 0;
	cub->map.rows = worldMapp;
	cub->map.height = 7;
	cub->map.width = 7;
	mlx_loop_hook(cub->screen.mlx, &render, cub);
	mlx_hook(cub->screen.window, 17, 0, &cub_exit, cub);
	mlx_hook(cub->screen.window, 2, 1L<<0, &handle_keyboard, cub);
	mlx_hook(cub->screen.window, 6, 1L<<6, &handle_mouse, cub);
	mlx_loop(cub->screen.mlx);
}
