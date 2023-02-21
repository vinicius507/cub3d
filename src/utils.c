/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:01:33 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/02/21 12:02:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_str_array(char **config)
{
	size_t	i;

	if (config == NULL)
		return ;
	i = 0;
	while (config[i] != NULL)
		free(config[i++]);
	free(config);
}
