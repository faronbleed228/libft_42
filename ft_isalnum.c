/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:26:06 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/26 11:25:16 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isdigit(c) || ft_isalpha(c));
}
/*
int	main(void)
{
	char	c;
	int		result;

	c = '8';
	result = ft_isalnum(c);
	if (result == 1)
		write(1, "true", 4);
	else
		write(1, "false", 5);
}
*/
