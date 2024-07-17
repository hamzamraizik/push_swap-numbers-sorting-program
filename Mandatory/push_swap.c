/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:47:47 by hmraizik          #+#    #+#             */
/*   Updated: 2024/04/06 21:20:25 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	storing(t_list **stack_a, char **res2)
{
	int		num;
	int		i;

	i = 1;
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

void	free_stack(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (*stack)
	{
		tmp = (*stack);
		*stack = (*stack)->next;
		free (tmp);
	}
	exit(0);
}

void	parsing(int argc, char **argv, t_list **stack_a, t_list **stack_b)
{
	char		*res;
	char		**res2;

	if (argc == 1)
		exit(0);
	joining(argc, argv, &res);
	res2 = ft_split(res, ' ', 0);
	free(res);
	if (!res2)
		exit(1);
	(*stack_a) = ft_lstnew(stack_a, ft_atoi((res2[0]), 0));
	storing(stack_a, res2);
	if (lstsize((*stack_a)) <= 3)
		sort_three(stack_a);
	else if (lstsize((*stack_a)) <= 5)
		sort5(&(*stack_a), stack_b);
	else
	{
		if (!if_reverse(stack_a))
			semi_sorting_2(stack_a, stack_b);
		else
			semi_sorting(stack_a, stack_b);
		last_sorting(stack_a, stack_b);
	}
	free_stack(stack_a);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	parsing(argc, argv, &stack_a, &stack_b);
	return (0);
}
