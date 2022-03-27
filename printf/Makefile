SRCS		= ft_printf.c \
			  set_flags.c \
			  write_letters.c \
			  write_pointer.c \
			  write_decimal.c \
			  write_hexa.c
SRCS_BONUS	= ft_printf_bonus.c \
			  flags_bonus.c \
			  set_flags_bonus.c \
			  write_letters_bonus.c \
			  write_pointer_bonus.c \
			  write_decimal_bonus.c \
			  write_hexa_bonus.c
OBJS		= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)
NAME		= libftprintf.a
CC			= gcc
MAKE		= make
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
.c.o:
				$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
$(NAME):		$(OBJS)
				$(MAKE) all -C libft
				cp ./libft/libft.a libftprintf.a
				ar rc $(NAME) $(OBJS)
all:			$(NAME)
bonus:			$(NAME_BONUS)
$(NAME_BONUS):	$(OBJS_BONUS)
				$(MAKE) all -C libft
				cp ./libft/libft.a libftprintf.a
				ar rc $(NAME) $(OBJS_BONUS)
clean:
				$(RM) $(OBJS) $(OBJS_BONUS)
				$(MAKE) clean -C libft
fclean:			clean
				$(RM) $(NAME)
				$(MAKE) fclean -C libft
re:				fclean all
.PHONY:			all clean fclean re bonus
