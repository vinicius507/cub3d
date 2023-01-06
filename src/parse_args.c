/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:09:41 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/01/05 18:48:28 by lufelip2         ###   ########.fr       */
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
		print_error("wrong number of arguments");
		usage(bin_path);
		return (NULL);
	}
	map_filename = argv[1];
	if ((!arg_is_map_file(map_filename)))
	{
		print_error("map file should have a .cub extension");
		usage(bin_path);
		return (NULL);
	}
	return (argv[1]);
}
