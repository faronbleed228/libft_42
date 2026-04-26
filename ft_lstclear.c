/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 11:45:45 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/24 16:02:51 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*prev;

	if (!lst || !del)
		return ;
	current = *lst;
	while (current != NULL)
	{
		del(current->content);
		prev = current;
		current = current->next;
		free(prev);
	}
	*lst = NULL;
}
