#include "push_swap.h"

void	storing(t_list **stack_a, char **res2)
{
	int		num;
	int		i;

	i = 1;
	(*stack_a)->index = 0;
	while (res2[i])
	{
		num = ft_atoi(res2[i], 0);
		check_duplicated(*stack_a, num);
		ft_lstadd_back((stack_a), ft_lstnew(stack_a, num));
		i++;
	}
	free_substrs(res2);
	if (check_sorted(*stack_a) == 1)
		exit(0);
}

void	joining(int argc, char **argv, char **res)
{
	int	i;

	i = 1;
	*res = NULL;
	while (i < argc)
	{
		if (!*(argv[i]) || check_spaces(argv[i]))
			error();
		*res = ft_strjoin(*res, argv[i]);
		i++;
	}
}

void	process(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	char		*res;
	char		**res2;

	(*stack_a) = NULL;
	(*stack_b) = NULL;
	if (argc == 1)
		exit(0);
	joining(argc, argv, &res);
	res2 = ft_split(res, ' ', 0);
	if (!res2)
		return ;
	(*stack_a) = ft_lstnew(stack_a, ft_atoi((res2[0]), 0));
	storing(stack_a, res2);
	if ((lstsize((*stack_a)) == 2))
		ft_sa(stack_a);
	else if (lstsize((*stack_a)) == 3)
		sort_three(stack_a);
	else if (lstsize((*stack_a)) <= 5)
		sort5(&(*stack_a), stack_b);
	else
	{
		semi_sorting(stack_a, stack_b);
		last_sorting(stack_a, stack_b, 0, 0);
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	process(argc, argv, &stack_a, &stack_b);
	return (0);
}
