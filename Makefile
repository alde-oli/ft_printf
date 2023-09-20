NAME = libftprintf.a

LIBFT_DIR = ./libft_src
LIBFT = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

FILES = ft_printf \
        ft_process_fs \
        ft_insert_c \
        ft_insert_s \
        ft_insert_p \
        ft_insert_d \
        ft_insert_u \
        ft_insert_x \
        ft_insert_xup \
        ft_insert_percent

SRCS = $(addprefix ./srcs/, $(addsuffix .c, $(FILES)))

OBJS = $(SRCS:.c=.o)

libft:
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT_DIR)/$(LIBFT) .
	@mv $(LIBFT) $(NAME)

$(NAME): libft $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)
	@cd $(LIBFT_DIR) && make clean

fclean: clean
	$(RM) $(NAME)
	@cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: libft all clean fclean re