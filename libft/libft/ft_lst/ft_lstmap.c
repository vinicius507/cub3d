/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgoncalv <vgoncalv@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 15:24:21 by vgoncalv          #+#    #+#             */
/*   Updated: 2022/09/05 16:12:39 by vgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <libft/ft_lst.h>

/**
 * @brief Iterates over a linked list and while applying the function `f` to
 * its content. It creates a new linked list with the modified content. The
 * `del` function is used to deallocate resources of each node's content should
 * there be an error.
 * @param lst The first node to iterate over
 * @param f The function that will be applied to the node's content
 * @param del The content deletion function for the nodes
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*first;

	first = NULL;
	while (lst != NULL)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		ft_lstadd_back(&first, temp);
		lst = lst->next;
	}
	return (first);
}
