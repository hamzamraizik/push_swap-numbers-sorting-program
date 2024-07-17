/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:36:46 by hmraizik          #+#    #+#             */
/*   Updated: 2024/03/28 03:21:01 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (str[i] != (char )c)
	{
		if (str[i] == '\0')
			return (NULL);
		i++;
	}
	return (str + i);
}

void	ft_free(char **x)
{
	free(*x);
	*x = NULL;
}

int	ft_strcmp(char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (-1);
		i++;
	}
	return (0);
}

void	joining(int argc, char **argv, char **res)
{
	int	i;

	i = 1;
	*res = NULL;
	while (i < argc)
	{
		if (!*(argv[i]) || check_spaces(argv[i]))
			error();
		*res = ft_strjoin(*res, argv[i]);
		i++;
	}
}
