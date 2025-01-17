/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:01:38 by hmraizik          #+#    #+#             */
/*   Updated: 2024/04/06 20:43:38 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	tmp = head;
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
	int			current;
	int			next;

	tmp = head;
	while (tmp && tmp->next)
	{
		current = tmp->data;
		next = tmp->next->data;
		if (current < next)
			tmp = tmp->next;
		else if (current > next)
			return (0);
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

int	if_reverse(t_list **stack)
{
	t_list	*tmp;
	t_list	*tmp2;
	int		i;

	i = 0;
	tmp = (*stack);
	tmp2 = tmp;
	while (tmp)
	{
		if (tmp2->data < tmp->data)
			i++;
		tmp2 = tmp;
		tmp = tmp->next;
	}
	if (i > 40)
		return (1);
	return (0);
}
