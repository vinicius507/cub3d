/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mem.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:11:28 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/21 18:22:26 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_mem.h
 * @author Vinícius Oliveira (vgoncalv)
 * @brief Provides functions for memory manipulation.
 */

#ifndef FT_MEM_H
# define FT_MEM_H

# include <stddef.h>

void	*ft_calloc(size_t nmemb, size_t size);

void	*ft_memset(void *s, int c, size_t n);

void	ft_bzero(void *s, size_t n);

void	*ft_memcpy(void *dest, const void *src, size_t n);

void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

void	*ft_memmove(void *dest, const void *src, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memjoin(const void *m1, const void *m2,
			size_t size1, size_t size2);

#endif
