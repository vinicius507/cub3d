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

# include "error.h"

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

t_err	set_config_option(t_config *config, char *option, char *value);

void	teardown_config(t_config *config);

t_err	load_map_config(const char *filename, t_config *config);

#endif
