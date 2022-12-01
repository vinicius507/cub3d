/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 14:52:52 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/21 18:30:48 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/ft_string.h>

/**
 * @brief Iterates over a string and creates a "translated" copy of it.
 * @param s The string to be iterated
 * @param f A function that receives a character of the string and
 * returns its "translated" value
 * @return The new allocated tranlated string
 */
char	*ft_striter(const char *s, int (*f)(int))
{
	char	*res;
	size_t	size;
	size_t	offset;

	if (s == NULL)
		return (NULL);
	size = ft_strlen(s);
	res = malloc(size + 1);
	if (res == NULL)
		return (NULL);
	offset = 0;
	while (offset < size)
	{
		res[offset] = (char)f(s[offset]);
		offset++;
	}
	res[offset] = '\0';
	return (res);
}
