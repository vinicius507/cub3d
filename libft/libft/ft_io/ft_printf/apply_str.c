/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:09:44 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 14:30:53 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libft/ft_string.h>
#include <libft/ft_io/ft_printf.h>

int	apply_precision_str(char **str, t_arg *arg)
{
	char	*res;

	if (arg->precision < 0)
		return (0);
	res = ft_substr(*str, 0, arg->precision);
	safe_free((void **)str);
	*str = res;
	if (*str == NULL)
		return (FT_PRINTF_ERROR);
	return (0);
}
