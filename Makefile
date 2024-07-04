NAME = push_swap
AR = ar -crs
CC = cc -Wall -Wextra -Werror -c

# libft
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC = push_swap.c\
	get_input.c\
	assign_stack.c\
	swap.c\
	simple_sort.c\

OBJ = $(SRC:%.c=%.o)

$(LIBFT) : 
	make -C $(LIBFT_PATH)
	@echo libft done!!!


all : utils mandatory
	$(AR) $(NAME) $(OBJ)

mandatory :
	$(CC) $(SRC)

clean =  
	rm -rf $(OBJ)
	make -C libft clean

utils : $(LIBFT)
	@echo "libft built successfully"

fclean = clean
	rm -rf $(NAME)
	make -C $(LIBFT_PATH) fclean

re : fclean all

norm : 
	norminette *.c