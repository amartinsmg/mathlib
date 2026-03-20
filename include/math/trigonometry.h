#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif /* M_PI */

#ifndef TRIGONOMETRY_H
#define TRIGONOMETRY_H

#include <math.h>

/**
 * @brief Calculate the hypotenuse of a right triangle.
 *
 * @param sideA The length of side A of the right triangle.
 * @param sideB The length of side B of the right triangle.
 *
 * @return The length of the hypotenuse.
 */

static inline double math_hypotenuse(double sideA, double sideB)
{
  if (sideA <= 0 || sideB <= 0)
    return NAN;
  double result = sqrt(pow(sideA, 2) + pow(sideB, 2));
  return result;
}

/**
 * @brief Calculate the length of a side in a right triangle.
 *
 * @param hypotenuse The length of the hypotenuse of the right triangle.
 * @param sideA The length of one of the other sides of the right triangle.
 *
 * @return The length of the side.
 */

static inline double math_sideRTriangle(double hypotenuse, double sideA)
{
  if (sideA <= 0 || hypotenuse <= sideA)
    return NAN;
  double result = sqrt(pow(hypotenuse, 2) - pow(sideA, 2));
  return result;
}

/**
 * @brief Calculate the length of a side in a triangle using the Law of Cosines.
 *
 * @param sideA The length of side A of the triangle.
 * @param sideB The length of side B of the triangle.
 * @param oppositeAng The measure of the angle opposite to the side whose length is being calculated.
 *
 * @return The length of the side.
 */

static inline double math_sideTriangleLC(double sideA, double sideB, double oppositeAng)
{
  if (sideA <= 0 || sideB <= 0 || oppositeAng <= 0 || oppositeAng >= M_PI)
    return NAN;
  double result = sqrt(pow(sideA, 2) + pow(sideB, 2) - (2 * sideA * sideB * cos(oppositeAng)));
  return result;
}

/**
 * @brief Calculate the measure of an angle in a triangle using the Law of Cosines.
 *
 * @param oppositeSide The length of the side opposite to the angle.
 * @param sideA The length of one of the other sides of the triangle.
 * @param sideB The length of the other side of the triangle.
 *
 * @return The measure of the angle in radians.
 */

static inline double math_angTriangleLC(double oppositeSide, double sideA, double sideB)
{
  if (sideA <= 0 || sideB <= 0 || oppositeSide <= 0 ||
      oppositeSide >= sideA + sideB || oppositeSide <= fabs(sideA - sideB))
    return NAN;
  double result = acos((pow(sideA, 2) + pow(sideB, 2) - pow(oppositeSide, 2)) / (2 * sideA * sideB));
  return result;
}

/**
 * @brief Calculate the length of a side in a triangle using the Law of Sines.
 *
 * @param oppositeAng The measure of the angle opposite to the side whose length is being calculated.
 * @param sideA The length of one of the other sides of the triangle.
 * @param oppositeAng2A The measure of the other angle opposite to side A.
 *
 * @return The length of the side.
 */

static inline double math_sideTriangleLS(double oppositeAng, double sideA, double oppositeAng2A)
{
  if (sideA <= 0 || oppositeAng <= 0 || oppositeAng >= M_PI ||
      oppositeAng2A <= 0 || oppositeAng2A >= M_PI)
    return NAN;
  double result = sideA / sin(oppositeAng2A) * sin(oppositeAng);
  return result;
}

/**
 * @brief Calculate the measure of an angle in a triangle using the Law of Sines.
 *
 * @param oppositeSide The length of the side opposite to the angle.
 * @param sideA The length of one of the other sides of the triangle.
 * @param oppositeAng2A The measure of the other angle opposite to side A.
 *
 * @return The measure of the angle in radians.
 */

static inline double math_angTriangleLS(double oppositeSide, double sideA, double oppositeAng2A)
{
  if (oppositeSide <= 0 || sideA <= 0 || oppositeAng2A <= 0 || oppositeAng2A >= M_PI ||
      oppositeSide > sideA / sin(oppositeAng2A))
    return NAN;
  double result = asin(oppositeSide / (sideA / sin(oppositeAng2A)));
  return result;
}

#endif /* TRIGONOMETRY_H */
