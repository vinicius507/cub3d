/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:02:26 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/11/29 12:31:39 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file libft.h
 * @author Vinícius Oliveira (vgoncalv)
 * @brief This is my Libft. A general purpose library meant for usage within
 * École 42.
 */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

# include <libft/ft_io.h>
# include <libft/ft_lst.h>
# include <libft/ft_mem.h>
# include <libft/ft_ctype.h>
# include <libft/ft_string.h>

int			ft_atoi(const char *nptr);

long long	ft_atoll(const char *nptr);

long double	ft_atold(const char *nptr);

char		*ft_itoa(int n);

char		*ft_ltoa(long int n);

char		*ft_lltoa(long long int n);

char		*ft_ldtoa(long double n, size_t precision);

char		*ft_uitoa(unsigned int n);

char		*ft_ultoa(unsigned long int n);

char		*ft_ulltoa(unsigned long long int n);

char		*ft_itoa_base(int n, char *base);

char		*ft_ltoa_base(long int n, char *base);

char		*ft_lltoa_base(long long int n, char *base);

char		*ft_uitoa_base(unsigned int n, char *base);

char		*ft_ultoa_base(unsigned long int n, char *base);

char		*ft_ulltoa_base(unsigned long long int n, char *base);

uint		ft_abs(int n);

#endif
