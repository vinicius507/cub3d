/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:41:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/21 18:28:46 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/ft_string.h>

/**
 * @brief Joins two strings.
 * @param s1
 * @param s2
 * @return The joined strings
 */
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*res;
	size_t	offset;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(len + 1);
	if (res == NULL)
		return (NULL);
	offset = 0;
	while (*s1)
		res[offset++] = *s1++;
	while (*s2)
		res[offset++] = *s2++;
	res[offset] = '\0';
	return (res);
}
