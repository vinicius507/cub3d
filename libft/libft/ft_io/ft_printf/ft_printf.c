/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 18:43:06 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 14:59:41 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft/ft_io.h>
#include <libft/ft_string.h>
#include <libft/ft_io/ft_printf.h>

/**
 * @brief Writes formatted string on STDOUT.
 * @param format The format string
 * @param ap The `va_list` of the specifiers values for the formatted output
 * @return On success, the number of characters written on STDOUT, else, -1
 */
int	ft_vprintf(const char *format, va_list ap)
{
	int	printed;

	printed = ft_vdprintf(STDOUT_FILENO, format, ap);
	return (printed);
}

/**
 * @brief Writes formatted string on STDOUT.
 * @param format The format string
 * @param ... The specifiers values for the formatted output
 * @return On success, the number of characters written on STDOUT, else, -1
 */
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		printed;

	va_start(ap, format);
	printed = ft_vprintf(format, ap);
	va_end(ap);
	return (printed);
}
