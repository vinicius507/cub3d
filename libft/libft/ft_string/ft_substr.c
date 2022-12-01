/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 17:57:04 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/21 18:28:33 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/ft_string.h>

/**
 * @brief Retrieves a substring of the string `s`.
 * @param s
 * @param start The starting index of the substring
 * @param len The length of the substring
 * @return The allocated substring
 */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	size;
	size_t	m_size;
	size_t	s_start;

	if (s == NULL)
		return (NULL);
	s_start = start;
	size = ft_strlen(s);
	if (start > size)
	{
		m_size = 1;
		s_start = 0;
	}
	else if (start + len > size)
		m_size = size - start + 1;
	else
		m_size = len + 1;
	sub = malloc(m_size);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + s_start, m_size);
	return (sub);
}
