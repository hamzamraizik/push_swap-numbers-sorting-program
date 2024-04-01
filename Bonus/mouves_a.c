#include "checker.h"

void	ft_pa(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (!(*stack_b))
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = *stack_a;
	*stack_a = tmp;
}
// ____________________________________

void	ft_ra(t_list **stack_a)
{
	t_list	*tmp;

	tmp = (*stack_a);
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next->next = NULL;
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
}