/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:27:37 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 14:58:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft/ft_string.h>
#include <libft/ft_io/ft_printf.h>

/**
 * @brief Writes formatted string on a file descriptor.
 * @param fd The file descriptor to be written
 * @param format The format string
 * @param ap The `va_list` of the specifiers values for the formatted output
 * @return On success, the number of characters written on the file
 * descriptor, else, -1
 */
int	ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_arg	arg;
	char	*buf;
	char	*var;

	buf = ft_strdup(format);
	var = ft_strchr(buf, '%');
	arg.printed = 0;
	while (var != NULL)
	{
		arg.printed = var - buf;
		if (arg_parser(&arg, &var, ap) || format_current(&arg, &buf, var, ap))
		{
			arg.printed = FT_PRINTF_ERROR;
			break ;
		}
		var = ft_strchr(buf + arg.printed, '%');
	}
	if (arg.printed != FT_PRINTF_ERROR)
	{
		arg.printed += ft_strlen(buf + arg.printed);
		(void)write(fd, buf, arg.printed);
		free(buf);
	}
	return (arg.printed);
}

/**
 * @brief Writes formatted string on a file descriptor.
 * @param fd The file descriptor to be written
 * @param format The format string
 * @param ... The specifiers values for the formatted output
 * @return On success, the number of characters written on the file
 * descriptor, else, -1
 */
int	ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		printed;

	printed = 0;
	va_start(ap, format);
	printed = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (printed);
}
