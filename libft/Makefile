NAME = libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs
RM = rm -f

FILES = ft_isalpha \
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
                    ft_strdup \
                    ft_substr \
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

SRCS_DIR = ./
SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES)))
SRCS_BONUS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(FILES_BONUS)))


OBJS_DIR = ./
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES)))
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(FILES_BONUS)))


%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(OBJS_BONUS)
	$(AR) $(NAME) $^

all: $(NAME)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: bonus all clean fclean re
