/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:34:02 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/04/01 20:02:37 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	cub;
	char	*config_path;

	ft_bzero(&cub, sizeof(t_cub));
	config_path = parse_args(argc, argv);
	if ((cub_load_config(&cub, config_path) != 0))
	{
		cub_exit(&cub);
		return (EXIT_FAILURE);
	}
	cub_init(&cub);
	return (EXIT_SUCCESS);
}
