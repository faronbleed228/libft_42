/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 14:29:31 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/22 16:58:48 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (len > 0)
	{
		*ptr = '\0';
		ptr++;
		len--;
	}
}
/*
int	main(void)
{
	char	str[6] = "Hello";
	int		i;
	char	c;

	i = 0;
	ft_bzero(str, 6);
	while (str[i])
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}
*/
