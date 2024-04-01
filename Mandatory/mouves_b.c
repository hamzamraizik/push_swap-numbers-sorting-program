#include "push_swap.h"

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	write(1, "pb\n", 3);
}

void	ft_rb(t_list **stack_b)
{
	t_list	*tmp;

	if (lstsize((*stack_b)) < 2)
		return ;
	tmp = (*stack_b);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
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
	tmp = (*stack_b);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next->next = NULL;
	write(1, "rr\n", 3);
}

void	ft_rrb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*before_last;

	if (lstsize(*stack_b) < 2)
		return ;
	before_last = (*stack_b);
	tmp = (*stack_b);
	while (before_last->next->next)
		before_last = before_last->next;
	tmp = before_last->next;
	before_last->next = NULL;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	write(1, "rrb\n", 4);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*before_last;

	if (lstsize(*stack_a) < 2 || lstsize(*stack_b) < 2)
		return ;
	before_last = (*stack_a);
	tmp = (*stack_a);
	while (before_last->next->next)
		before_last = before_last->next;
	tmp = before_last->next;
	before_last->next = NULL;
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	before_last = (*stack_b);
	tmp = (*stack_b);
	while (before_last->next->next)
		before_last = before_last->next;
	tmp = before_last->next;
	before_last->next = NULL;
	tmp->next = (*stack_b);
	(*stack_b) = tmp;
	write(1, "rrr\n", 4);
}
