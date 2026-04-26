/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 19:06:26 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/22 19:15:05 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = 0;
	while (dst_len < size && dst[dst_len])
		dst_len++;
	i = 0;
	if (size <= dst_len)
		return (size + src_len);
	while (dst_len + i + 1 < size && src[i])
	{
		dst[i + dst_len] = src[i];
		i++;
	}
	dst[i + dst_len] = '\0';
	return (src_len + dst_len);
}
/*
int	main(void)
{
	char	src[6] = "Hello";
	char	dest[20] = "World";
	int		total;

	total = ft_strlcat(dest, src, 20);
	printf("%i\n", total);
	printf("%s", dest);
}
*/
