#include "miniRT.h"
#include <time.h>

# define TRANSLATION(x, y, z) matrix_translation(x, y, z)
# define SCALING(x) matrix_scaling(x, x, x)

int	main(void)
{
	t_canvas 	cvs;
	t_camera 	c;
	t_world		w;
	t_all		args;

	canvas(&cvs);
	w = world();
	c = camera(DEFAULT_CAMERA_WIDTH_HI, DEFAULT_CAMERA_HEIGHT_HI, DEFAULT_CAMERA_FOV);
	all(&args, &cvs, &c, &w);
	display_loop(&args);
}