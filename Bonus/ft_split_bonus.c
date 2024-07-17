/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:02:00 by hmraizik          #+#    #+#             */
/*   Updated: 2024/04/01 22:02:00 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_word(const char *s, char c)
{
	int	count;
	int	c_fond;

	count = 0;
	c_fond = 0;
	while (*s)
	{
		if (*s == c)
			c_fond = 0;
		else if (!c_fond && *s != c)
		{
			c_fond = 1;
			count++;
		}
		s++;
	}
	return (count);
}

char	**free_substrs(char **substrs)
{
	int	i;

	i = 0;
	while (substrs[i])
		free(substrs[i++]);
	free(substrs);
	return (0);
}

static int	word_len(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s && *(s++) != c)
		count++;
	return (count);
}

char	**ft_split(char const *s, char c, int i)
{
	char	**substrs;
	int		len;

	if (!s)
		return (NULL);
	substrs = malloc(((count_word(s, c) + 1) * sizeof(char *)));
	if (!substrs)
		return (NULL);
	if (!s[i])
		error();
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			len = word_len(s, c);
			substrs[i] = ft_substr(s, 0, len);
			if (!substrs[i++])
				return (free_substrs(substrs));
			s += len;
		}
	}
	substrs[i] = 0;
	return (substrs);
}
