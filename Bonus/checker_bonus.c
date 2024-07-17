/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:01:46 by hmraizik          #+#    #+#             */
/*   Updated: 2024/04/06 21:48:40 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
}

void	ft_rest(t_list **stack_a, t_list **stack_b, char *s)
{
	if (ft_strcmp(s, "rr\n") == 0)
		ft_rr(stack_a, stack_b);
	else if (ft_strcmp(s, "rra\n") == 0)
		ft_rra(stack_a);
	else if (ft_strcmp(s, "rrb\n") == 0)
		ft_rrb(stack_b);
	else if (ft_strcmp(s, "rrr\n") == 0)
		ft_rrr(stack_a, stack_b);
	else if (ft_strcmp(s, "pa\n") == 0)
		ft_pa(stack_b, stack_a);
	else if (ft_strcmp(s, "pb\n") == 0)
		ft_pb(stack_a, stack_b);
	else
		error();
}

void	check_mouves(t_list **stack_a, t_list **stack_b, char *s)
{
	while (1)
	{
		s = get_next_line(0);
		if (!s)
			break ;
		if (ft_strcmp(s, "sa\n") == 0)
			ft_sa(stack_a);
		else if (ft_strcmp(s, "sb\n") == 0)
			ft_sb(stack_b);
		else if (ft_strcmp(s, "ss\n") == 0)
			ft_ss(stack_a, stack_b);
		else if (ft_strcmp(s, "ra\n") == 0)
			ft_ra(stack_a);
		else if (ft_strcmp(s, "rb\n") == 0)
			ft_rb(stack_b);
		else
			ft_rest(stack_a, stack_b, s);
	}
	free(s);
}

void	process(int argc, char **argv)
{
	char		*res;
	t_list		*stack_a;
	t_list		*stack_b;
	char		**res2;
	char		*s;

	s = NULL;
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		exit(0);
	joining(argc, argv, &res);
	res2 = ft_split(res, ' ', 0);
	free(res);
	if (!res2)
		exit(1);
	stack_a = ft_lstnew(&stack_a, ft_atoi((res2[0]), 0));
	storing(&stack_a, res2);
	check_mouves(&stack_a, &stack_b, s);
	if ((check_sorted(stack_a) == 1) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	process(argc, argv);
	return (0);
}
