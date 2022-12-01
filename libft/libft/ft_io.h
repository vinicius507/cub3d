/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_io.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:19:37 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/21 18:22:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_io.h
 * @author Vinícius Oliveira (vgoncalv)
 * @brief Provides functions for Input/Output operations.
 */

#ifndef FT_IO_H
# define FT_IO_H

# include <stdarg.h>

# ifdef __linux__
#  define NULL_STR "(nil)"
# elif defined(__APPLE__)
#  define NULL_STR "0x0"
# else
#  define NULL_STR "(null)"
# endif

void	ft_putchar(char c);

void	ft_putchar_fd(char c, int fd);

void	ft_putstr(char *s);

void	ft_putstr_fd(char *s, int fd);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr(int s);

void	ft_putnbr_fd(int s, int fd);

int		ft_printf(const char *str, ...);

int		ft_vprintf(const char *format, va_list ap);

int		ft_dprintf(int fd, const char *format, ...);

int		ft_vdprintf(int fd, const char *format, va_list ap);

int		ft_sprintf(char *buf, const char *format, ...);

int		ft_vsprintf(char *buf, const char *format, va_list ap);

int		ft_vasprintf(char **buf, const char *format, va_list ap);

int		ft_asprintf(char **buf, const char *format, ...);

int		get_next_line(int fd, char **line);

#endif
