/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:25:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/27 16:09:31 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#include "cub3d.h"

t_err	set_config_option(t_config *config, char *option, char *value)
{
	if ((ft_strcmp(option, "NO") == 0))
		config->textures.no = value;
	else if ((ft_strcmp(option, "SO") == 0))
		config->textures.so = value;
	else if ((ft_strcmp(option, "WE") == 0))
		config->textures.we = value;
	else if ((ft_strcmp(option, "EA") == 0))
		config->textures.ea = value;
	else
		return (error_from("Unknown configuration option", (t_err)option));
	return (NULL);
}

void	teardown_config(t_config *config)
{
	if (config->textures.no != NULL)
		free((char *)config->textures.no);
	if (config->textures.so != NULL)
		free((char *)config->textures.so);
	if (config->textures.we != NULL)
		free((char *)config->textures.we);
	if (config->textures.ea != NULL)
		free((char *)config->textures.ea);
}
