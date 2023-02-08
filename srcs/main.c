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
	t_tuple a, hit, eye, normal;
	
	t_sphere	*sp = sphere(point(0, 0, 0), 1);
	sp->mat.color = tmp_pixel(1, 0.2, 1, 0);
	
	t_light	l = point_light(point(-10, 10, -10), tmp_pixel(1, 1, 1, 0));

	// t_matrix	m;
	t_raytracer	rt;
	t_tmp_pixel	color;

	t_tuple	or = point(0, 0, -5);
	// transform_sp(sp, &m);
	for(i = 0; i < WIDTH; i++)
	{
		for(j = 0; j < HEIGHT; j++)
		{
			a = tuple_sub(pixel_to_point(&cvs->image, i, j), or);
			rt = raytracer(or, a);
			eye = tuple_neg(rt.ray.direction);
			intersection_sp(&rt, sp);
			hit = position(rt.ray, rt.itr_front.t);
			normal = normal_at_sp(sp, hit);
			color = lighting(sp->mat, l, hit, eye, normal);
			if (rt.itr_front.id != 0)
			{
				put_pixel(&cvs->image, i, j, pixel(color.r * 255, color.g * 255, color.b * 255, color.a * 255));
				// pixel_print(pixel(color.a * 255, color.r * 255, color.g * 255, color.b * 255), "p1: ");
			}
			else
				put_pixel(&cvs->image, i, j, pixel(100, 100, 100, 255));
		}
	}
}

int	main(void)
{
	t_canvas	cvs;

	canvas(&cvs);
	make_scene(&cvs);
	mlx_put_image_to_window(cvs.window.mlx, cvs.window.win, cvs.image.img, 0, 0);
	mlx_key_hook(cvs.window.win, &input_key, &cvs);
	mlx_hook(cvs.window.win, CLOSE_WINDOW_KEY_EVENT, 0, &free_canvas, &cvs);
	mlx_mouse_hook(cvs.window.win, &input_mouse, &cvs);
	mlx_loop(cvs.window.mlx);
	free_canvas(&cvs);
}