SRCS	= ./src/main.c \
	  ./src/parse.c \
	  ./src/draw.c \
	  ./src/window.c \
	  ./src/freedata.c \
	  ./src/color.c \
	  ./src/init.c \

OBJS	= ${SRCS:.c=.o}

LIBFT	= ./libft/libft.a \

TITLE	= fdf

RM	= rm -f

CC	= cc

CFLAGS	= -Wall -Werror -Wextra

MLXFLAGS	= -Lminilibx-linux -lX11 -lXext -lmlx -lm

NAME	= fdf

${NAME}	:	
		make all -C libft
		make all -C minilibx-linux
		${CC} -o ${NAME} -g ${CFLAGS} ${SRCS} ${LIBFT} ${MLXFLAGS} 

all :		
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
