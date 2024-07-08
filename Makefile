NAME = push_swap
AR = ar -crs
CC = cc -Wall -Wextra -Werror -c

# libft
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC_DIR = src

SRC = push_swap.c\
	get_input.c\
	assign_stack.c\
	swap.c\
	simple_sort.c\
	rotate.c\
	reverse_rotate.c\
	push.c\
	index.c\

OBJ = $(SRC:%.c=%.o)
FILES = $(addprefix $(SRC_DIR)/, $(SRC))
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