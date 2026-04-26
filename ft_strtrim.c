/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 09:54:24 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/26 11:45:03 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		min;
	int		max;
	int		i;
	char	*ptr;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	min = 0;
	max = ft_strlen(s1);
	while (ft_strchr(set, s1[min]) && min < max)
		min++;
	while (ft_strchr(set, s1[max - 1]) && max > min)
		max--;
	ptr = malloc(max - min + 1);
	if (!ptr)
		return (NULL);
	while (min < max)
		ptr[i++] = s1[min++];
	ptr[i] = '\0';
	return (ptr);
}
/*int	main(void)
{
	char	*str;

	str = ft_strtrim("123123", "1234553");
	printf("%s", str);
}*/
