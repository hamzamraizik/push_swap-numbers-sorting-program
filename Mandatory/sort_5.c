/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:01:19 by hmraizik          #+#    #+#             */
/*   Updated: 2024/04/01 22:01:19 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->data < stack->data)
			stack = tmp;
		tmp = tmp->next;
	}
	return (stack->position);
}

void	sort5(t_list **stack, t_list **stack_b)
{
	int		i;

	positioning(*stack);
	while (lstsize(*stack) > 3)
	{
		i = find_min_index(*stack);
		if (i <= 3)
		{
			while ((*stack)->position != i)
				ft_ra(stack);
		}
		else if (i > 3)
		{
			while ((*stack)->position != i)
				ft_rra(stack);
		}
		ft_pb(stack, stack_b);
	}
	sort_three(stack);
	ft_pa(stack_b, stack);
	ft_pa(stack_b, stack);
}
