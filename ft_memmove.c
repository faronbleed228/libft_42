/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 15:58:22 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/22 16:55:40 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_tmp;
	const unsigned char	*src_tmp;

	dest_tmp = (unsigned char *)dest;
	src_tmp = (const unsigned char *)src;
	if (dest < src)
	{
		ft_memcpy(dest, src, len);
		return (dest);
	}
	while (len > 0)
	{
		len--;
		*(dest_tmp + len) = *(src_tmp + len);
	}
	return (dest);
}
/*
int	main(void)
{
	char	src[6] = "1234";
	char	*dest;
	char	c;

	dest = ft_memmove(&src[1], src, 4);
	while (*dest)
	{
		c = *dest;
		write(1, &c, 1);
		dest++;
	}
}
*/
