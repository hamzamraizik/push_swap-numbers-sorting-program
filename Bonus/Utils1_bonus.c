/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:02:27 by hmraizik          #+#    #+#             */
/*   Updated: 2024/04/01 22:02:27 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	check_char(const char *s)
{
	if (s)
	{
		while (*s)
		{
			if (!(ft_isspace(*s)) && !(ft_isdigit(*s))
				&& *s != '-' && *s != '+')
			{
				if ((*s == '-' || *s == '+') && *(s++) == '\0')
					error();
				error();
			}
			else
				s++;
		}
	}
}

void	check_duplicated(t_list *head, int x)
{
	t_list		*tmp;
	int			current;

	tmp = head->next;
	while (tmp)
	{
		current = tmp->data;
		if (x == current)
			error();
		tmp = tmp->next;
	}
}

int	check_sorted(t_list *head)
{
	t_list		*tmp;

	tmp = head;
	while (tmp->next)
	{
		if (tmp->next->data < tmp->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_spaces(const char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
	{
		i++;
		if (!s[i])
			return (1);
	}
	return (0);
}
