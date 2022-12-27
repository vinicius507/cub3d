/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:25:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/27 15:03:09 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <cub3d.h>

int	set_config_option(t_config *config, char *key, char *value)
{
	if (key == NULL)
		return (1);
	if ((ft_strcmp(key, "NO") == 0))
		config->textures.no = value;
	else if ((ft_strcmp(key, "SO") == 0))
		config->textures.so = value;
	else if ((ft_strcmp(key, "WE") == 0))
		config->textures.we = value;
	else if ((ft_strcmp(key, "EA") == 0))
		config->textures.ea = value;
	else
	{
		error("Unknown map configuration key: %s", key);
		return (1);
	}
	return (0);
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
