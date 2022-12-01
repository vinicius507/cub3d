/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 17:42:09 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 15:01:22 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft/ft_string.h>

/**
 * @brief Compares two strings.
 * @param s1
 * @param s2
 * @return A non-zero value if the strings differ
 */
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t			offset;
	unsigned char	*s1_u;
	unsigned char	*s2_u;

	offset = 0;
	s1_u = (unsigned char *)s1;
	s2_u = (unsigned char *)s2;
	while (s1_u[offset] != '\0' && s2_u[offset] != '\0')
	{
		if (s1_u[offset] != s2_u[offset])
			break ;
		offset++;
	}
	return (s1_u[offset] - s2_u[offset]);
}
