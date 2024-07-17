/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:01:25 by hmraizik          #+#    #+#             */
/*   Updated: 2024/04/04 21:38:27 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*get_max_number(t_list *stack)
{
	t_list	*tmp;
	t_list	*max;

	tmp = stack;
	max = tmp;
	while (tmp)
	{
		if (tmp->data > max->data)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

void	sort_three(t_list **lst)
{
	t_list	*max;

	if ((lstsize((*lst)) == 2))
		ft_sa(lst);
	else
	{
		if (!check_sorted(*lst))
		{
			max = get_max_number(*lst);
			if (max->data == (*lst)->data)
				ft_ra(lst);
			else if (max->data == (*lst)->next->data)
				ft_rra(lst);
			if ((*lst)->data > (*lst)->next->data)
				ft_sa(lst);
		}
	}
	return ;
}
