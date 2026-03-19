#ifndef MATHLIB_HPP
#define MATHLIB_HPP

extern "C"
{
#include "area_shape.h"
#include "area_surface.h"
#include "armstrong_numbers.h"
#include "combinatorics.h"
#include "geometry.h"
#include "growth.h"
#include "happy_numbers.h"
#include "lcm.h"
#include "percentage.h"
#include "perfect_numbers.h"
#include "prime_factorization.h"
#include "prime_numbers.h"
#include "probability_distribution.h"
#include "statistics.h"
#include "volume.h"
}

namespace Math
{

  static inline double triangleArea1(double base, double height)
  {
    return math_triangleArea1(base, height);
  }

  static inline double triangleArea2(double sideA, double sideB, double angleGama)
  {
    return math_triangleArea2(sideA, sideB, angleGama);
  }

  static inline double triangleArea3(double sideA, double sideB, double sideC)
  {
    return math_triangleArea3(sideA, sideB, sideC);
  }

  static inline double squareArea(double side)
  {
    return math_squareArea(side);
  }

  static inline double retangleArea(double width, double length)
  {
    return math_retangleArea(width, length);
  }

  static inline double rhombusArea(double largerDiagonal, double smallerDiagonal)
  {
    return math_rhombusArea(largerDiagonal, smallerDiagonal);
  }

  static inline double parallelogramArea1(double base, double height)
  {
    return math_parallelogramArea1(base, height);
  }

  static inline double parallelogramArea2(double sideA, double sideB, double angleBeetweenAB)
  {
    return math_parallelogramArea2(sideA, sideB, angleBeetweenAB);
  }

  static inline double trapezoidArea(double largerBase, double smallerBase, double height)
  {
    return math_trapezoidArea(largerBase, smallerBase, height);
  }

  static inline double regPolygonArea(double side, int nOfSides)
  {
    return math_regPolygonArea(side, nOfSides);
  }

  static inline double circleArea(double radius)
  {
    return math_circleArea(radius);
  }

  static inline double circularSectorArea1(double angle, double radius)
  {
    return math_circularSectorArea1(angle, radius);
  }

  static inline double circularSectorArea2(double arc, double radius)
  {
    return math_circularSectorArea2(arc, radius);
  }

  static inline double ellipseArea(double semiMajorAxis, double semiMinorAxis)
  {
    return math_ellipseArea(semiMajorAxis, semiMinorAxis);
  }

  static inline double cubeArea(double side)
  {
    return math_cubeArea(side);
  }

  static inline double cuboidArea(double width, double length, double height)
  {
    return math_cuboidArea(width, length, height);
  }

  static inline double prismArea(double baseArea, double basePerimeter, double height)
  {
    return math_prismArea(baseArea, basePerimeter, height);
  }

  static inline double regularPrismArea(double baseSide, int nOfBaseSides, double height)
  {
    return math_regularPrismArea(baseSide, nOfBaseSides, height);
  }

  static inline double pyramidArea(double baseArea, double basePerimeter, double slantHeight)
  {
    return math_pyramidArea(baseArea, basePerimeter, slantHeight);
  }

  static inline double regPyramidArea(double baseSide, int nOfBaseSides, double heigth)
  {
    return math_regPyramidArea(baseSide, nOfBaseSides, heigth);
  }

  static inline double cylinderArea(double baseRadius, double height)
  {
    return math_cylinderArea(baseRadius, height);
  }

  static inline double coneArea(double baseRadius, double height)
  {
    return math_coneArea(baseRadius, height);
  }

  static inline double sphereArea(double radius)
  {
    return math_sphereArea(radius);
  }

  static inline bool isArmstrong(long long num)
  {
    return math_isArmstrong(num);
  }

  static inline double logarithm(double num, double base)
  {
    return math_logarithm(num, base);
  }

  static inline double nthRoot(double radicand, double degree)
  {
    return math_nthRoot(radicand, degree);
  }

  static inline double roundTo(double num, unsigned decimalPlaces)
  {
    return math_roundTo(num, decimalPlaces);
  }

