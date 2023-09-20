NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

FILES_LIBC = ft_isalpha \
                         ft_isdigit \
                         ft_isalnum \
                         ft_isascii \
                         ft_isprint \
                         ft_strlen \
                         ft_memset \
                         ft_bzero \
                         ft_memcpy \
                         ft_memmove \
                         ft_strlcpy \
                         ft_strlcat \
                         ft_toupper \
                         ft_tolower \
                         ft_strchr \
                         ft_strrchr \
                         ft_strncmp \
                         ft_memchr \
                         ft_memcmp \
                         ft_strnstr \
                         ft_atoi \
                         ft_calloc \
                         ft_strdup

FILES_SUPP = ft_substr \
                         ft_strjoin \
                         ft_strtrim \
                         ft_split \
                         ft_itoa \
                         ft_strmapi \
                         ft_striteri \
                         ft_putchar_fd \
                         ft_putstr_fd \
                         ft_putendl_fd \
                         ft_putnbr_fd

FILES_BONUS = ft_lstnew \
                          ft_lstadd_front \
                          ft_lstsize \
                          ft_lstlast \
                          ft_lstadd_back \
                          ft_lstdelone \
                          ft_lstclear \
                          ft_lstiter \
                          ft_lstmap

SRCS_LIBC = $(addprefix ./ft_libc/, $(addsuffix .c, $(FILES_LIBC)))
SRCS_SUPP = $(addprefix ./ft_supp/, $(addsuffix .c, $(FILES_SUPP)))
SRCS_BONUS = $(addprefix ./ft_bonus/, $(addsuffix .c, $(FILES_BONUS)))

OBJS_DIR = ./
OBJS_LIBC = $(addprefix $(OBJS_DIR)ft_libc/, $(addsuffix .o, $(FILES_LIBC)))
OBJS_SUPP = $(addprefix $(OBJS_DIR)ft_supp/, $(addsuffix .o, $(FILES_SUPP)))
OBJS_BONUS = $(addprefix $(OBJS_DIR)ft_bonus/, $(addsuffix .o, $(FILES_BONUS)))

ft_libc/%.o: ft_libc/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

ft_supp/%.o: ft_supp/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

ft_bonus/%.o: ft_bonus/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS_LIBC) $(OBJS_SUPP)
	$(AR) $@ $^

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS_LIBC) $(OBJS_SUPP) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re

