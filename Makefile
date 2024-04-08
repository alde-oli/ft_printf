NAME = libftprintf.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I$(INC_PATH)
TEST_FLAGS = -I$(INC_PATH)

SRC_PATH = src/
INC_PATH = include/
LIBFT_PATH = libft/

SRC = $(wildcard $(SRC_PATH)*.c)
INC = $(wildcard $(INC_PATH)*.h)
LIBFT = $(LIBFT_PATH)libft.a

OBJ = $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

bonus: all

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c $(INC)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@$(MAKE) -C $(LIBFT_PATH) clean
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all bonus clean fclean re
