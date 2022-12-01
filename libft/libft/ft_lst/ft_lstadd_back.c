/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 14:44:58 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 16:13:46 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <libft/ft_lst.h>

/**
 * @brief Adds a `t_list` node to the end of the list.
 * @param lst A pointer to the linked list
 * @param new_node The new node
 */
void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*temp;

	if (lst == NULL || new_node == NULL)
		return ;
	if (*lst == NULL)
		*lst = new_node;
	else
	{
		temp = ft_lstlast(*lst);
		temp->next = new_node;
		new_node->prev = temp;
	}
}
