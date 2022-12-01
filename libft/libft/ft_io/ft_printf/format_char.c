/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:22:27 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 16:21:14 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libft/ft_mem.h>
#include <libft/ft_string.h>
#include <libft/ft_io/ft_printf.h>

char	*format_char(t_arg *arg, va_list ap)
{
	char	*res;

	res = ft_calloc(2, sizeof(char));
	res[0] = (unsigned char)va_arg(ap, int);
	if (apply_width_char(&res, arg))
		return (NULL);
	if (arg->width > 0)
		arg->printed += arg->width;
	else
		arg->printed += 1;
	return (res);
}
