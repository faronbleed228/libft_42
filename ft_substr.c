/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/22 20:30:13 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/23 16:28:47 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	total_len;

	if (!s)
		return (NULL);
	total_len = ft_strlen(s);
	if (total_len < start)
		return (ft_strdup(""));
	if (total_len - start < len)
		len = total_len - start;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s[start], len + 1);
	return (str);
}
