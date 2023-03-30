/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:26:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/03/30 19:00:35 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include "../cub3d.h"

# define ERR_CFG_UNKNOWN_OPTION "Error\nconfig: expected option, got: '%s'\n"
# define ERR_CFG_TEXTURE_NOT_LOADED "Error\nCould not load XPM texture: '%s'\n"
# define ERR_CFG_WRONG_OPTION_VALUE "Error\nconfig: %s: invalid value\n"
# define ERR_CFG_UNSET_OPTIONS "Error\nconfig: configuration incomplete\n"
# define ERR_CFG_INVALID_MAP "Error\nmap: invalid map configuration\n"
# define ERR_CFG_MAP_NO_PLAYER "Error\nmap: no player inside the map\n"
# define ERR_CFG_MAP_TOO_MANY_PLAYERS "Error\nmap: too many players: %d\n"
# define ERR_CFG_DUPLICATE_KEY "Error\nconfig: %s: duplicate key in config\n"

enum e_tile
{
	TL_VOID = 1<<0,
	TL_WALL = 1<<1,
	TL_PLAYER = 1<<2,
	TL_FLOOR = 1<<3,
};

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

int		load_texture_option(t_cub *cub, char *key, int side, char *path);

int		load_color_option(t_color *option, char *key, char *value);

int		config_set_option(t_cub *cub, char *key, char *value);

int		parse_options(t_cub *cub, char **lines, size_t *lineno);

t_map	read_map(char **lines);

int		map_is_valid(t_map *map);

int		set_player_position(t_cub *cub);

int		parse_map(t_cub *cub, char **lines, size_t *lineno);

#endif
