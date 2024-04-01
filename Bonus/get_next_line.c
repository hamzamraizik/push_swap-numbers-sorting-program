/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 15:37:18 by hmraizik          #+#    #+#             */
/*   Updated: 2024/03/28 02:07:40 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

char	*ft_sdup(const char *s1)
{
	size_t	len;
	char	*s2;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 1;
	s2 = malloc(len);
	if (!s2 || !s1)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static char	*ft_join(char *s1, char *s2)
{
	char		*str;
	size_t		s1_len;
	size_t		s2_len;
	size_t		i;

	i = 0;
	if (!s1)
		return (free(s1), s1 = NULL, NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!str)
		return (free(s1), free(s2), NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		str[s1_len++] = s2[i++];
	str[s1_len] = '\0';
	free(s1);
	return (str);
}

static int	check(const char *s)
{
	int	i;

	i = 0;
	while (*s && *s != '\n')
	{
		i++;
		++s;
	}
	return (i);
}

static char	*get_read(int fd, char *line)
{
	char		*buff;
	int			count;

	buff = malloc((size_t)BUFFER_SIZE + 1);
	if (!buff)
		return (free(line), NULL);
	if (!line)
		line = ft_sdup("");
	while (!(ft_strchr(line, '\n')))
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == 0)
			break ;
		if (count == -1)
			return (free(line), free(buff), NULL);
		buff[count] = '\0';
		line = ft_join(line, buff);
	}
	ft_free(&buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*str;
	char		*tmp;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1
		|| BUFFER_SIZE > INT_MAX || fd > OPEN_MAX)
	{
		if (line)
			ft_free(&line);
		return (NULL);
	}
	line = get_read(fd, line);
	if (!(*line))
	{
		ft_free(&line);
		return (NULL);
	}
	i = check(line) + 1;
	str = ft_substr(line, 0, i);
	tmp = line;
	line = ft_substr(line, i, ft_strlen(line) - i + 1);
	ft_free(&tmp);
	return (str);
}
