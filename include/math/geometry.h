#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "area_surface.h"
#include "statistics.h"
#include "volume.h"

/**
 * @brief Converts degrees to radians.
 *
 * @param degrees The angle in degrees.
 *
 * @return The angle converted to radians.
 */

static inline double math_deg_to_rad(double degrees)
{
  double result = degrees / 180 * M_PI;
  return result;
}

/**
 * @brief Converts radians to degrees.
 *
 * @param radians The angle in radians.
 *
 * @return The angle converted to degrees.
 */

static inline double math_rad_to_deg(double radians)
{
  double result = radians / M_PI * 180;
  return result;
}

/**
 * @brief Structure representing a point in 2D space.
 */

typedef struct
{
  double x;
  double y;
} Point;

/**
 * @brief Calculates the distance between two points.
 *
 * @param a The first point.
 * @param b The second point.
 *
 * @return The distance between the two points.
 */

static inline double math_distance_points(Point a, Point b)
{
  double result = sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2));
  return result;
}

/**
 * @brief Calculates the midpoint between two points.
 *
 * @param a The first point.
 * @param b The second point.
 *
 * @return The midpoint between the two points.
 */

static inline Point math_midpoint(Point a, Point b)
{
  Point result;
  double x[2] = {a.x, b.x},
         y[2] = {a.y, b.y};
  result.x = math_mean(x, 2);
  result.y = math_mean(y, 2);
  return result;
}

/**
 * @brief Calculates the slope of a line.
 *
 * @param a The first point.
 * @param b The second point.
 *
 * @return The slope of the line.
 */

static inline double math_slope_line(Point a, Point b)
{
  if (a.x == b.x)
    return NAN;
  double result = (b.y - a.y) / (b.x - a.x);
  return result;
}

/**
 * @brief Calculates the angle of incline of a line.
 *
 * @param a The first point.
 * @param b The second point.
 *
 * @return The angle of incline of the line in radians.
 */

static inline double math_inclination_line(Point a, Point b)
{
  double result = atan(math_slope_line(a, b));
  return result;
}

/**
 * @brief Calculates the y-intercept of a line.
 *
 * @param a The first point.
 * @param b The second point.
 *
 * @return The y-intercept of the line.
 */

static inline double math_line_y_intercept(Point a, Point b)
{
  if (a.x == b.x)
    return NAN;
  double result = a.y - math_slope_line(a, b) * a.x;
  return result;
}

/**
 * @brief Calculates the distance between a point and a line.
 *
 * @param inclination The inclination (slope) of the line.
 * @param y_intercept The y-intercept of the line.
 * @param p The point.
 *
 * @return The distance between the point and the line.
 */

static inline double math_distance_point_line(double inclination, double y_intercept, Point p)
{
  double result = fabs(inclination * p.x - p.y + y_intercept) /
           sqrt(pow(inclination, 2) + 1);
  return result;
}

/**
 * @brief Calculates the perimeter of a circle.
 *
 * @param radius The radius of the circle.
 *
 * @return The perimeter of the circle.
 */

static inline double math_circle_perimeter(double radius)
{
  if (radius < 0)
    return NAN;
  double result = 2 * M_PI * radius;
  return result;
}

/**
 * @brief Calculates the number of diagonals in a polygon.
 *
 * @param n_of_sides The number of sides of the polygon.
 *
 * @return The number of diagonals in the polygon.
 */

static inline int math_polygon_diagonals(int n_of_sides)
{
  if (n_of_sides < 3)
    return 0;
  int result;
  result = n_of_sides * (n_of_sides - 3) / 2;
  return result;
}

/**
 * @brief Calculates the sum of interior angles in a convex polygon.
 *
 * @param n_of_sides The number of sides of the polygon.
 *
 * @return The sum of interior angles in the convex polygon, in radians.
 */

static inline double math_convex_poly_sum_i_ang(double n_of_sides)
{
  if (n_of_sides < 3)
    return NAN;
  double result = (n_of_sides - 2) * M_PI;
  return result;
}

/**
 * @brief Calculates the measure of each interior angle in a regular polygon.
 *
 * @param n_of_sides The number of sides of the polygon.
 *
 * @return The measure of each interior angle in the regular polygon, in radians.
 */

static inline double math_reg_polygon_i_ang(int n_of_sides)
{
  if (n_of_sides < 3)
    return NAN;
  double result = math_convex_poly_sum_i_ang(n_of_sides) / n_of_sides;
  return result;
}

/**
 * @brief Calculates the measure of each exterior angle in a convex polygon.
 *
 * @param n_of_sides The number of sides of the polygon.
 *
 * @return The measure of each exterior angle in the convex polygon, in radians.
 */

static inline double math_convex_poly_ext_ang(int n_of_sides)
{
  if (n_of_sides < 3)
    return NAN;
  double result = 2 * M_PI / n_of_sides;
  return result;
}

#endif /* GEOMETRY_H */
