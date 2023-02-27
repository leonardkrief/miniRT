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
	world_add_light(&w, light_point(point(10, 10, 10), tmp_pixel(1, 1, 1, 0)));

	// floor
	pl = plane();
	pl->mat.pattern = pattern(tmp_pixel(0.3, 0.3, 0.3, 0), tmp_pixel(0.9, 0.9, 0.9, 0), MASTER_PATTERN);
	pl->mat.color = tmp_pixel(1, 0, 0.9, 0);
	pl->mat.specular = 0;
	world_add_plane(&w, pl);

	// back_wall
	pl = plane();
	transform_object(pl, PLANE_ID, MUL(TRANSLATION(0, 0, 12), ROTATION_X(M_PI/2)));
	pl->mat.pattern = pattern(tmp_pixel(0, 0, 0, 0), tmp_pixel(1, 0, 0, 0), PLATINIUM_STRIPED_PATTERN);
	double	a[2] = {-1, 2};
	double	b[2] = {3, 7};
	double	c[2] = {2, 1};
	transform_pattern(&pl->mat.pattern, MUL(SCALING(0.01, 0.2, 0.2), matrix_shearing(a, b, c)));
	pl->mat.color = tmp_pixel(1, 0, 0.9, 0);
	pl->mat.specular = 0.2;
	world_add_plane(&w, pl);

	// inclined_wall
	pl = plane();
	transform_object(pl, PLANE_ID, MUL(TRANSLATION(-5, 0, 0), ROTATION_Z(3.5 * M_PI / 2)));
	pl->mat.pattern = pattern(tmp_pixel(0, 0, 0.8, 0), tmp_pixel(0, 0.7, 0.2, 0), GRADIENT_PATTERN);
	transform_pattern(&pl->mat.pattern, SCALING(0.5, 0.5, 0.5));
	pl->mat.color = tmp_pixel(1, 0, 0.9, 0);
	pl->mat.specular = 0.2;
	world_add_plane(&w, pl);

	// normal_ball
	sp = sphere();
	sp->mat.pattern = pattern(tmp_pixel(0.2, 0.2, 0, 0), tmp_pixel(0.8, 0.8, 0, 0), MASTER_PATTERN);
	transform_pattern(&sp->mat.pattern, SCALING(0.01, 0.01, 0.01));
	transform_object(sp, SPHERE_ID, TRANSLATION(0, 1, 0));
	sp->mat.color = tmp_pixel(1, 0.9, 0.9, 0);
	sp->mat.diffuse = 1;
	sp->mat.specular = 0;
	world_add_sphere(&w, sp);

	// small_ball
	sp = sphere();
	sp->mat.pattern = pattern(tmp_pixel(1, 0.2, 0, 0), tmp_pixel(0.2, 0, 1, 0), GRADIENT_PATTERN);
	transform_pattern(&sp->mat.pattern, MUL(SCALING(0.01, 0.01, 0.01), ROTATION_Z(0.3 * M_PI)));
	transform_object(sp, SPHERE_ID, MUL(TRANSLATION(2, 0.5, 1), SCALING(0.5, 0.5, 0.5)));
	sp->mat.color = tmp_pixel(1, 0.9, 0.9, 0);
	sp->mat.specular = 0.6;
	sp->mat.diffuse = 0.3;
	world_add_sphere(&w, sp);

	// big_ball
	sp = sphere();
	sp->mat.pattern = pattern(tmp_pixel(0.8, 0.4, 0.1, 0), tmp_pixel(0.1, 0.8, 0.4, 0), RING_PATTERN);
	transform_pattern(&sp->mat.pattern, MUL(SCALING(0.01, 0.01, 0.01), ROTATION_Z(0.3 * M_PI)));
	transform_object(sp, SPHERE_ID, MUL(TRANSLATION(1, 2, 5), SCALING(2, 2, 2)));
	sp->mat.color = tmp_pixel(1, 0.9, 0.9, 0);
	sp->mat.specular = 0.3;
	sp->mat.diffuse = 0.7;
	world_add_sphere(&w, sp);

	return (w);
}

int	main(void)
{
	t_canvas 	cvs;
	t_camera 	c;
	t_world		w;
	t_all		args;
	(void)args;
	(void)w;
	canvas(&cvs);
	w = world_three_spheres();

	c = camera(DEFAULT_CAMERA_WIDTH_HI , DEFAULT_CAMERA_HEIGHT_HI , DEFAULT_CAMERA_FOV);
	view_transform(&c, point(3, 2, -3), point(0, 0, 2), vector(0, 1, 0));
	all(&args, &cvs, &c, &w);
	display_loop(&args);
}
