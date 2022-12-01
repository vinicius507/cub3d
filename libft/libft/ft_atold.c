/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:11:10 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 15:29:01 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libft/ft_ctype.h>

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\r'
		|| c == '\f' || c == '\v')
		return (1);
	return (0);
}

static long double	get_decimal(const char *nptr, int sign)
{
	long double	num;
	long double	decimal;

	num = 0;
	decimal = 0.1;
	if (*nptr && *nptr++ == '.')
	{
		while (*nptr && ft_isdigit(*nptr))
		{
			num += sign * (*nptr - '0') * decimal;
			decimal *= 0.1;
			nptr++;
		}
	}
	return (num);
}

/**
 * @brief Converts the initial portion of the string `nptr` to a `long double`.
 * @param nptr
 * @return The `long double` representation of the inital portion of the string
 * `nptr`
 */
long double	ft_atold(const char *nptr)
{
	long double	num;
	int			sign;

	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	num = 0;
	while (*nptr && ft_isdigit(*nptr))
	{
		num *= 10;
		num += sign * (*nptr - '0');
		nptr++;
	}
	num += get_decimal(nptr, sign);
	return (num);
}
