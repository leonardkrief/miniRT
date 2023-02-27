#include "miniRT.h"
#include <time.h>

# define TRANSLATION(x, y, z) matrix_translation(x, y, z)
# define SCALING(x, y, z) matrix_scaling(x, y, z)
# define ROTATION_X(alpha) matrix_rotation_x(alpha)
# define ROTATION_Y(alpha) matrix_rotation_y(alpha)
# define ROTATION_Z(alpha) matrix_rotation_z(alpha)
# define MUL(m1, m2) 		matrix_matrix(m1, m2, 4)

t_world	world_three_spheres(void)
{
	t_world w;
	t_sphere *sp;
	t_plane *pl;
	(void)pl;
	(void)sp;

	ft_memset(&w, 0, sizeof(t_world));
	world_add_light(&w, light_point(point(10, 10, -10), tmp_pixel(1, 1, 1, 0)));

	// floor
	// sp = sphere();
	// transform_sp(sp, SCALING(10, 0.01, 10));
	// sp->mat.color = tmp_pixel(1, 0.9, 0.9, 0);
	// sp->mat.specular = 0;
	// world_add_sphere(&w, sp);

	// // blue
	// pl = plane();
	// transform_object(pl, PLANE_ID, ROTATION_Z(M_PI/2));
	// pl->mat.pattern = pattern(STRIPED_PATTERN, tmp_pixel(0.5, 0, 0.5, 0), tmp_pixel(0, 0.5, 0.5, 0));
	// pl->mat.color = tmp_pixel(0.1, 0.1, 0.9, 0);
	// pl->mat.specular = 0;
	// world_add_plane(&w, pl);

	// // floor
	// pl = plane();
	// // transform_object(pl, PLANE_ID, ROTATION_Z(-M_PI/6));
	// pl->mat.pattern = pattern(tmp_pixel(0.3, 0.3, 0.3, 0), tmp_pixel(0.9, 0.9, 0.9, 0), TEST_PATTERN);
	// // double	a[2] = {-1, 2};
	// // double	b[2] = {3, 7};
	// // double	c[2] = {2, 1};
	// // transform_pattern(&pl->mat.pattern, matrix_shearing(a, b, c));
	// pl->mat.color = tmp_pixel(1, 0, 0.9, 0);
	// pl->mat.specular = 0;
	// world_add_plane(&w, pl);


	// floor
	sp = sphere();
	// transform_object(sp, spANE_ID, ROTATION_Z(-M_PI/6));
	sp->mat.pattern = pattern(tmp_pixel(0.3, 0.6, 0.3, 0), tmp_pixel(0.5, 0.9, 0.2, 0), STRIPED_PATTERN);
	// double	a[2] = {-1, 2};
	// double	b[2] = {3, 7};
	// double	c[2] = {2, 1};
	// transform_pattern(&sp->mat.pattern, matrix_shearing(a, b, c));
	transform_sp(sp, TRANSLATION(0, 1, 0));
	sp->mat.color = tmp_pixel(1, 0, 0.9, 0);
	// sp->mat.specular = 0.7;
	sp->mat.reflective = 0.7;
	world_add_sphere(&w, sp);

	// 	// floor
	// sp = sphere();
	// // transform_object(sp, spANE_ID, ROTATION_Z(-M_PI/6));
	// sp->mat.pattern = pattern(tmp_pixel(0.3, 0.2, 0.3, 0), tmp_pixel(0.9, 0.1, 0.2, 0), PLATINIUM_STRIPED_PATTERN);
	// double	a[2] = {-1, 2};
	// double	b[2] = {3, 7};
	// double	c[2] = {2, 1};
	// transform_pattern(&sp->mat.pattern, matrix_shearing(a, b, c));
	// transform_sp(sp, TRANSLATION(-2, 1, 0));
	// transform_sp(sp, matrix_shearing(a, b, c));
	// sp->mat.color = tmp_pixel(1, 0, 0.3, 0);
	// // sp->mat.specular = 0.7;
	// sp->mat.reflective = 0.7;
	// world_add_sphere(&w, sp);

	return (w);
}

// int	main(void)
// {
// 	t_canvas 	cvs;
// 	t_camera 	c;
// 	t_world		w;
// 	t_all		args;
// 	(void)args;
// 	(void)w;
// 	canvas(&cvs);
// 	w = world_three_spheres();

// 	c = camera(DEFAULT_CAMERA_WIDTH_HI , DEFAULT_CAMERA_HEIGHT_HI , DEFAULT_CAMERA_FOV);
// 	// t_matrix	TRANS = MUL(ROTATION_Y(M_PI / 4), TRANSLATION(0, -2, 5));
// 	// TRANS = TRANSLATION(0,2,-5);
// 	// c.transform = matrix_invert(TRANS, 4);
// 	view_transform(&c, point(3, 3, -5), point(0, 0, 0), vector(0, 1, 0));
// 	all(&args, &cvs, &c, &w);
// 	display_loop(&args);
// }

int	main(int ac, char **av)
{
	t_world		w;
	t_camera	c;

	if (ac >= 2)
		parsing(av[1], &w, &c);
}