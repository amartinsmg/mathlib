#ifndef AREA_SURFACE_H
#define AREA_SURFACE_H

#include "area_shape.h"

/**
 * @brief Calculates the surface area of a cube.
 *
 * @param side The length of the side of the cube.
 *
 * @return The surface area of the cube.
 */

static inline double math_cube_area(double side)
{
  if (side < 0)
    return NAN;
  double result = 6 * pow(side, 2);
  return result;
}

/**
 * @brief Calculates the surface area of a cuboid.
 *
 * @param width The width of the cuboid.
 * @param length The length of the cuboid.
 * @param height The height of the cuboid.
 *
 * @return The surface area of the cuboid.
 */

static inline double math_cuboid_area(double width, double length, double height)
{
  if (width < 0 || length < 0 || height < 0)
    return NAN;
  double result = 2 * ((width * length) + (length * height) + (width * height));
  return result;
}

/**
 * @brief Calculates the surface area of a prism.
 *
 * @param base_area The area of the prism's base.
 * @param base_perimeter The perimeter of the prism's base.
 * @param height The height of the prism.
 *
 * @return The surface area of the prism.
 */

static inline double math_prism_area(double base_area, double base_perimeter, double height)
{
  if (base_area < 0 || base_perimeter < 0 || height < 0)
    return NAN;
  double result = 2 * base_area + base_perimeter * height;
  return result;
}

/**
 * @brief Calculates the surface area of a regular prism.
 *
 * @param base_side The length of the base side of the prism.
 * @param n_of_base_sides The number of sides in the base of the prism.
 * @param height The height of the prism.
 *
 * @return The surface area of the prism.
 */

static inline double math_reg_prism_area(double base_side, int n_of_base_sides, double height)
{
  if (base_side < 0 || n_of_base_sides < 0 || height < 0)
    return NAN;
  double base_area = math_reg_polygon_area(base_side, n_of_base_sides),
         base_perimeter = base_side * n_of_base_sides,
         result = math_prism_area(base_area, base_perimeter, height);
  return result;
}

/**
 * @brief Calculates the surface area of a pyramid.
 *
 * @param base_area The area of the pyramid's base.
 * @param base_perimeter The perimeter of the pyramid's base.
 * @param slant_height The slant height of the pyramid.
 *
 * @return The surface area of the pyramid.
 */

static inline double math_pyramid_area(double base_area, double base_perimeter, double slant_height)
{
  if (base_area < 0 || base_perimeter < 0 || slant_height < 0)
    return NAN;
  double result = base_area + base_perimeter * slant_height / 2;
  return result;
}

/**
 * @brief Calculates the surface area of a regular pyramid.
 *
 * @param base_side The length of the base side of the pyramid.
 * @param n_of_base_sides The number of sides in the base of the pyramid.
 * @param height The height of the pyramid.
 *
 * @return The surface area of the pyramid.
 */

static inline double math_reg_pyramid_area(double base_side, int n_of_base_sides, double height)
{
  if (base_side < 0 || n_of_base_sides < 0 || height < 0)
    return NAN;
  double base_area = math_reg_polygon_area(base_side, n_of_base_sides),
         base_perimeter = base_side * n_of_base_sides,
         apothen = base_side / (2 * tan(M_PI / n_of_base_sides)),
         slant_height = math_hypotenuse(apothen, height),
         result = math_pyramid_area(base_area, base_perimeter, slant_height);
  return result;
}

/**
 * @brief Calculates the surface area of a cylinder.
 *
 * @param base_radius The radius of the cylinder's base.
 * @param height The height of the cylinder.
 *
 * @return The surface area of the cylinder.
 */

static inline double math_cylinder_area(double base_radius, double height)
{
  if (base_radius < 0 || height < 0)
    return NAN;
  double result = 2 * M_PI * base_radius * (base_radius + height);
  return result;
}

/**
 * @brief Calculates the surface area of a cone.
 *
 * @param base_radius The radius of the cone's base.
 * @param height The height of the cone.
 *
 * @return The surface area of the cone.
 */

static inline double math_cone_area(double base_radius, double height)
{
  if (base_radius < 0 || height < 0)
    return NAN;
  double result = math_circle_area(base_radius) + M_PI * base_radius * math_hypotenuse(height, base_radius);
  return result;
}

/**
 * @brief Calculates the surface area of a sphere.
 *
 * @param radius The radius of the sphere.
 *
 * @return The surface area of the sphere.
 */

static inline double math_sphere_area(double radius)
{
  if (radius < 0)
    return NAN;
  double result = 4 * M_PI * pow(radius, 2);
  return result;
}

#endif /* AREA_SURFACE_H */
