/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ypopovyc <@student.42vienna.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:13:48 by ypopovyc          #+#    #+#             */
/*   Updated: 2026/04/26 12:06:32 by ypopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	words;
	int	in_word;

	in_word = 0;
	words = 0;
	while (*s)
	{
		if (*s != c && in_word == 0)
		{
			in_word = 1;
			words++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (words);
}

char	**ft_free(char **ptr, int i)
{
	while (i > 0)
	{
		free(ptr[--i]);
	}
	free(ptr);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		start;
	int		end;
	int		i;

	i = 0;
	end = 0;
	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!ptr)
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		while (s[end] == c && s[end])
			end++;
		start = end;
		while (s[end] != c && s[end])
			end++;
		ptr[i] = ft_substr(s, start, end - start);
		if (!ptr[i++])
			return (ft_free(ptr, i - 1));
	}
	ptr[i] = NULL;
	return (ptr);
}
