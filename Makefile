NAME = bsq
CC = cc
SRCS = main.c ft_map_reader.c ft_map_validator.c ft_map_solver.c ft_utils.c ft_parse_map.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -I ft_includes

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)
