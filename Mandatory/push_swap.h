/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmraizik <hmraizik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 22:01:15 by hmraizik          #+#    #+#             */
/*   Updated: 2024/04/06 20:43:51 by hmraizik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_list
{
	int				data;
	int				index;
	int				position;
	struct s_list	*next;
}		t_list;

//libft functions

char		*ft_substr(char const *s, unsigned int start, size_t len);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c, int i);
long		ft_isdigit(long i);
int			ft_isspace(char c);
int			ft_atoi(const char *str, long i);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		**free_substrs(char **substrs);

//parsing functions

void		check_char(const char *s);
void		check_duplicated(t_list *head, int x);
int			check_sorted(t_list *head);
int			check_spaces(const char *s);
int			error(void);

//list tools

t_list		*ft_lstnew(t_list **stack, int data);
void		ft_lstadd_back(t_list **alst, t_list *new);
int			lstsize(t_list *stack);

//linked list mouves

void		ft_pa(t_list **stack_b, t_list **stack_a);
void		ft_ra(t_list **stack_a);
void		ft_rra(t_list **stack_a);
void		ft_pb(t_list **stack_a, t_list **stack_b);
void		ft_rb(t_list **stack_b);
void		ft_rr(t_list **stack_a, t_list **stack_b);
void		ft_rrb(t_list **stack_b);
void		ft_rrr(t_list **stack_a, t_list **stack_b);
void		ft_ss(t_list **stack_a, t_list **stack_b);
void		ft_sa(t_list **stack_a);
void		ft_sb(t_list **stack_b);
// ________________________
int			if_reverse(t_list **stack);
void		semi_sorting(t_list **stack_a, t_list **stack_b);
void		semi_sorting_2(t_list **stack_a, t_list **stack_b);
void		last_sorting(t_list **stack_a, t_list **stack_b);
void		positioning(t_list *lst);
void		indexing(t_list **stack, t_list **new);
void		sort_three(t_list **stack);
void		sort5(t_list **stack, t_list **stack_b);

#endif