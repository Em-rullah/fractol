NAME =fractol
CC =cc
CFLAGS =-Wall -Wextra -Werror
RM =rm -f

LIBFT_DIR =./libft
MLX_DIR =./minilibx-linux
INCDIRS =-I. -I$(LIBFT_DIR) -I$(MLX_DIR)
X11_LIBS := -lXext -lX11 -lm -lz -lbsd

SRCS =main.c math_utils.c render.c init.c events.c string.utils.c
OBJS =$(SRCS:.c=.o)

LIBFT_A =$(LIBFT_DIR)/libft.a
MLX_A =$(MLX_DIR)/libmlx_Linux.a
MLX_NAME =mlx_Linux

LDFLAGS     := -L$(LIBFT_DIR) -L$(MLX_DIR)
LDLIBS      := -lft -l$(MLX_NAME) $(X11_LIBS)

all: $(NAME)

$(NAME): $(LIBFT_A) $(MLX_A) $(OBJS)
	$(CC) $(CFLAGS) $(INCDIRS) $(OBJS) $(LDFLAGS) $(LDLIBS) -o $@

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_A):
	$(MAKE) -C $(MLX_DIR)

%.o: %.c fractol.h
	$(CC) $(CFLAGS) $(INCDIRS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	-$(MAKE) -C $(LIBFT_DIR) clean
	-$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	$(RM) $(NAME)
	-$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
