/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 20:37:00 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:03:38 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_string.h>

/**
 * @brief Finds the last occurrence of the char `c` in the string `s`.
 * @param s
 * @param c
 * @return A pointer to the character in the string, if found, else, NULL
 */
char	*ft_strrchr(const char *s, int c)
{
	size_t			len;
	unsigned char	*s_u;
	unsigned char	c_u;

	len = ft_strlen(s) + 1;
	c_u = (unsigned char)c;
	s_u = (unsigned char *)s;
	while (len--)
	{
		if (s_u[len] == c_u)
			return ((char *)s + len);
	}
	return (NULL);
}
