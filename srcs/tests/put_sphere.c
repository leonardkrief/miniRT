#include "miniRT.h"

// ecran dans le plan (1,0,0)(0,1,0) qui contient le point (0,0,-3)
// je me situe en (0,0,-5)
// je dois lancer les rayons avec un angle qui varie:
// direction (0,0,1) qui doit aller toucher chacun des pixels
// i determine l'angle u dans le plan xz
// j determine l'angle v dans le plan yz

void	put_raytracer_to_image(t_image *img, t_raytracer rt, int i, int j)
{
	if (rt.itr_front.t > 0)
		put_pixel(img, i, j, pixel(255, 0, 255, 0));
}

# define TRANSLATION(x, y, z) matrix_translation(x, y, z)
# define SCALING(x) matrix_scaling(x, x, x)

void	make_scene(t_canvas *cvs)
{
	int	i, j;
	t_tuple a, light;
	t_raytracer	rt;
	t_sphere	*sp;
	t_matrix	m;

	m = TRANSLATION(0, 1, 0);
	sp = sphere(point(0, 0, 0), 1);
	transform_sp(sp, &m);
	light = point(0, 0, -5);
	for(i = 0; i < WIDTH; i++)
	{
		for(j = 0; j < HEIGHT; j++)
		{
			a = pixel_to_point(&cvs->image, i, j);
			a = tuple_sub(a, light);
			a = tuple_normalize(a);
			rt = raytracer(light, a);
			intersection_sp(&rt, sp);
			if (rt.itr_front.id != 0)
				put_pixel(&cvs->image, i, j, pixel(255, 0, 255, 0));
		}
	}
}


int	main(void)
{
	t_canvas	cvs;

	canvas(&cvs);
	make_scene(&cvs);
	mlx_put_image_to_window(cvs.window.mlx, cvs.window.win, cvs.image.img, 0, 0);
	mlx_loop(cvs.window.mlx);
}