MINIRT			=	miniRT

DIR_SRCS		=	srcs

DIR_OBJS		=	objs

SRCS_NAMES		=	error_handler/error.c \
					graphics/free.c \
					graphics/graphics.c \
					matrixes/init.c \
					matrixes/invert.c \
					matrixes/ops.c \
					matrixes/print.c \
					pixels/ops.c \
					pixels/pixels.c \
					pixels/print.c \
					ppm/ppm.c \
					tuples/init.c \
					tuples/ops.c \
					tuples/scalar_ops.c \
					tuples/print.c \
					main.c


SRCS			=	$(addprefix $(DIR_SRCS)/, $(SRCS_NAMES))
OBJS			=	$(addprefix $(DIR_OBJS)/, $(OBJS_NAMES))

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}
DEPS			=	${SRCS_NAMES:.c=.d}

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3
CDFLAGS 		=	-MMD -MP
INCLUDE			=	-Iinclude -I/usr/X11/include -Ilibft/include
LIBS			=	-L/usr/X11/lib -Llibft -lft -l mlx
FRAMEWORKS		=	-framework OpenGL -framework AppKit
RM				=	rm -rf

all:			${MINIRT}

${MINIRT}:		${DIR_OBJS} ${OBJS}
				make -C libft
				${CC} ${CFLAGS} ${OBJS} ${LIBS} ${FRAMEWORKS} -o ${MINIRT}

${OBJS} :		${DIR_OBJS}/%.o : ${DIR_SRCS}/%.c
				${CC} ${CFLAGS} ${CDFLAGS} ${INCLUDE} -c $< -o $@

${DIR_OBJS}:
				mkdir -p ${DIR_OBJS}
				mkdir -p ${addprefix ${DIR_OBJS}/, error_handler}
				mkdir -p ${addprefix ${DIR_OBJS}/, graphics}
				mkdir -p ${addprefix ${DIR_OBJS}/, matrixes}
				mkdir -p ${addprefix ${DIR_OBJS}/, pixels}
				mkdir -p ${addprefix ${DIR_OBJS}/, ppm}
				mkdir -p ${addprefix ${DIR_OBJS}/, tuples}

bonus:			${MINIRT}

clean:
				make clean -C libft
				${RM} ${DIR_OBJS}

fclean:			clean
				make fclean -C libft
				${RM} ${MINIRT}

re:				fclean all

-include		${DEPS}

.PHONY:			all clean fclean re
