#include "checker.h"

// indexing the values from smaller to the bigger
void	indexing(t_list **stack, t_list **new)
{
	t_list	*tmp;
	int		current;

	current = (*new)->data;
	tmp = (*stack);
	while (tmp)
	{
		if (current > tmp->data)
			(*new)->index += 1;
		else
			tmp->index += 1;
		tmp = tmp->next;
	}
}

t_list	*ft_lstnew(t_list **stack, int data)
{
	t_list	*new;

	new = NULL;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->data = data;
	new->index = 0;
	new->next = NULL;
	indexing(stack, &new);
	return (new);
}

// count the size of the list 
int	lstsize(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}
//add node to the back of the list

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = *alst;
	while ((tmp)->next)
		tmp = (tmp)->next;
	(tmp)->next = new;
	new->next = NULL;
}
