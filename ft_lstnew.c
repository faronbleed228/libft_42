/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 10:32:04 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/24 10:37:52 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*s_ptr;

	s_ptr = malloc(sizeof(t_list));
	if (!s_ptr)
		return (NULL);
	s_ptr->content = content;
	s_ptr->next = NULL;
	return (s_ptr);
}
