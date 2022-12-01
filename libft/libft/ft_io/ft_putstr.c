/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:46:38 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/21 18:00:42 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <libft/ft_string.h>

/**
 * @brief Writes a string on STDOUT.
 * @param s
 */
void	ft_putstr(char *s)
{
	size_t	size;

	if (s == NULL)
		return ;
	size = ft_strlen(s);
	(void)write(1, s, size);
}
