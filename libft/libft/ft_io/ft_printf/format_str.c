/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:09:08 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 14:32:49 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_string.h>
#include <libft/ft_io/ft_printf.h>

char	*format_str(t_arg *arg, va_list ap)
{
	char	*str;
	char	*temp;

	temp = (char *)va_arg(ap, const char *);
	if (temp == NULL)
		str = ft_strdup("(null)");
	else
		str = ft_strdup(temp);
	if (str == NULL)
		return (NULL);
	if (apply_precision_str(&str, arg)
		|| apply_width(&str, arg))
		return (NULL);
	arg->printed += ft_strlen(str);
	return (str);
}
