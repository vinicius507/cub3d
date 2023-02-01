/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:09:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/01/14 17:36:16 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	usage(const char *name)
{
	ft_dprintf(2,
		"Usage: %s MAP\n\n"
		"Positional Arguments:\n"
		"  MAP\n"
		"    A .cub file with the configuration for cub3d.\n",
		name);
}

char	arg_is_map_file(const char *filename)
{
	const char	*extension;

	extension = ft_strrchr(filename, '.');
	if (extension == NULL)
		return (0);
	return ((!ft_strcmp(extension, ".cub")));
}

char	*parse_args(int argc, char **argv)
{
	const char	*bin_path;
	const char	*map_filename;

	bin_path = argv[0];
	if (argc != 2)
	{
		errmsg("Wrong number of arguments");
		usage(bin_path);
		return (NULL);
	}
	map_filename = argv[1];
	if ((!arg_is_map_file(map_filename)))
	{
		errmsg("Config file should have a .cub extension.");
		usage(bin_path);
		return (NULL);
	}
	return (argv[1]);
}
