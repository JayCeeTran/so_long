NAME = libso_long.a
LIBFT = libft.a

CC = cc
CFLAG = -Wall -Wextra -Werror

LSRCS =	libft/ft_atoi.c \
	libft/ft_bzero.c \
	libft/ft_calloc.c \
	libft/ft_isalnum.c \
	libft/ft_isalpha.c \
	libft/ft_isascii.c \
	libft/ft_isdigit.c \
	libft/ft_isprint.c \
	libft/ft_itoa.c \
	libft/ft_memchr.c \
	libft/ft_memcmp.c \
	libft/ft_memcpy.c \
	libft/ft_memmove.c \
	libft/ft_memset.c \
	libft/ft_putchar_fd.c \
	libft/ft_putendl_fd.c \
	libft/ft_putnbr_fd.c \
	libft/ft_putstr_fd.c \
	libft/ft_split.c \
	libft/ft_strchr.c \
	libft/ft_strdup.c \
	libft/ft_striteri.c \
	libft/ft_strjoin.c \
	libft/ft_strlcat.c \
	libft/ft_strlcpy.c \
	libft/ft_strlen.c \
	libft/ft_strmapi.c \
	libft/ft_strncmp.c \
	libft/ft_strnstr.c \
	libft/ft_strrchr.c \
	libft/ft_strtrim.c \
	libft/ft_substr.c \
	libft/ft_tolower.c \
	libft/ft_toupper.c \
	libft/ft_lstnew_bonus.c \
	libft/ft_lstadd_front_bonus.c \
	libft/ft_lstadd_back_bonus.c \
	libft/ft_lstclear_bonus.c \
	libft/ft_lstdelone_bonus.c \
	libft/ft_lstiter_bonus.c \
	libft/ft_lstlast_bonus.c \
	libft/ft_lstmap_bonus.c \
	libft/ft_lstsize_bonus.c \

SRCS = map_size.c \
	map_chars.c \
	map_walls.c \
	fill_map.c \
	valid_path.c \

OBJ = $(SRCS:.c=.o)
LOBJ = $(LSRCS:.c=.o)
LIBMLX = -L ~/42/MLX42/build -lmlx42 -ldl -lglfw -lm -pthread
EXE = a.out

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ) 

$(LIBFT): $(LOBJ)
	ar -rcs $(LIBFT) $(LOBJ) 


run: $(EXE)
	./a.out maps/map1.ber

$(EXE): $(NAME) $(LIBFT) so_long.c
	cc $(CFLAGS) -g so_long.c $(NAME) $(LIBFT) $(LIBMLX) -o $(EXE)

clean:
	rm -f $(LOBJ) $(OBJ)

fclean: clean
	rm -f $(NAME) $(LIBFT) $(EXE)

re: fclean all
