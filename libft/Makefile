LIBFT			=	libft.a

DIR_SRCS		=	srcs
DIR_OBJS		=	objs

SRCS_NAMES		=	ft_put_fd/ft_putchar_fd.c \
					ft_put_fd/ft_putendl_fd.c \
					ft_put_fd/ft_putnbr_fd.c \
					ft_put_fd/ft_putstr_fd.c \
					is_something/ft_isalnum.c \
					is_something/ft_isalpha.c \
					is_something/ft_isascii.c \
					is_something/ft_isblank.c \
					is_something/ft_isdigit.c \
					is_something/ft_isprint.c \
					mem/ft_memchr.c \
					mem/ft_memcmp.c \
					mem/ft_memcpy.c \
					mem/ft_memmove.c \
					mem/ft_memset.c \
					str/ft_strchr.c \
					str/ft_strcmp.c \
					str/ft_strdup.c \
					str/ft_striteri.c \
					str/ft_strjoin.c \
					str/ft_strlcat.c \
					str/ft_strlcpy.c \
					str/ft_strlen.c \
					str/ft_strmapi.c \
					str/ft_strncmp.c \
					str/ft_strndup.c \
					str/ft_strnstr.c \
					str/ft_strrchr.c \
					str/ft_strtrim.c \
					str/ft_substr.c \
					to_something/ft_tolower.c \
					to_something/ft_toupper.c \
					utils/ft_atoi.c \
					utils/ft_bzero.c \
					utils/ft_calloc.c \
					utils/ft_free_tab.c \
					utils/ft_itoa.c \
					utils/ft_split.c \
					get_next_line/get_next_line.c

SRCS			=	${addprefix ${DIR_SRCS}/,${SRCS_NAMES}}
OBJS			=	${addprefix ${DIR_OBJS}/,${OBJS_NAMES}}

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}
DEPS			=	${SRCS_NAMES:.c=.d}

INCLUDE			=	-Iinclude
CC				=	cc
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror
CDFLAGS			=	-MMD -MP

${LIBFT}:		${DIR_OBJS} ${OBJS}
			ar rc ${LIBFT} ${OBJS}
			ranlib ${LIBFT}

all:		${LIBFT}

${DIR_OBJS}:
			mkdir -p ${DIR_OBJS}
			mkdir -p objs/ft_put_fd
			mkdir -p objs/get_next_line
			mkdir -p objs/is_something
			mkdir -p objs/lst
			mkdir -p objs/mem
			mkdir -p objs/str
			mkdir -p objs/to_something
			mkdir -p objs/utils


${OBJS} :	${DIR_OBJS}/%.o : ${DIR_SRCS}/%.c
			${CC} ${CFLAGS} ${CDFLAGS} ${INCLUDE} -c $< -o $@

clean:
			rm -rf ${DIR_OBJS}

fclean:		clean
			rm -rf ${LIBFT}

re:			fclean all

-include	${DEPS}

.PHONY:		all clean fclean re
.SILENT:
