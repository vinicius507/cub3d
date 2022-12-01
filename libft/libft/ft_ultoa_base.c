/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 17:08:46 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 15:43:38 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libft/ft_mem.h>
#include <libft/ft_string.h>

static int	get_int_base(char *base)
{
	int	int_base;

	int_base = 0;
	while (*base)
	{
		if (ft_strchr(base + 1, *base))
			return (0);
		base++;
		int_base++;
	}
	if (int_base <= 1)
		return (0);
	return (int_base);
}

/**
 * @brief Converts a `unsigned long int` value `n` to a
 * string using the string base `base`.
 * @param n
 * @param base A string with the characters representing the base. The numeric
 * base is the the number of characters in it.
 * @return The string form of the `unsigned long int` value
 * `n` in its `base` form
 */
char	*ft_ultoa_base(unsigned long int n, char *base)
{
	char					*res;
	int						int_base;
	unsigned long int		counter;
	size_t					size;

	int_base = get_int_base(base);
	if (!int_base)
		return (NULL);
	size = 1;
	counter = n / int_base;
	while (counter)
	{
		size++;
		counter /= int_base;
	}
	res = ft_calloc(size + 1, sizeof(char));
	while (size--)
	{
		res[size] = base[(n % int_base)];
		n /= int_base;
	}
	return (res);
}
