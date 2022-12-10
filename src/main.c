/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:34:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/10 16:35:47 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <cub3d.h>

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
	return (EXIT_SUCCESS);
}
