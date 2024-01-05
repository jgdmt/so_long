SRCS			:=	ft_printf.c \
					ft_change_base.c \
					ft_itoa.c \
					ft_put.c
OBJS			:= $(SRCS:.c=.o)


CC				:= gcc
RM				:= rm -f
CFLAGS			:= -Wall -Wextra -Werror -I.

NAME			:= printf.a

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)
	
.PHONY:			all clean fclean re 
.SILENT:	