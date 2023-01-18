/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:34:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/01/18 08:11:18 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "config/config.h"
#include "error.h"
#include "cub3d.h"

void	teardown(t_config *config)
{
	config_teardown(config);
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
	if ((load_config(config_path, &config) != 0))
	{
		teardown(&config);
		exit(EXIT_FAILURE);
	}
	ft_printf("config.no=%s\n", config.no);
	ft_printf("config.so=%s\n", config.so);
	ft_printf("config.we=%s\n", config.we);
	ft_printf("config.ea=%s\n", config.ea);
	ft_printf("config.floor=%s\n", config.floor);
	ft_printf("config.ceiling=%s\n", config.ceiling);
	ft_printf("config.map_lines:\n--START--\n'%s'\n--END--\n", config.map_lines);
	teardown(&config);
	return (EXIT_SUCCESS);
}
