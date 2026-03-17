#ifndef AREA_SURFACE_H
#define AREA_SURFACE_H

#include <math.h>
#include "area_shape.h"

/**
 * @brief Calculates the surface area of a cube.
 *
 * @param side The length of the side of the cube.
 *
 * @return The surface area of the cube.
 */

static inline double cubeArea(double side)
{
  if (side < 0)
    return NAN;
  double result;
  result = 6 * pow(side, 2);
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

static inline double cuboidArea(double width, double length, double height)
{
  if (width < 0 || length < 0 || height < 0)
    return NAN;
  double result;
  result = 2 * ((width * length) + (length * height) + (width * height));
  return result;
}

/**
 * @brief Calculates the surface area of a prism.
 *
 * @param baseArea The area of the prism's base.
 * @param basePerimeter The perimeter of the prism's base.
 * @param height The height of the prism.
 *
 * @return The surface area of the prism.
 */

static inline double prismArea(double baseArea, double basePerimeter, double height)
{
  if (baseArea < 0 || basePerimeter < 0 || height < 0)
    return NAN;
  double result;
  result = 2 * baseArea + basePerimeter * height;
  return result;
}

/**
 * @brief Calculates the surface area of a regular prism.
 *
 * @param baseSide The length of the base side of the prism.
 * @param nOfBaseSides The number of sides in the base of the prism.
 * @param height The height of the prism.
 *
 * @return The surface area of the prism.
 */

static inline double regularPrismArea(double baseSide, int nOfBaseSides, double height)
{
  if (baseSide < 0 || nOfBaseSides < 0 || height < 0)
    return NAN;
  double baseArea = regularPolygonArea(baseSide, nOfBaseSides),
         basePerimeter = baseSide * nOfBaseSides;
  return prismArea(baseArea, basePerimeter, height);
}

/**
 * @brief Calculates the surface area of a pyramid.
 *
 * @param baseArea The area of the pyramid's base.
 * @param basePerimeter The perimeter of the pyramid's base.
 * @param slantHeight The slant height of the pyramid.
 *
 * @return The surface area of the pyramid.
 */

static inline double pyramidArea(double baseArea, double basePerimeter, double slantHeight)
{
  if (baseArea < 0 || basePerimeter < 0 || slantHeight < 0)
    return NAN;
  double result;
  result = baseArea + basePerimeter * slantHeight / 2;
  return result;
}

/**
 * @brief Calculates the surface area of a regular pyramid.
 *
 * @param baseSide The length of the base side of the pyramid.
 * @param nOfBaseSides The number of sides in the base of the pyramid.
 * @param height The height of the pyramid.
 *
 * @return The surface area of the pyramid.
 */

static inline double regularPyramidArea(double baseSide, int nOfBaseSides, double heigth)
{
  if (baseSide < 0 || nOfBaseSides < 0 || heigth < 0)
    return NAN;
  double baseArea = regularPolygonArea(baseSide, nOfBaseSides),
         basePerimeter = baseSide * nOfBaseSides,
         apothen = baseSide / (2 * tan(M_PI / nOfBaseSides)),
         slantHeight = hypotenuse(apothen, heigth);
  return pyramidArea(baseArea, basePerimeter, slantHeight);
}

/**
 * @brief Calculates the surface area of a cylinder.
 * 
 * @param baseRadius The radius of the cylinder's base.
 * @param height The height of the cylinder.
 * 
 * @return The surface area of the cylinder.
 */

static inline double cylinderArea(double baseRadius, double height)
{
  if (baseRadius < 0 || height < 0)
    return NAN;
  double result;
  result = 2 * M_PI * baseRadius * (baseRadius + height);
  return result;
}

/**
 * @brief Calculates the surface area of a cone.
 * 
 * @param baseRadius The radius of the cone's base.
 * @param height The height of the cone.
 * 
 * @return The surface area of the cone.
 */

static inline double coneArea(double baseRadius, double height)
{
  if (baseRadius < 0 || height < 0)
    return NAN;
  double result;
  result = circleArea(baseRadius) + M_PI * baseRadius * hypotenuse(height, baseRadius);
  return result;
}

/**
 * @brief Calculates the surface area of a sphere.
 * 
 * @param radius The radius of the sphere.
 * 
 * @return The surface area of the sphere.
 */

static inline double sphereArea(double radius)
{
  if (radius < 0)
    return NAN;
  double result;
  result = 4 * M_PI * pow(radius, 2);
  return result;
}

#endif /* AREA_SURFACE_H */
