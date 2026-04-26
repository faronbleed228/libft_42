/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/20 12:18:12 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/26 11:44:56 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
/*
int	main(void)
{
	char	c;
	int		result;

	c = '4';
	result = ft_isdigit(c);
	if (result == 1)
		write(1, "Num", 3);
	else
		write(1, "Not a num", 9);
}
*/
