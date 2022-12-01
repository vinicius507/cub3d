/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 14:41:47 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/21 18:29:15 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/ft_string.h>

/**
 * @brief Maps a funtion to a string and returns the resulting string.
 * @param s: The string to be mapped
 * @param f The map function to build the new string
 * @return The allocated new string
 */
char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
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
		res[offset] = f(offset, s[offset]);
		offset++;
	}
	res[offset] = '\0';
	return (res);
}
