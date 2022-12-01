/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 13:21:54 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 15:44:11 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <libft/ft_mem.h>

/**
 * @brief Converts an `unsigned long long int` value `n` to a
 * string.
 * @param n
 * @return The string form of the `unsigned long long int`
 * value `n`
 */
char	*ft_ulltoa(unsigned long long int n)
{
	unsigned long long int		temp;
	char						*num;
	size_t						size;

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
