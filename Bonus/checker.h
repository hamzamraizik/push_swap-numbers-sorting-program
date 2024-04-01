#ifndef CHECKER_H
# define CHECKER_H

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

# define BUFFER_SIZE 24

//parsing functions
int			check_sorted(t_list *head);
int			check_spaces(const char *s);
size_t		ft_strlen(const char *str);
char		**ft_split(char const *s, char c, int i);
long		ft_isdigit(long i);
int			ft_isspace(char c);
int			ft_atoi(const char *str, long i);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
int			error(void);
void		indexing(t_list **stack, t_list **new);
char		**free_substrs(char **substrs);
//list tools
t_list		*ft_lstnew(t_list **stack, int data);
void		ft_lstadd_back(t_list **alst, t_list *new);
int			lstsize(t_list *stack);
//stack mouves
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

// _________
//for Bonus
int			ft_strcmp(char *s1, const char *s2);
void		joining(int argc, char **argv, char **res);
char		*get_next_line(int fd);
void		ft_free(char **x);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
void		check_char(const char *s);
void		check_duplicated(t_list *head, int x);

#endif