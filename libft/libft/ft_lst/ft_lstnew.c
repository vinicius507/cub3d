/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:26:27 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 16:00:44 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <libft/ft_mem.h>
#include <libft/ft_lst.h>

/**
 * @brief Creates a new `t_list` node.
 * @param content A pointer to the content of the node
 * @return The allocated  `t_list` node
 */
t_list	*ft_lstnew(void *content)
{
	t_list	*item;

	item = ft_calloc(1, sizeof(t_list));
	if (item == NULL)
		return (NULL);
	item->content = content;
	return (item);
}
