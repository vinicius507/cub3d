/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:34:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/04/06 16:21:59 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;
	char	*config_path;

	ft_bzero(&cub, sizeof(t_cub));
	config_path = parse_args(argc, argv);
	if (config_path == NULL)
	{
		errmsg("Missing required argument MAP");
		return (EXIT_FAILURE);
	}
	if ((cub_load_config(&cub, config_path) != 0))
	{
		cub_exit(&cub);
		return (EXIT_FAILURE);
	}
	cub_init(&cub);
	return (EXIT_SUCCESS);
}
