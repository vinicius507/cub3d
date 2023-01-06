/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lufelip2 <lufelip2@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:12:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2023/01/05 19:21:55 by lufelip2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_err	error(const char *msg)
{
	return (ft_strdup(msg));
}

t_err	error_from(const char *msg, t_err err_from)
{
	t_err	err;

	if (err_from == NULL)
		return (NULL);
	ft_asprintf((char **)&err, "%s: %s", msg, err_from);
	return (err);
}

void	print_error(t_err err)
{
	ft_dprintf(2, "cub3d: %s\n", err);
}
