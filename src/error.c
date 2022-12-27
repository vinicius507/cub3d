/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:12:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/12/23 15:54:15 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	error(const char *msg, const char *detail)
{
	if (detail != NULL)
		ft_dprintf(2, "Error: %s: %s\n", msg, detail);
	else
		ft_dprintf(2, "Error: %s\n", msg);
}
