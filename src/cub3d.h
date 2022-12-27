/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 23:39:36 by lufelip2          #+#    #+#             */
/*   Updated: 2022/12/27 15:06:55 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <libft.h>

typedef struct s_textures
{
	const char	*no;
	const char	*so;
	const char	*we;
	const char	*ea;
}	t_textures;

typedef struct s_config
{
	t_textures	textures;
}	t_config;

void	error(const char *msg, const char *detail);

char	*parse_args(int argc, char **argv);

int		set_config_option(t_config *config, char *key, char *value);

void	teardown_config(t_config *config);

int		load_map_config(const char *filename, t_config *config);

#endif
