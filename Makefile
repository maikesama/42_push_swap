NAME = push_swap

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SCRS = push_swap.c\
		init_args.c\
		error_check.c\
		ins_sort.c\
		cleaner.c\
		sorter.c\
		ops.c\
		rkrs_calc.c\
		rkrs_hunt.c\
		utils.c\
		exec_ops.c\
		operations.c\
		ind_calc.c\
		ind_hunt.c

OBJS = $(SCRS:.c=.o)

LIBS = -L./lib/libft -L./lib/ft_printf -lft -lftprintf

all : $(NAME)

libraries :
	cd ./lib/libft; make;
	cd ./lib/ft_printf; make;

$(NAME) : $(OBJS) | libraries
		$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

clean :
	rm -f $(NAME) $(OBJS)

fclean : clean
	make fclean -C ./lib/libft
	make fclean -C ./lib/ft_printf

re : fclean all
