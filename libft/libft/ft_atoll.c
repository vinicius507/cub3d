/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 03:07:48 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 15:29:25 by vgoncalv         ###   ########.fr       */
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

/**
 * @brief Converts the initial portion of the string `nptr` to a `long int`.
 * @param nptr
 * @return The `long int` representation of the inital portion of the string
 * `nptr`
 */
long long int	ft_atoll(const char *nptr)
{
	long long int	num;
	long long int	sign;

	while ((ft_isspace(*nptr)))
		nptr++;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	num = 0;
	while ((ft_isdigit(*nptr)))
	{
		num *= 10;
		num += sign * (*nptr - '0');
		nptr++;
	}
	return (num);
}
