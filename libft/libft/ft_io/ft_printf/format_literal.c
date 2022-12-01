/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_literal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 19:25:36 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 14:32:14 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_string.h>
#include <libft/ft_io/ft_printf.h>

char	*format_literal(t_arg *arg)
{
	char		*str;

	str = ft_strdup("%");
	if (str == NULL)
		return (NULL);
	if (apply_width_literal(&str, arg))
		return (NULL);
	arg->printed += ft_strlen(str);
	return (str);
}
