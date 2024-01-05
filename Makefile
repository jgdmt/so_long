SRCS			:=	check_map.c \
					main.c \
					events.c \
					create_map.c \
					errors.c \
					map_copy.c \
					init_struct.c \
					game_handler.c \
					free.c

SRCS_BON		:=	bonus/check_map_bonus.c \
					bonus/main_bonus.c \
					bonus/events_bonus.c \
					bonus/create_map_bonus.c \
					bonus/errors_bonus.c \
					bonus/map_copy_bonus.c \
					bonus/init_struct_bonus.c \
					bonus/game_handler_bonus.c \
					bonus/free_bonus.c \
					bonus/enemy_bonus.c

OBJS			:= $(SRCS:.c=.o)

OBJS_BON		:= $(SRCS_BON:.c=.o)

CC				:= gcc
RM				:= rm -f
CFLAGS			:= -I. -Wall -Wextra -Werror 

NAME			:= so_long

NAME_BON		:= so_long_bonus

all:			$(NAME)

$(NAME):		$(OBJS)
				$(MAKE) -C ./printf
				$(MAKE) -C ./get_next_line
				$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) printf/printf.a get_next_line/gnl.a

bonus:			$(NAME_BON)

$(NAME_BON):	$(OBJS_BON)
				$(MAKE) -C ./printf
				$(MAKE) -C ./get_next_line
				$(CC) $(CFLAGS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME_BON) $(OBJS_BON) printf/printf.a get_next_line/gnl.a

clean:
				$(MAKE) clean -C ./printf
				$(MAKE) clean -C ./get_next_line
				$(RM) $(OBJS) $(OBJS_BON)

fclean:			clean
				$(MAKE) fclean -C ./printf
				$(MAKE) fclean -C ./get_next_line
				$(RM) $(NAME) $(NAME_BON)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus