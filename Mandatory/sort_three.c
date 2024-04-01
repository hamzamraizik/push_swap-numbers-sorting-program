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
	return ;
}
