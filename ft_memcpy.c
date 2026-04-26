/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:20:03 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/22 17:53:45 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_tmp;
	const unsigned char	*src_tmp;

	dest_tmp = (unsigned char *)dest;
	src_tmp = (const unsigned char *)src;
	while (len > 0)
	{
		*dest_tmp++ = *src_tmp++;
		len--;
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[6] = "Hello";
	char	dest[6];
	int		i;
	char	c;

	i = 0;
	ft_memcpy(dest, src, 6);
	while(dest[i])
	{
		c = dest[i];
		write(1, &c, 1);
		i++;
	}
}
*/
