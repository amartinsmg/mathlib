#ifndef MATHLIB_HPP
#define MATHLIB_HPP

#include <vector>

extern "C"
{
#include "mathlib.h"
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

static inline double rectangleArea(double width, double length)
{
  return math_rectangleArea(width, length);
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

static inline double regPyramidArea(double baseSide, int nOfBaseSides, double height)
{
  return math_regPyramidArea(baseSide, nOfBaseSides, height);
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

static inline long long gcd(long long x, long long y)
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

static inline double distancePointLine(double inclination, double yIntercept, Point p)
{
  return math_distancePointLine(inclination, yIntercept, p);
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

static inline double simpGrowth(double initial, double rate, double interval)
{
  return math_simpGrowth(initial, rate, interval);
}

static inline double simpGrowthRate(double initial, double final, double interval)
{
  return math_simpGrowthRate(initial, final, interval);
}

static inline double compGrowth(double initial, double rate, double interval)
{
  return math_compGrowth(initial, rate, interval);
}

static inline double compGrowthRate(double initial, double final, double interval)
{
  return math_compGrowthRate(initial, final, interval);
}

static inline bool isHappy(long long num)
{
  return math_isHappy(num);
}

static inline long long lcm(long long x, long long y)
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

static inline std::vector<long long> primeFactors(long long num)
{
  Vector out = math_primeFactors(num);
  long long *arr = (long long *)vector_get_values(&out);
  std::vector<long long> result(arr, arr + out.length);
  vector_free(&out);
  free(arr);
  return result;
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

static inline double gaussianCDF(double mu, double stdDev, double x)
{
  return math_gaussianCDF(mu, stdDev, x);
}

static inline double mean(const std::vector<double> v)
{
  return math_mean(v.data(), v.size());
}

static inline double trimmedMean(const std::vector<double> v, double percentage)
{
  return math_trimmedMean(v.data(), v.size(), percentage);
}

static inline double geometricMean(const std::vector<double> v)
{
  return math_geometricMean(v.data(), v.size());
}

static inline double harmonicMean(const std::vector<double> v)
{
  return math_harmonicMean(v.data(), v.size());
}

static inline double median(const std::vector<double> v)
{
  return math_median(v.data(), v.size());
}

static inline std::vector<double> mode(const std::vector<double> v)
{
  Vector out = math_mode(v.data(), v.size());
  double *arr = (double *)vector_get_values(&out);
  std::vector<double> result(arr, arr + out.length);
  vector_free(&out);
  free(arr);
  return result;
}

static inline double min(const std::vector<double> v)
{
  return math_min(v.data(), v.size());
}

static inline double max(const std::vector<double> v)
{
  return math_max(v.data(), v.size());
}

static inline double range(const std::vector<double> v)
{
  return math_range(v.data(), v.size());
}

static inline double midrange(const std::vector<double> v)
{
  return math_midrange(v.data(), v.size());
}

static inline double variance(const std::vector<double> v)
{
  return math_variance(v.data(), v.size());
}

static inline double stdDev(const std::vector<double> v)
{
  return math_stdDev(v.data(), v.size());
}

static inline double sampleVariance(const std::vector<double> v)
{
  return math_sampleVariance(v.data(), v.size());
}

static inline double sampleStdDev(const std::vector<double> v)
{
  return math_sampleStdDev(v.data(), v.size());
}

static inline double hypotenuse(double sideA, double sideB)
{
  return math_hypotenuse(sideA, sideB);
}

static inline double sideRTriangle(double hypotenuse, double sideA)
{
  return math_sideRTriangle(hypotenuse, sideA);
}

static inline double sideTriangleLC(double sideA, double sideB, double oppositeAng)
{
  return math_sideTriangleLC(sideA, sideB, oppositeAng);
}

static inline double angTriangleLC(double oppositeSide, double sideA, double sideB)
{
  return math_angTriangleLC(oppositeSide, sideA, sideB);
}

static inline double sideTriangleLS(double oppositeAng, double sideA, double oppositeAng2A)
{
  return math_sideTriangleLS(oppositeAng, sideA, oppositeAng2A);
}

static inline double angTriangleLS(double oppositeSide, double sideA, double oppositeAng2A)
{
  return math_angTriangleLS(oppositeSide, sideA, oppositeAng2A);
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
