CFILES = Mandatory/push_swap.c Mandatory/moves.c Mandatory/ft_atoi.c Mandatory/ft_split.c Mandatory/libft_utils.c Mandatory/list_tools.c Mandatory/mouves_a.c Mandatory/mouves_b.c Mandatory/swap_mouves.c Mandatory/sort_three.c Mandatory/sorting.c Mandatory/Utils1.c Mandatory/sort_5.c
BFILES = Bonus/checker_bonus.c Bonus/ft_atoi.c Bonus/ft_split.c Bonus/libft_utils.c Bonus/list_tools.c Bonus/mouves_a.c Bonus/mouves_b.c Bonus/swap_mouves.c Bonus/Utils1.c Bonus/get_next_line.c Bonus/get_next_line_utils.c
OFILES = $(CFILES:.c=.o)
B_OFILES = $(BFILES:.c=.o)
NAME = push_swap
BONUS_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

Mandatory/%.o: Mandatory/%.c Mandatory/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

Bonus/%.o: Bonus/%.c Bonus/checker.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OFILES)
	$(CC) $(CFLAGS) -o $(NAME) $(OFILES)

$(BONUS_NAME): $(B_OFILES)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(B_OFILES)

bonus: $(BONUS_NAME)

clean:
	rm -f $(OFILES) $(B_OFILES)

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all
