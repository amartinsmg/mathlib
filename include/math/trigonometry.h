#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif /* M_PI */

#ifndef TRIGONOMETRY_H
#define TRIGONOMETRY_H

#include <math.h>

/**
 * @brief Calculate the hypotenuse of a right triangle.
 *
 * @param side_A The length of side A of the right triangle.
 * @param side_B The length of side B of the right triangle.
 *
 * @return The length of the hypotenuse.
 */

static inline double math_hypotenuse(double side_A, double side_B)
{
  if (side_A <= 0 || side_B <= 0)
    return NAN;
  double result = sqrt(pow(side_A, 2) + pow(side_B, 2));
  return result;
}

/**
 * @brief Calculate the length of a side in a right triangle.
 *
 * @param hypotenuse The length of the hypotenuse of the right triangle.
 * @param side_A The length of one of the other sides of the right triangle.
 *
 * @return The length of the side.
 */

static inline double math_side_r_triangle(double hypotenuse, double side_A)
{
  if (side_A <= 0 || hypotenuse <= side_A)
    return NAN;
  double result = sqrt(pow(hypotenuse, 2) - pow(side_A, 2));
  return result;
}

/**
 * @brief Calculate the length of a side in a triangle using the Law of Cosines.
 *
 * @param side_A The length of side A of the triangle.
 * @param side_B The length of side B of the triangle.
 * @param opp_ang The measure of the angle opposite to the side whose length is being calculated.
 *
 * @return The length of the side.
 */

static inline double math_side_triangle_l_cos(double side_A, double side_B, double opp_ang)
{
  if (side_A <= 0 || side_B <= 0 || opp_ang <= 0 || opp_ang >= M_PI)
    return NAN;
  double result = sqrt(pow(side_A, 2) + pow(side_B, 2) - (2 * side_A * side_B * cos(opp_ang)));
  return result;
}

/**
 * @brief Calculate the measure of an angle in a triangle using the Law of Cosines.
 *
 * @param opp_side The length of the side opposite to the angle.
 * @param side_A The length of one of the other sides of the triangle.
 * @param side_B The length of the other side of the triangle.
 *
 * @return The measure of the angle in radians.
 */

static inline double math_ang_triangle_l_cos(double opp_side, double side_A, double side_B)
{
  if (side_A <= 0 || side_B <= 0 || opp_side <= 0 ||
      opp_side >= side_A + side_B || opp_side <= fabs(side_A - side_B))
    return NAN;
  double result = acos((pow(side_A, 2) + pow(side_B, 2) - pow(opp_side, 2)) / (2 * side_A * side_B));
  return result;
}

/**
 * @brief Calculate the length of a side in a triangle using the Law of Sines.
 *
 * @param opp_ang The measure of the angle opposite to the side whose length is being calculated.
 * @param side_A The length of one of the other sides of the triangle.
 * @param opp_ang_to_A The measure of the other angle opposite to side A.
 *
 * @return The length of the side.
 */

static inline double math_side_triangle_l_sin(double opp_ang, double side_A, double opp_ang_to_A)
{
  if (side_A <= 0 || opp_ang <= 0 || opp_ang >= M_PI ||
      opp_ang_to_A <= 0 || opp_ang_to_A >= M_PI)
    return NAN;
  double result = side_A / sin(opp_ang_to_A) * sin(opp_ang);
  return result;
}

/**
 * @brief Calculate the measure of an angle in a triangle using the Law of Sines.
 *
 * @param opp_side The length of the side opposite to the angle.
 * @param side_A The length of one of the other sides of the triangle.
 * @param opp_ang_to_A The measure of the other angle opposite to side A.
 *
 * @return The measure of the angle in radians.
 */

static inline double math_ang_triangle_l_sin(double opp_side, double side_A, double opp_ang_to_A)
{
  if (opp_side <= 0 || side_A <= 0 || opp_ang_to_A <= 0 || opp_ang_to_A >= M_PI ||
      opp_side > side_A / sin(opp_ang_to_A))
    return NAN;
  double result = asin(opp_side / (side_A / sin(opp_ang_to_A)));
  return result;
}

#endif /* TRIGONOMETRY_H */
