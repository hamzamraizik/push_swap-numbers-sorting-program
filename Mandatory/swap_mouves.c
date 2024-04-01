#include "push_swap.h"

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (lstsize(*stack_a) < 2 || lstsize(*stack_b) < 2)
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	tmp2 = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp2->next = (*stack_b)->next;
	(*stack_b)->next = tmp2;
	write(1, "ss\n", 3);
}

void	ft_sa(t_list **stack_a)
{
	t_list	*tmp;

	if (lstsize(*stack_a) < 2)
		return ;
	tmp = (*stack_a);
	(*stack_a) = (*stack_a)->next;
	tmp->next = (*stack_a)->next;
	(*stack_a)->next = tmp;
	write(1, "sa\n", 3);
}

void	ft_sb(t_list **stack_b)
{
	t_list	*tmp;

	if (lstsize(*stack_b) < 2)
		return ;
	tmp = (*stack_b);
	(*stack_b) = (*stack_b)->next;
	tmp->next = (*stack_b)->next;
	(*stack_b)->next = tmp;
	write(1, "sb\n", 3);
}
