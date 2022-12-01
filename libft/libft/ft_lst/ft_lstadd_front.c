/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:28:42 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 16:19:38 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <libft/ft_lst.h>

/**
 * @brief Adds a `t_list` node to the start of the list.
 * @param lst A pointer to the linked list
 * @param new_node The new node
 */
void	ft_lstadd_front(t_list **lst, t_list *new_node)
{
	if (lst == NULL || new_node == NULL)
		return ;
	if (*lst != NULL)
	{
		new_node->next = *lst;
		(*lst)->prev = new_node;
	}
	*lst = new_node;
}
