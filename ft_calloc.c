/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 22:25:06 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/23 09:53:21 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*ptr;
	size_t	max;

	max = -1;
	if (nelem == 0 || elsize == 0)
	{
		ptr = malloc(1);
		return (ptr);
	}
	if (elsize != 0 && nelem > max / elsize)
		return (NULL);
	ptr = malloc(elsize * nelem);
	if (ptr != NULL)
		ft_memset(ptr, 0, elsize * nelem);
	return (ptr);
}
