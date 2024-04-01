#include "checker.h"

size_t	ft_strlen(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		count += 1;
		i++;
	}
	return (count);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!src && !dest)
		return (NULL);
	if (dest != src)
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_len;
	int		s2_len;
	int		i;

	i = 0;
	if (!s1)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_len + s2_len + 2));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
		str[s1_len++] = s2[i++];
	str[s1_len++] = ' ';
	str[s1_len] = '\0';
	free((void *)s1);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*s2;
	int		i;

	i = 0;
	len = ft_strlen(s1) + 2;
	s2 = malloc(len);
	if (!s2 || !s1)
		return (NULL);
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i++] = ' ';
	s2[i] = '\0';
	return (s2);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	if (start > (unsigned int)ft_strlen(s) || *s == '\0')
	{
		substr = malloc(1);
		if (!substr)
			return (NULL);
		substr[i] = '\0';
		return (substr);
	}
	if (len > ft_strlen(s) - (size_t)start)
		len = ft_strlen(s) - (size_t)start;
	substr = malloc(1 * len + 1);
	if (!substr)
		return (NULL);
	i--;
	while (++i < len)
		substr[i] = s[start + i];
	substr[i] = '\0';
	return (substr);
}
