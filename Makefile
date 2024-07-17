NAME = push_swap
AR = ar -crs
CC = cc -Wall -Wextra -Werror -fsanitize=address -g3

# libft
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a


SRC = push_swap.c\
	get_input.c\
	assign_stack.c\
	swap.c\
	sort.c\
	rotate.c\
	reverse_rotate.c\
	push.c\
	index.c\
	utils.c\

OBJ = $(SRC:%.c=%.o)

$(LIBFT) : 
	make -C $(LIBFT_PATH) all
	@echo libft done!!!


all : $(NAME)

$(NAME) : utils $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)


%.o: %.c
	$(CC) -c $< -o $@

clean :  
	rm -rf $(OBJ)
	make -C libft clean

utils :
	make -C libft all
	@echo "libft built successfully"

fclean : clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all

norm : 
	norminette *.c *.h
	make -C libft norm