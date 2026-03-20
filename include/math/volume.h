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

static inline double math_cubeVol(double side)
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

static inline double math_cuboidVol(double length, double width, double height)
{
  if (width < 0 || length < 0 || height < 0)
    return NAN;
  double result = length * width * height;
  return result;
}

/**
 * @brief Calculates the volume of a prism.
 *
 * @param baseArea The area of the prism's base.
 * @param height The height of the prism.
 *
 * @return The volume of the prism.
 */

static inline double math_prismVol(double baseArea, double height)
{
  if (baseArea < 0 || height < 0)
    return NAN;
  double result = baseArea * height;
  return result;
}

/**
 * @brief Calculates the volume of a regular prism.
 *
 * @param baseSide The length of the base side of the prism.
 * @param nOfBaseSides The number of sides of the base polygon of the prism.
 * @param height The height of the prism.
 *
 * @return The volume of the regular prism.
 */

static inline double math_regularPrismVol(double baseSide, int nOfBaseSides, double height)
{
  double baseArea = math_regPolygonArea(baseSide, nOfBaseSides),
         result = math_prismVol(baseArea, height);
  return result;
}

/**
 * @brief Calculates the volume of a pyramid.
 *
 * @param baseArea The area of the pyramid's base.
 * @param height The height of the pyramid.
 *
 * @return The volume of the pyramid.
 */

static inline double math_pyramidVol(double baseArea, double height)
{
  if (baseArea < 0 || height < 0)
    return NAN;
  double result = baseArea * height / 3;
  return result;
}

/**
 * @brief Calculates the volume of a regular pyramid.
 *
 * @param baseSide The length of the base side of the pyramid.
 * @param nOfBaseSides The number of sides of the base polygon of the pyramid.
 * @param height The height of the pyramid.
 *
 * @return The volume of the regular pyramid.
 */

static inline double math_regPyramidVol(double baseSide, int nOfBaseSides, double height)
{
  double baseArea = math_regPolygonArea(baseSide, nOfBaseSides),
         result = math_pyramidVol(baseArea, height);
  return result;
}

/**
 * @brief Calculates the volume of a cylinder.
 *
 * @param baseRadius The radius of the cylinder's base.
 * @param height The height of the cylinder.
 *
 * @return The volume of the cylinder.
 */

static inline double math_cylinderVol(double baseRadius, double height)
{
  if (baseRadius < 0 || height < 0)
    return NAN;
  double result = math_circleArea(baseRadius) * height;
  return result;
}

/**
 * @brief Calculates the volume of a cone.
 *
 * @param baseRadius The radius of the cone's base.
 * @param height The height of the cone.
 *
 * @return The volume of the cone.
 */

static inline double math_coneVol(double baseRadius, double height)
{
  if (baseRadius < 0 || height < 0)
    return NAN;
  double result = math_circleArea(baseRadius) * height / 3;
  return result;
}

/**
 * @brief Calculates the volume of a sphere.
 * @param radius The radius of the sphere.
 * @return The volume of the sphere.
 */

static inline double math_sphereVol(double radius)
{
  if (radius < 0)
    return NAN;
  double result = 4 * M_PI * pow(radius, 3) / 3;
  return result;
}

#endif /* VOLUME_H */
