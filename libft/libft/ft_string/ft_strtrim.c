/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 15:01:19 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/21 18:28:55 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft/ft_string.h>

static int	contains(const char *set, const char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	get_limit(const char *str, const char *set)
{
	size_t	len;

	len = ft_strlen(str);
	while (len-- && contains(set, str[len]))
		;
	return (len + 1);
}

/**
 * @brief Trims a string of characters from `set`.
 * @param str The string to be trimmed
 * @param set The set of characters to be trimmed of the string
 * @return The allocated trimmed string
 */
char	*ft_strtrim(const char *str, const char *set)
{
	char	*res;
	size_t	limit;
	size_t	offset;

	if (str == NULL || set == NULL)
		return (NULL);
	while (contains(set, *str))
		str++;
	limit = get_limit(str, set);
	res = malloc(limit + 1);
	if (res == NULL)
		return (NULL);
	offset = 0;
	while (offset < limit)
	{
		res[offset] = str[offset];
		offset++;
	}
	res[offset] = '\0';
	return (res);
}
