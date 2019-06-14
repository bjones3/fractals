NAME = fractol
OBJS = objs/main.o objs/params.o objs/init.o objs/main_menu.o \
	   objs/mouse_hooks.o objs/key_hooks.o objs/redraw.o \
	   objs/draw1.o objs/draw2.o objs/color_palettes.o
HEADERS = includes libft/includes minilibx_macos
HEAD_DEPEND = includes/$(NAME).h libft/includes/libft.h minilibx_macos/mlx.h
LIBFT = libft/libft.a
LIBMLX = minilibx_macos/libmlx.a
CFLAGS = -Wall -Wextra -Werror
FRAMEWORKS = -framework Appkit -framework OpenGL

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	gcc $(CFLAGS) -I libft/includes -I minilibx_macos $(OBJS) $(LIBFT) $(LIBMLX) -o $(NAME) $(FRAMEWORKS)

$(OBJS): objs/%.o: srcs/%.c $(HEAD_DEPEND) objs
	gcc $(CFLAGS) -I libft/includes -I minilibx_macos -c $< -o $@

objs:
	mkdir objs

$(LIBFT):
	make -C libft

$(LIBMLX):
	make -C minilibx_macos

clean:
	rm -rf objs
	make clean -C libft
	make clean -C minilibx_macos

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY : all clean fclean re