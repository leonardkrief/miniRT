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
	world_add_light(&w, light_point(point(-10, 10, -10), tmp_pixel(TMP_PIXEL_WHITE, 0)));
	world_add_light(&w, light_point(point(10, 10, 10), tmp_pixel(TMP_PIXEL_WHITE, 0)));

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

	// magenta
	pl = plane();
	// transform_object(pl, PLANE_ID, ROTATION_Z(-M_PI/6));
	pl->mat.pattern = pattern(THREED_CHECKER_PATTERN, tmp_pixel(0.8, 0, 0.8, 0), tmp_pixel(0, 0.8, 0.8, 0));
	// double	a[2] = {-1, 2};
	// double	b[2] = {3, 7};
	// double	c[2] = {2, 1};
	// transform_pattern(&pl->mat.pattern, matrix_shearing(a, b, c));
	pl->mat.color = tmp_pixel(1, 0, 0.9, 0);
	pl->mat.specular = 0;
	world_add_plane(&w, pl);

	// sp = sphere();
	// sp->mat.pattern = pattern(GRADIENT_PATTERN, tmp_pixel(0.5, 0.4, 0.2, 0), tmp_pixel(0, 0, 0.8, 0));
	// // transform_pattern(&sp->mat.pattern, MUL(ROTATION_Y(M_PI/2), SCALING(0.1, 0.8, 3)));
	// // transform_object(sp, SPHERE_ID, ROTATION_X(M_PI/2));
	// sp->mat.color = tmp_pixel(1, 0.9, 0.9, 0);
	// sp->mat.specular = 0.5;
	// world_add_sphere(&w, sp);

	// // green
	// pl = plane();
	// pl->mat.pattern = pattern(STRIPED_PATTERN, tmp_pixel(0.3, 0, 0.6, 0), tmp_pixel(0, 0.6, 0.3, 0));
	// pl->mat.color = tmp_pixel(0.2, 0.9, 0.2, 0);
	// pl->mat.specular = 0;
	// world_add_plane(&w, pl);

	// // left_wall
	// sp = sphere();
	// transform_sp(sp, MUL(MUL(TRANSLATION(0, 0, 5), MUL(ROTATION_Y(-M_PI/4), ROTATION_X(M_PI/2))), SCALING(10, 0.01, 10)));
	// sp->mat.color = tmp_pixel(1, 0.9, 0.9, 0);
	// sp->mat.specular = 0;
	// world_add_sphere(&w, sp);

	// // right_wall
	// sp = sphere();
	// transform_sp(sp, TRANSLATION(0, 0, 5));
	// transform_sp(sp, ROTATION_Y(M_PI/4));
	// transform_sp(sp, ROTATION_X(M_PI/2));
	// transform_sp(sp, SCALING(10, 0.01, 10));
	// sp->mat.color = tmp_pixel(1, 0.9, 0.9, 0);
	// sp->mat.specular = 0;
	// world_add_sphere(&w, sp);

	// // big green sphere
	// sp = sphere();
	// transform_sp(sp, TRANSLATION(-0.5, 1, 0.5));
	// sp->mat.color = tmp_pixel(0.1, 1, 0.5, 0);
	// sp->mat.diffuse = 0.7;
	// sp->mat.specular = 0.3;
	// world_add_sphere(&w, sp);

	// // small green sphere
	// sp = sphere();
	// transform_sp(sp, TRANSLATION(1.5, 0.5, -0.5));
	// transform_sp(sp, SCALING(0.5, 0.5, 0.5));
	// sp->mat.color = tmp_pixel(0.5, 1, 0.1, 0);
	// sp->mat.diffuse = 0.7;
	// sp->mat.specular = 0.3;
	// world_add_sphere(&w, sp);

	// // smaller yellow sphere
	// sp = sphere();
	// transform_sp(sp, TRANSLATION(-1.5, 0.33, -0.75));
	// transform_sp(sp, SCALING(0.33, 0.33, 0.33));
	// sp->mat.color = tmp_pixel(1, 0.8, 0.1, 0);
	// sp->mat.diffuse = 0.7;
	// sp->mat.specular = 0.3;
	// world_add_sphere(&w, sp);

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
	// t_matrix	TRANS = MUL(ROTATION_Y(M_PI / 4), TRANSLATION(0, -2, 5));
	// TRANS = TRANSLATION(0,2,-5);
	// c.transform = matrix_invert(TRANS, 4);
	view_transform(&c, point(0, 1, -4), point(0, 0, 50), vector(0, 1, 0));
	all(&args, &cvs, &c, &w);
	display_loop(&args);
}
