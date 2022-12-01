/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 17:16:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:01:14 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_string.h>

/**
 * @brief Finds the first occurrence of `c` in the string `s`.
 * @param s
 * @param c
 * @return A pointer to the character, if found, else NULL
 */
char	*ft_strchr(const char *s, int c)
{
	unsigned char	*s_u;
	unsigned char	c_u;

	s_u = (unsigned char *)s;
	c_u = (unsigned char)c;
	if (*s_u == c_u)
		return ((char *)s_u);
	while (*s_u++)
	{
		if (*s_u == c_u)
			return ((char *)s_u);
	}
	return (NULL);
}
