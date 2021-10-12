
NAME			=	fractol

SRCS			=	sources/fractol.c			\
					sources/burningship.c		\
					sources/calculate_color.c	\
					sources/draw_image.c		\
					sources/help.c				\
					sources/hook.c				\
					sources/init_fractol.c		\
					sources/julia.c				\
					sources/mandelbrot.c		\
					sources/reset_fractol.c		\
					sources/terminate.c

OBJS			=	$(SRCS:.c=.o)

LIBFT			=	libft.a
LIBFT_PATH		=	./libft/
LIBFTMAKE		=	$(MAKE) all -sC $(LIBFT_PATH)

CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror
MLXFLAGS		=	-lmlx -framework OpenGL -framework AppKit

all:				lib $(NAME)

.c.o:
					$(CC) $(CFLAGS) -I./includes/ -c $< -o $@

$(NAME):			$(OBJS)
					$(CC) $(CFLAGS) $(MLXFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft -o $(NAME)

lib:
					$(LIBFTMAKE)

clean:
					$(MAKE)	clean -sC $(LIBFT_PATH)
					rm -rf $(OBJS)

fclean:				clean
					$(MAKE)	fclean -sC $(LIBFT_PATH)
					rm -rf $(NAME)

re:					fclean all
.PHONY:				all lib clean fclean re
