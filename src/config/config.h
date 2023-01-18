/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:26:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/01/15 13:06:17 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

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

int		config_set_option(t_config *config, char *option, char *value);

int		config_should_read_map(t_config *config);

int		config_add_map_line(t_config *config, char *line);

void	config_teardown(t_config *config);

int		load_config(const char *filename, t_config *config);

#endif
