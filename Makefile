SRCS	= ./src/main.c \
	  ./src/parse.c \
	  ./src/draw.c \
	  ./src/window.c \
	  ./src/freedata.c \
	  ./src/color.c \
	  ./src/init.c \
	  ./src/setpoints.c \
	  ./src/event.c \

OBJS	= ${SRCS:.c=.o}

LIBFT	= -Llibft

MLX	= -Lminilibx-linux

TITLE	= fdf

RM	= rm -f

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

LIBFLAGS	= -lX11 -lXext -lmlx -lm -lft

NAME	= fdf

.c.o :		
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}	:	${OBJS}
		make all -C libft
		make all -C minilibx-linux
		${CC} -o ${NAME} -g ${CFLAGS} ${OBJS} ${LIBFT} ${MLX} ${MLXFLAGS} 

all :		${NAME}

clean :
		${RM} ${OBJS}
		make clean -C libft
		make clean -C minilibx-linux

fclean :	clean
		make fclean -C libft
		${RM} ${NAME}

re :		fclean all

.PHONY :	all clean fclean re
