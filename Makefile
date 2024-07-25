NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -I

INCLUDE = include

SRC_DIR = src
BONUS_DIR = bonus

SRC_FILES =	push_swap\
			get_input\
			assign_stack\
			swap\
			sort\
			rotate\
			reverse_rotate\
			push\
			utils\
			index\
			sort_big\
			count_cost

BONUS_SRC_FILES = assign_stack\
				get_input\
				swap\
				rotate\
				reverse_rotate\
				push\
				utils_bonus\
				checker

SRC = $(addprefix $(SRC_DIR)/, $(addsuffix .c, $(SRC_FILES)))
BONUS_SRC = $(addprefix $(BONUS_DIR)/, $(addsuffix .c, $(BONUS_SRC_FILES)))

OBJ_DIR = obj
BONUS_OBJ_DIR = bonus_obj
OBJ = $(addprefix $(OBJ_DIR)/, $(addsuffix .o, $(SRC_FILES)))
BONUS_OBJ = $(addprefix $(BONUS_OBJ_DIR)/, $(addsuffix .o, $(BONUS_SRC_FILES)))

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all :
		@mkdir -p $(OBJ_DIR)
		@make -C libft all
		@make $(NAME)
		clear
		
bonus :
		@mkdir -p $(BONUS_OBJ_DIR)
		@make -C libft all
		@make $(BONUS_NAME)
		clear

$(OBJ_DIR)/%.o:		$(SRC_DIR)/%.c
					@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(BONUS_OBJ_DIR)/%.o:		$(BONUS_DIR)/%.c
							@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME) :	$(OBJ)
			@$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) $(LIBFT) -o $(NAME)

$(BONUS_NAME):	$(BONUS_OBJ)
				@$(CC) $(CFLAGS) $(INCLUDE) $(BONUS_OBJ) $(LIBFT) -o $(BONUS_NAME)

clean :
			@rm -rf $(OBJ_DIR) $(BONUS_OBJ_DIR)
			@make clean -C $(LIBFT_DIR)
			clear

fclean:
			@rm -rf $(OBJ_DIR) $(NAME) $(BONUS_OBJ_DIR) $(BONUS_NAME)
			@make -C $(LIBFT_DIR) fclean
			clear

re:			fclean all

.PHONY:	clean fclean re all bonus