  static inline unsigned long long permutation(unsigned num)
  {
    return math_permutation(num);
  }

  static inline unsigned long long cyclePermutation(unsigned num)
  {
    return math_cyclePermutation(num);
  }

  static inline unsigned long long arrangement(unsigned total, unsigned selected)
  {
    return math_arrangement(total, selected);
  }

  static inline unsigned long long combination(unsigned total, unsigned selected)
  {
    return math_combination(total, selected);
  }

  static inline double permutationlf(unsigned num)
  {
    return math_permutationlf(num);
  }

  static inline double cyclePermutationlf(unsigned num)
  {
    return math_cyclePermutationlf(num);
  }

  static inline double arrangementlf(unsigned total, unsigned selected)
  {
    return math_arrangementlf(total, selected);
  }

  static inline double combinationlf(unsigned total, unsigned selected)
  {
    return math_combinationlf(total, selected);
  }

  static inline unsigned long long factorial(unsigned num)
  {
    return math_factorial(num);
  }

  static inline double factoriallf(unsigned num)
  {
    return math_factoriallf(num);
  }

  static inline int gcd(int x, int y)
  {
    return math_gcd(x, y);
  }

  static inline double deg2rad(double degrees)
  {
    return math_deg2rad(degrees);
  }

  static inline double rad2deg(double radians)
  {
    return math_rad2deg(radians);
  }

  static inline double distancePoints(Point a, Point b)
  {
    return math_distancePoints(a, b);
  }

  static inline Point midpointPoints(Point a, Point b)
  {
    return math_midpointPoints(a, b);
  }

  static inline double slopeLine(Point a, Point b)
  {
    return math_slopeLine(a, b);
  }

  static inline double inclinationLine(Point a, Point b)
  {
    return math_inclinationLine(a, b);
  }

  static inline double lineYIntercept(Point a, Point b)
  {
    return math_lineYIntercept(a, b);
  }

  static inline double distancePointLine(double inclinationLine, double yInterceptLine, Point p)
  {
    return math_distancePointLine(inclinationLine, yInterceptLine, p);
  }

  static inline double circlePerimeter(double radius)
  {
    return math_circlePerimeter(radius);
  }

  static inline int polygonDiagonals(int nOfSides)
  {
    return math_polygonDiagonals(nOfSides);
  }

  static inline double convexPolySumIntAng(double nOfSides)
  {
    return math_convexPolySumIntAng(nOfSides);
  }

  static inline double regPolygonIAng(int nOfSides)
  {
    return math_regPolygonIAng(nOfSides);
  }

  static inline double convexPolyExtAngle(int nOfSides)
  {
    return math_convexPolyExtAngle(nOfSides);
  }

  static inline double simpleGrowth(double initial, double rate, double interval)
  {
    return math_simpleGrowth(initial, rate, interval);
  }

  static inline double simpleGrowthRate(double initial, double final, double interval)
  {
    return math_simpleGrowthRate(initial, final, interval);
  }

  static inline double compoundedGrowth(double initial, double rate, double interval)
  {
    return math_compoundedGrowth(initial, rate, interval);
  }

  static inline double compoundedGrowthRate(double initial, double final, double interval)
  {
    return math_compoundedGrowthRate(initial, final, interval);
  }

  static inline bool isHappy(long long num)
  {
    return math_isHappy(num);
  }

  static inline long long lcm(int x, int y)
  {
    return math_lcm(x, y);
  }

  static inline double nPercentOfX(double x, double n)
  {
    return math_nPercentOfX(x, n);
  }

  static inline double nIsWhatPercentOfX(double x, double n)
  {
    return math_nIsWhatPercentOfX(x, n);
  }

  static inline bool isPerfect(long long num)
  {
    return math_isPerfect(num);
  }

  static inline long long *primeFactors(long long num)
  {
    return math_primeFactors(num);
  }

  static inline bool isPrime(long long num)
  {
    return math_isPrime(num);
  }

  static inline double binominal(int trials, double successProb, int success)
  {
    return math_binominal(trials, successProb, success);
  }

  static inline double poisson(double lambda, unsigned x)
  {
    return math_poisson(lambda, x);
  }

