#include "miniRT.h"
#include <time.h>

// ecran dans le plan (1,0,0)(0,1,0) qui contient le point (0,0,-3)
// je me situe en (0,0,-5)
// je dois lancer les rayons avec un angle qui varie:
// direction (0,0,1) qui doit aller toucher chacun des pixels
// i determine l'angle u dans le plan xz
// j determine l'angle v dans le plan yz

void	put_ray_to_image(t_image *img, t_ray r, int i, int j)
{
	if (r.itr_front->t > 0)
		put_pixel(img, i, j, pixel(255, 0, 255, 0));
}

# define TRANSLATION(x, y, z) matrix_translation(x, y, z)
# define SCALING(x) matrix_scaling(x, x, x)

void	get_infos(int i, int j, t_sphere *sp, t_light	l, t_canvas *cvs, t_tuple or)
{
	t_tuple a, hit, eye, normal;
	
	t_ray	rt;
	t_tmp_pixel	color;

	a = tuple_sub(pixel_to_point(&cvs->image, i, j), or);
	rt = ray(or, a);
	eye = tuple_neg(rt.direction);
	intersection_sp(&rt, sp);
	hit = position(rt, rt.itr_front->t);
	normal = normal_at_sp(sp, hit);
	color = lighting(sp->mat, l, hit, eye, normal);
	printf("      i: %3d  j: %3d\n", i, j);
	t_tuple t = pixel_to_point(&cvs->image, i, j);
	printf("      x: %.2f  y: %.2f\n", t.x, t.y);
	tuple_print(hit, "hit:  ");
	tuple_print(normal, "nrml: ");
	tmp_pixel_print(color, "pix:  ");
}


void	make_scene(t_canvas *cvs)
{
	int	i, j;
	t_tuple a, hit, eye, normal;
	
	t_sphere	*sp = sphere();
	sp->mat.color = tmp_pixel(1, 0.2, 1, 0);
	
	t_light	l = light_point(point(-10, 10, -10), tmp_pixel(1, 1, 1, 0));

	t_matrix	m = SCALING(2);
	t_ray	ry;
	t_tmp_pixel	color;

	t_tuple	or = point(0, 0, -5);
	transform_sp(sp, &m);
	clock_t		start, end;
	start = clock();
	for(i = 0; i < WIDTH; i++)
	{
		for(j = 0; j < HEIGHT; j++)
		{
			a = tuple_sub(pixel_to_point(&cvs->image, i, j), or);
			ry = ray(or, a);
			eye = tuple_neg(ry.direction);
			intersection_sp(&ry, sp);
			if (ry.itr_front)
			{
				hit = position(ry, ry.itr_front->t);
				normal = normal_at_sp(sp, hit);
				color = lighting(sp->mat, l, hit, eye, normal);
			// printf("      i: %3d  j: %3d\n", i, j);
			// t_tuple t = pixel_to_point(&cvs->image, i, j);
			// printf("      x: %3.2f  y: %3.2f\n", t.x, t.y);
			// tuple_print(hit, "hit:  ");
			// tuple_print(normal, "nrml: ");
			// tmp_pixel_print(color, "pix:  ");
				put_pixel(&cvs->image, i, j, tmp_pixel_to_pixel(color));
				// pixel_print(pixel(color.a * 255, color.r * 255, color.g * 255, color.b * 255), "p1: ");
			}
			else
				put_pixel(&cvs->image, i, j, pixel(100, 100, 100, 0));
		}
	}
	end = clock();
	printf("time: %.3fs\n", (double)(end - start) / CLOCKS_PER_SEC);
}

int	main(void)
{
	t_canvas	cvs;

	canvas(&cvs);
	make_scene(&cvs);
	mlx_put_image_to_window(cvs.window.mlx, cvs.window.win, cvs.image.img, 0, 0);
	SCREENSHOT();
	mlx_key_hook(cvs.window.win, &input_key, &cvs);
	mlx_hook(cvs.window.win, CLOSE_WINDOW_BUTTON_EVENT, 0, &exit_program, &cvs);
	mlx_mouse_hook(cvs.window.win, &input_mouse, &cvs);
	mlx_loop(cvs.window.mlx);
	free_canvas(&cvs);
}