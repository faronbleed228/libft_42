/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:28:26 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/23 20:33:29 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int n)
{
	int	lenght;

	lenght = 0;
	if (n == 0 || n < 0)
		lenght++;
	while (n)
	{
		lenght++;
		n /= 10;
	}
	return (lenght);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		lenght;
	char	*ptr;

	nb = n;
	lenght = ft_intlen(n);
	ptr = malloc(lenght + 1);
	if (!ptr)
		return (NULL);
	if (nb == 0)
		ptr[0] = '0';
	ptr[lenght] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		ptr[0] = '-';
	}
	while (nb > 0)
	{
		ptr[--lenght] = (nb % 10) + 48;
		nb /= 10;
	}
	return (ptr);
}