  static inline double gaussianCDF(double mu, double standardDev, double x)
  {
    return math_gaussianCDF(mu, standardDev, x);
  }

  static inline double mean(const double *arr, size_t length)
  {
    return math_mean(arr, length);
  }

  static inline double weightedMean(const ValueWeight *values_weights, size_t length)
  {
    return math_weightedMean(values_weights, length);
  }

  static inline double trimmedMean(const double *arr, size_t length, double trimmedMeanPercentage)
  {
    return math_trimmedMean(arr, length, trimmedMeanPercentage);
  }

  static inline double geometricMean(const double *arr, size_t length)
  {
    return math_geometricMean(arr, length);
  }

  static inline double harmonicMean(const double *arr, size_t length)
  {
    return math_harmonicMean(arr, length);
  }

  static inline double median(const double *arr, size_t length)
  {
    return math_median(arr, length);
  }

  static inline double *mode(const double *arr, size_t length, size_t *ptrNOfModes)
  {
    return math_mode(arr, length, ptrNOfModes);
  }

  static inline double min(const double *arr, size_t length)
  {
    return math_min(arr, length);
  }

  static inline double max(const double *arr, size_t length)
  {
    return math_max(arr, length);
  }

  static inline double range(const double *arr, size_t length)
  {
    return math_range(arr, length);
  }

  static inline double midrange(const double *arr, size_t length)
  {
    return math_midrange(arr, length);
  }

  static inline double variance(const double *arr, size_t length)
  {
    return math_variance(arr, length);
  }

  static inline double standardDeviation(const double *arr, size_t length)
  {
    return math_standardDeviation(arr, length);
  }

  static inline double sampleVariance(const double *arr, size_t length)
  {
    return math_sampleVariance(arr, length);
  }

  static inline double sampleStandardDeviation(const double *arr, size_t length)
  {
    return math_sampleStandardDeviation(arr, length);
  }

  static inline double hypotenuse(double sideA, double sideB)
  {
    return math_hypotenuse(sideA, sideB);
  }

  static inline double sideRTriangle(double hypotenuse, double sideA)
  {
    return math_sideRTriangle(hypotenuse, sideA);
  }

  static inline double sideTriangleLC(double sideA, double sideB, double oppositeAngle)
  {
    return math_sideTriangleLC(sideA, sideB, oppositeAngle);
  }

  static inline double angTriangleLC(double oppositeSide, double sideA, double sideB)
  {
    return math_angTriangleLC(oppositeSide, sideA, sideB);
  }

  static inline double sideTriangleLS(double oppositeAngle, double sideA, double oppositeAngle2A)
  {
    return math_sideTriangleLS(oppositeAngle, sideA, oppositeAngle2A);
  }

  static inline double angTriangleLS(double oppositeSide, double sideA, double oppositeAngle2A)
  {
    return math_angTriangleLS(oppositeSide, sideA, oppositeAngle2A);
  }

  static inline double cubeVol(double side)
  {
    return math_cubeVol(side);
  }

  static inline double cuboidVol(double length, double width, double height)
  {
    return math_cuboidVol(length, width, height);
  }

  static inline double prismVol(double baseArea, double height)
  {
    return math_prismVol(baseArea, height);
  }

  static inline double regularPrismVol(double baseSide, int nOfBaseSides, double height)
  {
    return math_regularPrismVol(baseSide, nOfBaseSides, height);
  }

  static inline double pyramidVol(double baseArea, double height)
  {
    return math_pyramidVol(baseArea, height);
  }

  static inline double regPyramidVol(double baseSide, int nOfBaseSides, double height)
  {
    return math_regPyramidVol(baseSide, nOfBaseSides, height);
  }

  static inline double cylinderVol(double baseRadius, double height)
  {
    return math_cylinderVol(baseRadius, height);
  }

  static inline double coneVol(double baseRadius, double height)
  {
    return math_coneVol(baseRadius, height);
  }

  static inline double sphereVol(double radius)
  {
    return math_sphereVol(radius);
  }

} // namespace Math

#endif /* MATHLIB_HPP */
