/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:26:16 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/27 16:34:20 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdint.h>

# include "error.h"

typedef const char	*t_texture_path;

typedef uint32_t		t_color;

typedef struct s_config
{
	t_texture_path	no;
	t_texture_path	so;
	t_texture_path	we;
	t_texture_path	ea;
	t_color			floor;
	t_color			ceiling;
}	t_config;

t_err	set_config_option(t_config *config, char *option, char *value);

void	teardown_config(t_config *config);

t_err	load_map_config(const char *filename, t_config *config);

#endif
