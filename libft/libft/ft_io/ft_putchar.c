/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 15:30:55 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/04 14:59:19 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft/ft_io.h>

/**
 * @brief Writes a character on STDOUT.
 * @param c
 */
void	ft_putchar(char c)
{
	(void)write(1, &c, 1);
}
