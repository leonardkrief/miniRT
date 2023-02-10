#include "miniRT.h"
#include <time.h>

# define TRANSLATION(x, y, z) matrix_translation(x, y, z)
# define SCALING(x) matrix_scaling(x, x, x)

int	main(void)
{
	t_canvas cvs;
	t_camera c;
	t_world w;

	canvas(&cvs);
	w = world();
	c = camera(DEFAULT_CAMERA_WIDTH_HI, DEFAULT_CAMERA_HEIGHT_HI, DEFAULT_CAMERA_FOV);
	render(&cvs, &c, &w);
	mlx_put_image_to_window(cvs.window.mlx, cvs.window.win, cvs.image.img, 0, 0);
	mlx_key_hook(cvs.window.win, &input_key, &cvs);
	mlx_hook(cvs.window.win, CLOSE_WINDOW_BUTTON_EVENT, 0, &exit_program, &cvs);
	mlx_mouse_hook(cvs.window.win, &input_mouse, &cvs);
	mlx_loop(cvs.window.mlx);
	free_canvas(&cvs);
}