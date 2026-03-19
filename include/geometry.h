#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <math.h>
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

static inline double math_deg2rad(double degrees)
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

static inline double math_rad2deg(double radians)
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

static inline double math_distancePoints(Point a, Point b)
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

static inline Point math_midpointPoints(Point a, Point b)
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

static inline double math_slopeLine(Point a, Point b)
{
  if (a.x == b.x)
    return NAN;
  double result;
  result = (b.y - a.y) / (b.x - a.x);
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

static inline double math_inclinationLine(Point a, Point b)
{
  double result = atan(math_slopeLine(a, b));
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

static inline double math_lineYIntercept(Point a, Point b)
{
  if (a.x == b.x)
    return NAN;
  double result;
  result = a.y - math_slopeLine(a, b) * a.x;
  return result;
}

/**
 * @brief Calculates the distance between a point and a line.
 *
 * @param inclinationLine The inclination (slope) of the line.
 * @param yInterceptLine The y-intercept of the line.
 * @param p The point.
 *
 * @return The distance between the point and the line.
 */

static inline double math_distancePointLine(double inclinationLine, double yInterceptLine, Point p)
{
  double result = fabs(inclinationLine * p.x - p.y + yInterceptLine) /
                  sqrt(pow(inclinationLine, 2) + 1);
  return result;
}

/**
 * @brief Calculates the perimeter of a circle.
 *
 * @param radius The radius of the circle.
 *
 * @return The perimeter of the circle.
 */

static inline double math_circlePerimeter(double radius)
{
  if (radius < 0)
    return NAN;
  double result = 2 * M_PI * radius;
  return result;
}

/**
 * @brief Calculates the number of diagonals in a polygon.
 *
 * @param nOfSides The number of sides of the polygon.
 *
 * @return The number of diagonals in the polygon.
 */

static inline int math_polygonDiagonals(int nOfSides)
{
  if (nOfSides < 3)
    return 0;
  int result;
  result = nOfSides * (nOfSides - 3) / 2;
  return result;
}

/**
 * @brief Calculates the sum of interior angles in a convex polygon.
 *
 * @param nOfSides The number of sides of the polygon.
 *
 * @return The sum of interior angles in the convex polygon, in radians.
 */

static inline double math_convexPolySumIntAng(double nOfSides)
{
  if (nOfSides < 3)
    return NAN;
  double result;
  result = (nOfSides - 2) * M_PI;
  return result;
}

/**
 * @brief Calculates the measure of each interior angle in a regular polygon.
 *
 * @param nOfSides The number of sides of the polygon.
 *
 * @return The measure of each interior angle in the regular polygon, in radians.
 */

static inline double math_regPolygonIAng(int nOfSides)
{
  if (nOfSides < 3)
    return NAN;
  double result;
  result = math_convexPolySumIntAng(nOfSides) / nOfSides;
  return result;
}

/**
 * @brief Calculates the measure of each exterior angle in a convex polygon.
 *
 * @param nOfSides The number of sides of the polygon.
 *
 * @return The measure of each exterior angle in the convex polygon, in radians.
 */

static inline double math_convexPolyExtAngle(int nOfSides)
{
  if (nOfSides < 3)
    return NAN;
  double result;
  result = 2 * M_PI / nOfSides;
  return result;
}

#endif /* GEOMETRY_H */
