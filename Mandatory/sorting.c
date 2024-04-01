#include "push_swap.h"

void	positioning(t_list *stack)
{
	int		position;

	position = 0;
	while (stack)
	{
		stack->position = position;
		position++;
		stack = stack->next;
	}
}

int	the_biggest(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->data > stack->data)
			stack = tmp;
		tmp = tmp->next;
	}
	return (stack->position);
}

// the threshold , smaller threshold may
	//result in more frequent but smaller movements of elements to stack_b
		// big treshold may result fewwer but more movement;
void	semi_sorting(t_list **stack_a, t_list **stack_b)
{
	int	current_index;
	int	threshold;

	current_index = 0;
	while (*stack_a)
	{
		if (lstsize(*stack_a) <= 100)
			threshold = lstsize(*stack_a) / 5;
		else
			threshold = lstsize(*stack_a) / 8;
		if ((*stack_a)->index <= current_index)
		{
			ft_pb(stack_a, stack_b);
			current_index++;
		}
		else if ((*stack_a)->index <= current_index + threshold)
		{
			ft_pb(stack_a, stack_b);
			ft_rb(stack_b);
			current_index++;
		}
		else
			ft_ra(stack_a);
	}
}

void	last_sorting(t_list **stack_a, t_list **stack_b, int size, int i)
{
	size = lstsize(*stack_b) + 1;
	while (--size)
	{
		positioning(*stack_b);
		i = the_biggest(*stack_b);
		if (i <= size / 2)
		{
			while (i--)
				ft_rb(stack_b);
		}
		else
		{
			while (i++ < size)
				ft_rrb(stack_b);
		}
		ft_pa(stack_b, stack_a);
	}
}
