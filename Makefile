NAME		=	minishell

CC			=	gcc

FLAG		=	-Wall -Wextra -Werror -g 

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

C_FILE		=	main.c 				\
				minishell_loop.c 	\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\
				\


SRC_DIR		=	./srcs/

INC_DIR		=	./includes/

SRC			=	$(addprefix $(SRC_DIR),$(C_FILE))

OBJ			=	$(SRC:.c=.o)

.c.o:
	$(CC) $(FLAG) -c $< -o $@ 

all: $(NAME)

lib:
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJ)
	make lib
	$(CC) $(OBJ) $(LIBFT_LIB) -o $(NAME) -lreadline
	@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

clean:
	@make clean -sC $(LIBFT_PATH)
	@rm -f $(OBJ)
	@echo -e "$(YELLOW)object files deleted!$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_PATH)
	@echo -e "$(RED)all deleted!$(DEFAULT)"

re: fclean all

.PHONY: all clean fclean re lib mlx


#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m