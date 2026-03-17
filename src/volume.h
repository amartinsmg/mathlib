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

static inline double cubeVol(double side)
{
  if (side < 0)
    return NAN;
  double result;
  result = pow(side, 3);
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

static inline double cuboidVol(double length, double width, double height)
{
  if (width < 0 || length < 0 || height < 0)
    return NAN;
  double result;
  result = length * width * height;
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

static inline double prismVol(double baseArea, double height)
{
  if (baseArea < 0 || height < 0)
    return NAN;
  double result;
  result = baseArea * height;
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

static inline double regularPrismVol(double baseSide, int nOfBaseSides, double height)
{
  double baseArea = regularPolygonArea(baseSide, nOfBaseSides);
  return prismVol(baseArea, height);
}

/**
 * @brief Calculates the volume of a pyramid.
 *
 * @param baseArea The area of the pyramid's base.
 * @param height The height of the pyramid.
 *
 * @return The volume of the pyramid.
 */

static inline double pyramidVol(double baseArea, double height)
{
  if (baseArea < 0 || height < 0)
    return NAN;
  double result;
  result = baseArea * height / 3;
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

static inline double regularPyramidVol(double baseSide, int nOfBaseSides, double height)
{
  double baseArea = regularPolygonArea(baseSide, nOfBaseSides);
  return pyramidVol(baseArea, height);
}

/**
 * @brief Calculates the volume of a cylinder.
 *
 * @param baseRadius The radius of the cylinder's base.
 * @param height The height of the cylinder.
 *
 * @return The volume of the cylinder.
 */

static inline double cylinderVol(double baseRadius, double height)
{
  if (baseRadius < 0 || height < 0)
    return NAN;
  double result;
  result = circleArea(baseRadius) * height;
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

static inline double coneVol(double baseRadius, double height)
{
  if (baseRadius < 0 || height < 0)
    return NAN;
  double result;
  result = circleArea(baseRadius) * height / 3;
  return result;
}

/**
 * @brief Calculates the volume of a sphere.
 * @param radius The radius of the sphere.
 * @return The volume of the sphere.
 */

static inline double sphereVol(double radius)
{
  if (radius < 0)
    return NAN;
  double result;
  result = 4 * M_PI * pow(radius, 3) / 3;
  return result;
}

#endif /* VOLUME_H */
