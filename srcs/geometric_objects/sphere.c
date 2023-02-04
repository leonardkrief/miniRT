/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkrief <lkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 05:12:09 by lkrief            #+#    #+#             */
/*   Updated: 2023/02/04 06:00:27 by lkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometric_objects.h"


t_sphere	sphere(t_tuple origin, double radius)
{
	t_sphere	sphere;

	ft_memset(&sphere, 0, sizeof(sphere));
	if (!eq(origin.w, 1))
	{
		ft_puterror(ERROR_SPHERE, ": origin should be a point");
		return (sphere);
	}
	if (radius <= 0)
	{
		ft_puterror(ERROR_SPHERE, ": radius should be positive");
		return (sphere);
	}
	sphere.origin = origin;
	sphere.radius = radius;
	return (sphere);
}

void	*sp_intersection(t_ray ray, t_sphere sp, t_intersection *intersection)
{
	t_tuple			sp_to_ray;
	double			a;
	double			b;
	double			c;
	double			discriminant;

	sp_to_ray = vector(sub(ray.origin, sp.origin));
	a = dotprod(ray.direction, ray.direction);
	b = 2 * dotprod(ray.direction, sp_to_ray);
	c = 2 * dotprod(sp_to_ray, sp_to_ray) - 1;
	discriminant = b * b - 4 * a * c;
	ft_memset(intersection, 0, sizeof (intersection));
	if (discriminant < 0)
		return (intersection);
	intersection.t1 = (-b - sqrt(discriminant)) / (2 * a);
	intersection.t2 = (-b + sqrt(discriminant)) / (2 * a);
}

// # the vector from the sphere's center, to the ray origin
// # remember: the sphere is centered at the world origin
// sphere_to_ray ← ray.origin - point(0, 0, 0)
// a ← dot(ray.direction, ray.direction)
// b ← 2 * dot(ray.direction, sphere_to_ray)
// c ← dot(sphere_to_ray, sphere_to_ray) - 1
// discriminant ← b² - 4 * a * c
// That discriminant value is the key. If it’s negative, then the ray misses and no
// intersections occur between the sphere and the ray.
// if discriminant < 0 then
// return ()
// end if