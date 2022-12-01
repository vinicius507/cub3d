/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 12:33:09 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 15:38:37 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libft/ft_mem.h>

/**
 * @brief Converts an `unsigned int` value `n` to a string.
 * @param n
 * @return The string form of the `unsigned int` value `n`
 */
char	*ft_uitoa(unsigned int n)
{
	unsigned int		temp;
	char				*num;
	size_t				size;

	size = 1;
	temp = n / 10;
	while (temp)
	{
		size++;
		temp /= 10;
	}
	num = ft_calloc(size + 1, sizeof(char));
	if (num == NULL)
		return (NULL);
	while (size--)
	{
		num[size] = (n % 10) + '0';
		n /= 10;
	}
	return (num);
}
