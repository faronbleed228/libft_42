/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 13:55:51 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/22 16:55:28 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned char	*copy;

	copy = (unsigned char *)str;
	while (len > 0)
	{
		*copy = (unsigned char)c;
		len--;
		copy++;
	}
	return (str);
}
/*
int	main(void)
{
	char let = 'a';
	char c;
	char str[12] = "Hello World";
	char *result = ft_memset(&str, let, 5);
	while(*result)
	{
		c = *result;
		write(1, &c, 1);
		result++;
	}
}*/
