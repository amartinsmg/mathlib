#ifndef VOLUME_H
#define VOLUME_H

#include "area_shape.h"
#include <math.h>

/**
 * @brief Calculates the volume of a cube.
 *
 * @param side The length of the cube's side.
 *
 * @return The volume of the cube.
 */

static inline double math_cube_vol(double side)
{
  if (side < 0)
    return NAN;
  double result = pow(side, 3);
  return result;
}

/**
 * @brief Calculates the volume of a cuboid.
 *
 * @param length The length of the cuboid.
 * @param width The width of the cuboid.
 * @param height The height of the cuboid.
 *
 * @return The volume of the cuboid.
 */

static inline double math_cuboid_vol(double length, double width, double height)
{
  if (width < 0 || length < 0 || height < 0)
    return NAN;
  double result = length * width * height;
  return result;
}

/**
 * @brief Calculates the volume of a prism.
 *
 * @param base_area The area of the prism's base.
 * @param height The height of the prism.
 *
 * @return The volume of the prism.
 */

static inline double math_prism_vol(double base_area, double height)
{
  if (base_area < 0 || height < 0)
    return NAN;
  double result = base_area * height;
  return result;
}

/**
 * @brief Calculates the volume of a regular prism.
 *
 * @param base_side The length of the base side of the prism.
 * @param n_of_base_sides The number of sides of the base polygon of the prism.
 * @param height The height of the prism.
 *
 * @return The volume of the regular prism.
 */

static inline double math_reg_prism_vol(double base_side, int n_of_base_sides, double height)
{
  double base_area = math_reg_polygon_area(base_side, n_of_base_sides),
         result = math_prism_vol(base_area, height);
  return result;
}

/**
 * @brief Calculates the volume of a pyramid.
 *
 * @param base_area The area of the pyramid's base.
 * @param height The height of the pyramid.
 *
 * @return The volume of the pyramid.
 */

static inline double math_pyramid_vol(double base_area, double height)
{
  if (base_area < 0 || height < 0)
    return NAN;
  double result = base_area * height / 3;
  return result;
}

/**
 * @brief Calculates the volume of a regular pyramid.
 *
 * @param base_side The length of the base side of the pyramid.
 * @param n_of_base_sides The number of sides of the base polygon of the pyramid.
 * @param height The height of the pyramid.
 *
 * @return The volume of the regular pyramid.
 */

static inline double math_reg_pyramid_vol(double base_side, int n_of_base_sides, double height)
{
  double base_area = math_reg_polygon_area(base_side, n_of_base_sides),
         result = math_pyramid_vol(base_area, height);
  return result;
}

/**
 * @brief Calculates the volume of a cylinder.
 *
 * @param base_radius The radius of the cylinder's base.
 * @param height The height of the cylinder.
 *
 * @return The volume of the cylinder.
 */

static inline double math_cylinder_vol(double base_radius, double height)
{
  if (base_radius < 0 || height < 0)
    return NAN;
  double result = math_circle_area(base_radius) * height;
  return result;
}

/**
 * @brief Calculates the volume of a cone.
 *
 * @param base_radius The radius of the cone's base.
 * @param height The height of the cone.
 *
 * @return The volume of the cone.
 */

static inline double math_cone_vol(double base_radius, double height)
{
  if (base_radius < 0 || height < 0)
    return NAN;
  double result = math_circle_area(base_radius) * height / 3;
  return result;
}

/**
 * @brief Calculates the volume of a sphere.
 * @param radius The radius of the sphere.
 * @return The volume of the sphere.
 */

static inline double math_sphere_vol(double radius)
{
  if (radius < 0)
    return NAN;
  double result = 4 * M_PI * pow(radius, 3) / 3;
  return result;
}

#endif /* VOLUME_H */
