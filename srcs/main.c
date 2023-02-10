#include "miniRT.h"
#include <time.h>

# define TRANSLATION(x, y, z) matrix_translation(x, y, z)
# define SCALING(x) matrix_scaling(x, x, x)

int	main(void)
{
	t_tuple from, to, up;

	from = point(1, 3, 2);
	to = point(4, -2, 8);
	up = vector(1, 1, 0);
	matrix_print(view_transform(from, to, up), "M: ");
}