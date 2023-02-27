UNAME			=	$(shell uname)

MINIRT			=	miniRT

DIR_SRCS		=	srcs

DIR_OBJS		=	objs

SRCS_NAMES		=	core/graphics/camera.c \
					core/graphics/display.c \
					core/graphics/free.c \
					core/graphics/mlx_basics.c \
					core/graphics/inputs/inputs.c \
					core/graphics/pixels/ops.c \
					core/graphics/pixels/pixels.c \
					core/graphics/pixels/print.c \
					core/graphics/tmp_pixels/ops.c \
					core/graphics/tmp_pixels/tmp_pixels.c \
					core/graphics/tmp_pixels/print.c \
					core/objects/lights/lights.c \
					core/objects/lights/print.c \
					core/objects/object_lists/basics.c \
					core/objects/object_lists/more.c \
					core/objects/patterns/patterns_basics.c \
					core/objects/patterns/patterns.c \
					core/objects/objects.c \
					core/objects/shapes/plane.c \
					core/objects/shapes/sphere.c \
					core/intersections/intersect_plane.c \
					core/intersections/intersect_sphere.c \
					core/intersections/intersections.c \
					core/intersections/print.c \
					core/rays/print.c \
					core/rays/rays.c \
					core/world/add_elements.c \
					core/world/hits.c \
					core/world/print.c \
					core/world/world.c \
					geometry/matrixes/init.c \
					geometry/matrixes/invert.c \
					geometry/matrixes/linear_ops.c \
					geometry/matrixes/ops.c \
					geometry/matrixes/print.c \
					geometry/matrixes/transformations/transformations1.c \
					geometry/matrixes/transformations/transformations2.c \
					geometry/tuples/init.c \
					geometry/tuples/ops1.c \
					geometry/tuples/ops2.c \
					geometry/tuples/scalar_ops.c \
					geometry/tuples/print.c \
					parser/parser.c \
					parser/parser_objects.c \
					utils/error_handler/error.c \
					utils/ppm/ppm.c \
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
				mkdir -p ${addprefix ${DIR_OBJS}/, core/graphics}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/graphics/inputs}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/graphics/pixels}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/graphics/tmp_pixels}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/lights}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/lists}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/phong}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/objects}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/objects/lights}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/objects/object_lists}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/objects/patterns}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/objects/shapes}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/intersections}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/rays}
				mkdir -p ${addprefix ${DIR_OBJS}/, core/world}
				mkdir -p ${addprefix ${DIR_OBJS}/, geometry/tuples}
				mkdir -p ${addprefix ${DIR_OBJS}/, geometry/matrixes}
				mkdir -p ${addprefix ${DIR_OBJS}/, geometry/matrixes/transformations}
				mkdir -p ${addprefix ${DIR_OBJS}/, parser}
				mkdir -p ${addprefix ${DIR_OBJS}/, utils/error_handler}
				mkdir -p ${addprefix ${DIR_OBJS}/, utils/ppm}

bonus:			${MINIRT}

clean:
				make clean -C libft
				${RM} ${DIR_OBJS}

fclean:			clean
				make fclean -C libft
				${RM} ${MINIRT}

re:				fclean all

# Debug			CFLAGS = -Wall -Wextra -g3
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
# .SILENT: