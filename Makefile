SRCS	= ./src/main.c \

OBJS	= ${SRCS:.c=.o}

LIBFT	= ./libft/libft.a \

NAME	= fdf

RM	= rm -f

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

MLXFLAGS	= -Lminilibx-linux -lX11 -lXext -lmlx

.c.o :	
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
		${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBF} ${MLXFLAGS}

all :		
		make all -C libft
		make all -C minilibx-linux	
		${NAME}

clean :
		${RM} ${OBJS}
		make clean -C libft
		make clean -C minilibx-linux

fclean :	clean
		make fclean -C libft
		${RM} ${NAME}

re :		fclean all

.PHONY :	all clean fclean re
