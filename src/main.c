/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:34:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/27 15:03:51 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <cub3d.h>

void	teardown(t_config *config)
{
	teardown_config(config);
}

// TODO init projection
// TODO free memory when done
int	main(int argc, char **argv)
{
	t_config	config;
	const char	*config_path;

	ft_bzero(&config, sizeof(t_config));
	config_path = parse_args(argc, argv);
	if (config_path == NULL)
		exit(EXIT_FAILURE);
	if ((load_map_config(config_path, &config) != 0))
		exit(EXIT_FAILURE);
	ft_printf("no: %s\n", config.textures.no);
	ft_printf("so: %s\n", config.textures.so);
	ft_printf("we: %s\n", config.textures.we);
	ft_printf("ea: %s\n", config.textures.ea);
	teardown(&config);
	return (EXIT_SUCCESS);
}
