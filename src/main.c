/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:34:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/27 16:32:43 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "cub3d.h"
#include "error.h"

void	teardown(t_config *config)
{
	teardown_config(config);
}

// TODO init projection
// TODO free memory when done
int	main(int argc, char **argv)
{
	t_err		err;
	t_config	config;
	const char	*config_path;

	ft_bzero(&config, sizeof(t_config));
	config_path = parse_args(argc, argv);
	if (config_path == NULL)
		exit(EXIT_FAILURE);
	err = load_map_config(config_path, &config);
	if (err != NULL)
	{
		print_error(err);
		teardown(&config);
		exit(EXIT_FAILURE);
	}
	ft_printf("config.no=%s\n", config.no);
	ft_printf("config.so=%s\n", config.so);
	ft_printf("config.we=%s\n", config.we);
	ft_printf("config.ea=%s\n", config.ea);
	ft_printf("config.floor=%#x\n", config.floor);
	ft_printf("config.ceiling=%#x\n", config.ceiling);
	teardown(&config);
	return (EXIT_SUCCESS);
}
