/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouves_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:00:57 by hmraizik          #+#    #+#             */
/*   Updated: 2024/04/03 09:10:41 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (lstsize((*stack_b)) < 1)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
	write(1, "pa\n", 3);
}
// ____________________________________

void	ft_ra(t_list **stack_a)
{
	t_list	*tmp;

	if (lstsize((*stack_a)) < 2)
		return ;
	tmp = (*stack_a);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*before_last;

	if (lstsize(*stack_a) < 2)
		return ;
	before_last = (*stack_a);
	tmp = (*stack_a);
	while (before_last->next->next)
		before_last = before_last->next;
	tmp = before_last->next;
	before_last->next = NULL;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	write(1, "rra\n", 4);
}
