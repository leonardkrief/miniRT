UNAME			=	$(shell uname)

MINIRT			=	miniRT

DIR_SRCS		=	srcs

DIR_OBJS		=	objs

SRCS_NAMES		=	error_handler/error.c \
					graphics/conversions.c \
					graphics/free.c \
					graphics/graphics.c \
					graphics/inputs/inputs.c \
					graphics/pixels/ops.c \
					graphics/pixels/pixels.c \
					graphics/pixels/print.c \
					graphics/tmp_pixels/ops.c \
					graphics/tmp_pixels/tmp_pixels.c \
					graphics/tmp_pixels/print.c \
					objects/lights/lights.c \
					objects/lights/print.c \
					matrixes/init.c \
					matrixes/invert.c \
					matrixes/linear_ops.c \
					matrixes/ops.c \
					matrixes/print.c \
					matrixes/transformations/transformations1.c \
					matrixes/transformations/transformations2.c \
					objects/sphere.c \
					objects/material.c \
					ppm/ppm.c \
					raytracer/intersections/intersect_objects.c \
					raytracer/intersections/intersections.c \
					raytracer/intersections/print.c \
					raytracer/rays/lighting.c \
					raytracer/rays/print.c \
					raytracer/rays/rays.c \
					tuples/init.c \
					tuples/ops1.c \
					tuples/ops2.c \
					tuples/scalar_ops.c \
					tuples/print.c \
					world/camera.c \
					world/display.c \
					world/object_lists/basics.c \
					world/object_lists/more.c \
					world/add_elements.c \
					world/hits.c \
					world/print.c \
					world/transformations.c \
					world/world.c \
					main.c

SRCS			=	$(addprefix $(DIR_SRCS)/, $(SRCS_NAMES))
OBJS			=	$(addprefix $(DIR_OBJS)/, $(OBJS_NAMES))

OBJS_NAMES		=	${SRCS_NAMES:.c=.o}
DEPS			=	${SRCS_NAMES:.c=.d}

CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
CDFLAGS			=	-MMD -MP

ifeq (${UNAME}, Darwin)
	INCLUDE			=	-Iinclude -Iinclude/structs -Ilibft/include -I/usr/X11/include
	LIBS			=	-L/usr/X11/lib -Llibft -lft -l mlx
	FRAMEWORKS		=	-framework OpenGL -framework AppKit
else ifeq (${UNAME}, Linux)
	INCLUDE			=	-Iinclude -Iinclude/structs -Ilibft/include -Imlx
	LIBS			=	-L/usr/lib -Llibft -Lmlx -lft -lmlx -lXext -lX11 -lm
endif

RM					=	rm -rf

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
				mkdir -p ${addprefix ${DIR_OBJS}/, graphics/inputs}
				mkdir -p ${addprefix ${DIR_OBJS}/, graphics/pixels}
				mkdir -p ${addprefix ${DIR_OBJS}/, graphics/tmp_pixels}
				mkdir -p ${addprefix ${DIR_OBJS}/, lights}
				mkdir -p ${addprefix ${DIR_OBJS}/, lists}
				mkdir -p ${addprefix ${DIR_OBJS}/, phong}
				mkdir -p ${addprefix ${DIR_OBJS}/, matrixes}
				mkdir -p ${addprefix ${DIR_OBJS}/, matrixes/transformations}
				mkdir -p ${addprefix ${DIR_OBJS}/, objects}
				mkdir -p ${addprefix ${DIR_OBJS}/, objects/lights}
				mkdir -p ${addprefix ${DIR_OBJS}/, ppm}
				mkdir -p ${addprefix ${DIR_OBJS}/, raytracer}
				mkdir -p ${addprefix ${DIR_OBJS}/, raytracer/intersections}
				mkdir -p ${addprefix ${DIR_OBJS}/, raytracer/rays}
				mkdir -p ${addprefix ${DIR_OBJS}/, tuples}
				mkdir -p ${addprefix ${DIR_OBJS}/, world}
				mkdir -p ${addprefix ${DIR_OBJS}/, world/object_lists}

bonus:			${MINIRT}

clean:
				make clean -C libft
				${RM} ${DIR_OBJS}

fclean:			clean
				make fclean -C libft
				${RM} ${MINIRT}

re:				fclean all

# Debug
d:				CFLAGS += -g3
d:				all
red:			fclean d

# Performance
p:				CC = gcc
p:				CFLAGS += -O3
p:				all
rep:			fclean p


-include		${DEPS}

.PHONY:			all clean fclean re
