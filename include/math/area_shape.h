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

static inline double math_triangle_area_1(double base, double height)
{
  if (base < 0 || height <= 0)
    return NAN;
  double result = base * height / 2;
  return result;
}

/**
 * @brief Calculate the area of a triangle given two sides and an angle between them.
 *
 * @param side_A The length of side A of the triangle.
 * @param side_B The length of side B of the triangle.
 * @param angle_gama The angle between sides A and B, in radians.
 *
 * @return The area of the triangle.
 */

static inline double math_triangle_area_2(double side_A, double side_B, double angle_gama)
{
  if (side_A < 0 || side_B < 0 || angle_gama < 0 || angle_gama > M_PI)
    return NAN;
  double result = side_A * side_B * sin(angle_gama) / 2;
  return result;
}

/**
 * @brief Calculate the area of a triangle given three sides.
 *
 * @param side_A The length of side A of the triangle.
 * @param side_B The length of side B of the triangle.
 * @param side_C The length of side C of the triangle.
 *
 * @return The area of the triangle.
 */

static inline double math_triangle_area_3(double side_A, double side_B, double side_C)
{
  if (side_A < 0 || side_B < 0 || side_C < 0)
    return NAN;
  double result, s;
  s = (side_A + side_B + side_C) / 2;
  result = sqrt(s * (s - side_A) * (s - side_B) * (s - side_C));
  return result;
}

/**
 * @brief Calculate the area of a square.
 *
 * @param side The length of the side of the square.
 *
 * @return The area of the square.
 */

static inline double math_square_area(double side)
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

static inline double math_rectangle_area(double width, double length)
{
  if (width < 0 || length < 0)
    return NAN;
  double result = width * length;
  return result;
}

/**
 * @brief Calculate the area of a rhombus given the lengths of the larger diagonal and smaller diagonal.
 *
 * @param larger_diagonal The length of the larger diagonal of the rhombus.
 * @param smaller_diagonal The length of the smaller diagonal of the rhombus.
 *
 * @return The area of the rhombus.
 */

static inline double math_rhombus_area(double larger_diagonal, double smaller_diagonal)
{
  if (larger_diagonal < 0 || smaller_diagonal < 0)
    return NAN;
  double result = larger_diagonal * smaller_diagonal / 2;
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

static inline double math_parallelogram_area_1(double base, double height)
{
  if (base < 0 || height < 0)
    return NAN;
  double result = base * height;
  return result;
}

/**
 * @brief Calculate the area of a parallelogram given the lengths of two sides and the angle between them.
 *
 * @param side_A The length of one side of the parallelogram.
 * @param side_B The length of the adjacent side of the parallelogram.
 * @param angle_between_A_B The angle between side_A and side_B, in radians.
 *
 * @return The area of the parallelogram.
 */

static inline double math_parallelogram_area_2(double side_A, double side_B, double angle_between_A_B)
{
  if (side_A < 0 || side_B < 0 || angle_between_A_B < 0 || angle_between_A_B > M_PI)
    return NAN;
  double result = side_A * side_B * sin(angle_between_A_B);
  return result;
}

/**
 * @brief Calculate the area of a trapezoid given the lengths of the larger base, smaller base, and height.
 *
 * @param larger_base The length of the larger base of the trapezoid.
 * @param smaller_base The length of the smaller base of the trapezoid.
 * @param height The height of the trapezoid.
 *
 * @return The area of the trapezoid.
 */

static inline double math_trapezoid_area(double larger_base, double smaller_base, double height)
{
  if (larger_base < 0 || smaller_base < 0 || height < 0)
    return NAN;
  double result = (larger_base + smaller_base) * height / 2;
  return result;
}

/**
 *  @brief Calculate the area of a regular polygon.
 *
 *  @param side The length of one side of the polygon.
 *  @param n_of_sides The number of sides of the polygon.
 *
 *  @return The area of the regular polygon.
 */

static inline double math_reg_polygon_area(double side, int n_of_sides)
{
  if (side < 0 || n_of_sides < 3)
    return NAN;
  double apothen, perimeter, result;
  apothen = side / (2 * tan(M_PI / n_of_sides));
  perimeter = side * n_of_sides;
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

static inline double math_circle_area(double radius)
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

static inline double math_circular_sector_area_1(double angle, double radius)
{
  if (radius < 0 || angle < 0 || angle > 2 * M_PI)
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

static inline double math_circular_sector_area_2(double arc, double radius)
{
  if (radius < 0 || arc < 0 || arc > M_PI * 2 * radius)
    return NAN;
  double result = arc * radius / 2;
  return result;
}

/**
 * @brief Calculate the area of an ellipse given the semi-major axis and semi-minor axis.
 *
 * @param semi_major_axis The length of the semi-major axis of the ellipse.
 * @param semi_minor_axis The length of the semi-minor axis of the ellipse.
 *
 * @return The area of the ellipse.
 */

static inline double math_ellipse_area(double semi_major_axis, double semi_minor_axis)
{
  if (semi_major_axis < 0 || semi_minor_axis < 0)
    return NAN;
  double result = M_PI * semi_major_axis * semi_minor_axis;
  return result;
}

#endif /* AREA_SHAPE_H */
