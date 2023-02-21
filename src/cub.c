/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:55:18 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/21 13:18:37 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "config/config.h"
#include <errno.h>
#include <fcntl.h>
#include <mlx.h>
#include <string.h>
#include <unistd.h>

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
	if (cub->screen.window != NULL)
		mlx_destroy_window(cub->screen.mlx, cub->screen.window);
	if (cub->screen.mlx != NULL)
		free(cub->screen.mlx);
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
	mlx_loop_hook(cub->screen.window, &render, cub);
	mlx_hook(cub->screen.window, 17, 0, &cub_exit, cub);
	mlx_loop(cub->screen.mlx);
}
