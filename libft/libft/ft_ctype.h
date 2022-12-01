/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:10:59 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/21 18:22:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_ctype.h
 * @author Vinícius Oliveira (vgoncalv)
 * @brief Provides character testing functions.
 */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

int	ft_isalpha(int c);

int	ft_isdigit(int c);

int	ft_isalnum(int c);

int	ft_isascii(int c);

int	ft_isprint(int c);

int	ft_tolower(int c);

int	ft_toupper(int c);

#endif
