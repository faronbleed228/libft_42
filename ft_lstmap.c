/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:05:39 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/24 16:45:04 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*tmp_lst;

	new_lst = NULL;
	while (lst != NULL)
	{
		tmp_lst = ft_lstnew(f(lst->content));
		if (!tmp_lst)
		{
			del(tmp_lst->content);
			free(tmp_lst);
			ft_lstclear(&new_lst, del);
			free(new_lst);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, tmp_lst);
		lst = lst->next;
	}
	return (new_lst);
}
