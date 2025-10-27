NAME =fractol
CC =cc
CFLAGS =-Wall -Wextra -Werror
RM =rm -f

MLX_DIR =./minilibx-linux
X11_LIBS = -lXext -lX11

SRCS =main.c init.c render.c events.c  utils.c string_utils.c cleanup.c
OBJS =$(SRCS:.c=.o)

MLX_A =$(MLX_DIR)/libmlx_Linux.a
MLX_NAME =mlx_Linux

LDFLAGS =-L$(MLX_DIR)
LDLIBS =-l$(MLX_NAME) $(X11_LIBS)

all: $(NAME)

$(NAME): $(MLX_A) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	-$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
