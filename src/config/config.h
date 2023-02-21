/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:26:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/21 13:29:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "../cub3d.h"

# define ERR_CFG_UNKNOWN_OPTION "Error\nUnknown configuration option: %s"
# define ERR_CFG_TEXTURE_NOT_LOADED "Error\nCould not load XPM texture: %s"

/**
 * Config structure, mainly for storing the raw data from the config file.
 * The field `map_lines` is a string separated by `\n` of the map lines.
 */
typedef struct s_config
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*floor;
	char	*ceiling;
	char	*map_lines;
}	t_config;

char	**read_config_file(int fd);

char	*option_key(char *line);

char	*option_value(char *line);

int		load_texture_option(t_cub *cub, int side, char *path);

int		load_color_option(t_cub *cub, char key, char *value);

int		config_set_option(t_cub *cub, char *key, char *value);

int		parse_options(t_cub *cub, char **lines, size_t *lineno);

int		parse_map(t_cub *cub, char **lines, size_t *lineno);

#endif
