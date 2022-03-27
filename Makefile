SRCS		= colors.c \
			  fractals.c \
			  fractol.c \
			  graphics.c \
			  hooks.c \
			  utils.c
OBJS		= ${SRCS:.c=.o}
NAME		= fractol
CC			= gcc
MAKE		= make
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
			
$(NAME):		$(OBJS)
				$(MAKE) -C printf	
				$(MAKE) -C minilibx
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) printf/libftprintf.a minilibx/libmlx.a -framework OpenGL -framework AppKit
all:			$(NAME)
clean:
				${RM} ${OBJS}
				$(MAKE) clean -C printf
				$(MAKE) clean -C minilibx
fclean:			clean
				${RM} $(NAME)
				$(MAKE) fclean -C printf
				$(MAKE) clean -C minilibx
re:				fclean all
.PHONY:			all clean fclean re
