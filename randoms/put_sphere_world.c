#include "miniRT.h"
#include <time.h>

# define TRANSLATION(x, y, z) matrix_translation(x, y, z)
# define SCALING(x) matrix_scaling(x, x, x)

int	main(void)
{

	t_world	w;

	w = world();
	world_print(&w);

	int	i, j;
	t_tuple	or = point(0, 0, -5);
	t_tuple a;
	t_ray	ry;
	t_canvas	cvs;

	canvas(&cvs);
	clock_t		start, end;
	start = clock();
	for(i = 0; i < WIDTH; i++)
	{
		for(j = 0; j < HEIGHT; j++)
		{
			a = tuple_sub(pixel_to_point(&cvs.image, i, j), or);
			ry = ray(or, a);
			put_pixel(&cvs.image, i, j, color_at(&w, &ry));
			if (ry.itr_back)
				free(ry.itr_back);
			if (ry.itr_front)
				free(ry.itr_front);
		}
	}
	end = clock();
	printf("time: %.3fs\n", (double)(end - start) / CLOCKS_PER_SEC);

	// make_scene(&cvs);
	mlx_put_image_to_window(cvs.window.mlx, cvs.window.win, cvs.image.img, 0, 0);
	mlx_key_hook(cvs.window.win, &input_key, &cvs);
	mlx_hook(cvs.window.win, CLOSE_WINDOW_BUTTON_EVENT, 0, &exit_program, &cvs);
	mlx_mouse_hook(cvs.window.win, &input_mouse, &cvs);
	mlx_loop(cvs.window.mlx);
	free_canvas(&cvs);
}