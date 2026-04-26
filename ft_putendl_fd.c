/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 20:18:35 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/23 20:19:30 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	lenght;

	if (!s)
		return ;
	(lenght = ft_strlen(s));
	write(fd, s, lenght);
	write(fd, "\n", 1);
}
