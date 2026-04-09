#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif /* M_PI */

#ifndef AREA_SHAPE_H
#define AREA_SHAPE_H

#include <math.h>
#include "trigonometry.h"

/**
 * @brief Calculate the area of a triangle given the base and height.
 *
 * @param base The length of the base of the triangle.
 * @param height The height of the triangle.
 *
 * @return The area of the triangle.
 */

static inline double math_triangleArea1(double base, double height)
{
  if (base < 0 || height <= 0)
    return NAN;
  double result = base * height / 2;
  return result;
}

/**
 * @brief Calculate the area of a triangle given two sides and an angle between them.
 *
 * @param sideA The length of side A of the triangle.
 * @param sideB The length of side B of the triangle.
 * @param angleGama The angle between sides A and B, in radians.
 *
 * @return The area of the triangle.
 */

static inline double math_triangleArea2(double sideA, double sideB, double angleGama)
{
  if (sideA < 0 || sideB < 0 || angleGama < 0 || angleGama > M_PI)
    return NAN;
  double result = sideA * sideB * sin(angleGama) / 2;
  return result;
}

/**
 * @brief Calculate the area of a triangle given three sides.
 *
 * @param sideA The length of side A of the triangle.
 * @param sideB The length of side B of the triangle.
 * @param sideC The length of side C of the triangle.
 *
 * @return The area of the triangle.
 */

static inline double math_triangleArea3(double sideA, double sideB, double sideC)
{
  if (sideA < 0 || sideB < 0 || sideC < 0)
    return NAN;
  double result, s;
  s = (sideA + sideB + sideC) / 2;
  result = sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
  return result;
}

/**
 * @brief Calculate the area of a square.
 *
 * @param side The length of the side of the square.
 *
 * @return The area of the square.
 */

static inline double math_squareArea(double side)
{
  if (side < 0)
    return NAN;
  double result = pow(side, 2);
  return result;
}

/**
 * @brief Calculate the area of a rectangle.
 *
 * @param width The width of the rectangle.
 * @param length The length of the rectangle.
 *
 * @return The area of the rectangle.
 */

static inline double math_rectangleArea(double width, double length)
{
  if (width < 0 || length < 0)
    return NAN;
  double result = width * length;
  return result;
}

/**
 * @brief Calculate the area of a rhombus given the lengths of the larger diagonal and smaller diagonal.
 *
 * @param largerDiagonal The length of the larger diagonal of the rhombus.
 * @param smallerDiagonal The length of the smaller diagonal of the rhombus.
 *
 * @return The area of the rhombus.
 */

static inline double math_rhombusArea(double largerDiagonal, double smallerDiagonal)
{
  if (largerDiagonal < 0 || smallerDiagonal < 0)
    return NAN;
  double result = largerDiagonal * smallerDiagonal / 2;
  return result;
}

/**
 *  @brief Calculate the area of a parallelogram given the base and height.
 *
 *  @param base The length of the base of the parallelogram.
 *  @param height The height of the parallelogram.
 *
 *  @return The area of the parallelogram.
 */

static inline double math_parallelogramArea1(double base, double height)
{
  if (base < 0 || height < 0)
    return NAN;
  double result = base * height;
  return result;
}

/**
 * @brief Calculate the area of a parallelogram given the lengths of two sides and the angle between them.
 *
 * @param sideA The length of one side of the parallelogram.
 * @param sideB The length of the adjacent side of the parallelogram.
 * @param angleBetweenAB The angle between sideA and sideB, in radians.
 *
 * @return The area of the parallelogram.
 */

static inline double math_parallelogramArea2(double sideA, double sideB, double angleBeetweenAB)
{
  if (sideA < 0 || sideB < 0 || angleBeetweenAB < 0 || angleBeetweenAB > M_PI)
    return NAN;
  double result = sideA * sideB * sin(angleBeetweenAB);
  return result;
}

/**
 * @brief Calculate the area of a trapezoid given the lengths of the larger base, smaller base, and height.
 *
 * @param largerBase The length of the larger base of the trapezoid.
 * @param smallerBase The length of the smaller base of the trapezoid.
 * @param height The height of the trapezoid.
 *
 * @return The area of the trapezoid.
 */

static inline double math_trapezoidArea(double largerBase, double smallerBase, double height)
{
  if (largerBase < 0 || smallerBase < 0 || height < 0)
    return NAN;
  double result = (largerBase + smallerBase) * height / 2;
  return result;
}

/**
 *  @brief Calculate the area of a regular polygon.
 *
 *  @param side The length of one side of the polygon.
 *  @param nOfSides The number of sides of the polygon.
 *
 *  @return The area of the regular polygon.
 */

static inline double math_regPolygonArea(double side, int nOfSides)
{
  if (side < 0 || nOfSides < 3)
    return NAN;
  double apothen, perimeter, result;
  apothen = side / (2 * tan(M_PI / nOfSides));
  perimeter = side * nOfSides;
  result = perimeter * apothen / 2;
  return result;
}

/**
 * @brief Calculate the area of a circle given the radius.
 *
 * @param radius The radius of the circle.
 *
 * @return The area of the circle.
 */

static inline double math_circleArea(double radius)
{
  if (radius < 0)
    return NAN;
  double result = M_PI * pow(radius, 2);
  return result;
}

/**
 * @brief Calculate the area of a circular sector given the central angle and radius.
 *
 * @param angle The central angle of the circular sector, in radians.
 * @param radius The radius of the circular sector.
 *
 * @return The area of the circular sector.
 */

static inline double math_circularSectorArea1(double angle, double radius)
{
  if (radius < 0 || angle < 0)
    return NAN;
  double result = angle * pow(radius, 2) / 2;
  return result;
}

/**
 * @brief Calculate the area of a circular sector given the arc length and radius.
 *
 * @param arc The length of the arc of the circular sector.
 * @param radius The radius of the circular sector.
 *
 * @return The area of the circular sector.
 */

static inline double math_circularSectorArea2(double arc, double radius)
{
  if (radius < 0 || arc < 0)
    return NAN;
  double result = arc * radius / 2;
  return result;
}

/**
 * @brief Calculate the area of an ellipse given the semi-major axis and semi-minor axis.
 *
 * @param semiMajorAxis The length of the semi-major axis of the ellipse.
 * @param semiMinorAxis The length of the semi-minor axis of the ellipse.
 *
 * @return The area of the ellipse.
 */

static inline double math_ellipseArea(double semiMajorAxis, double semiMinorAxis)
{
  if (semiMajorAxis < 0 || semiMinorAxis < 0)
    return NAN;
  double result = M_PI * semiMajorAxis * semiMinorAxis;
  return result;
}

#endif /* AREA_SHAPE_H */
