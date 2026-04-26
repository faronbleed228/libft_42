/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 16:25:40 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/22 21:11:39 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		size;
	char	*ptr;

	size = ft_strlen(s);
	ptr = malloc(sizeof(char) * size + 1);
	if (!ptr)
		return (NULL);
	while (size >= 0)
	{
		ptr[size] = s[size];
		size--;
	}
	return (ptr);
}

/*int	main(void)
{
	char	*ptr;

	ptr = ft_strdup("Hello World");
	if (ptr != NULL)
	{
		printf("%s\n", ptr);
		free(ptr);
	}
}*/
