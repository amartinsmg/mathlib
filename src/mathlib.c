#include "mathlib.h"
#include <stdlib.h>

void freeArray(void *ptr)
{
  free(ptr);
}

double triangleArea1(double base, double height)
{
  return math_triangleArea1(base, height);
}

double triangleArea2(double sideA, double sideB, double angleGama)
{
  return math_triangleArea2(sideA, sideB, angleGama);
}

double triangleArea3(double sideA, double sideB, double sideC)
{
  return math_triangleArea3(sideA, sideB, sideC);
}

double squareArea(double side)
{
  return math_squareArea(side);
}

double retangleArea(double width, double length)
{
  return math_retangleArea(width, length);
}

double rhombusArea(double largerDiagonal, double smallerDiagonal)
{
  return math_rhombusArea(largerDiagonal, smallerDiagonal);
}

double parallelogramArea1(double base, double height)
{
  return math_parallelogramArea1(base, height);
}

double parallelogramArea2(double sideA, double sideB, double angleBeetweenAB)
{
  return math_parallelogramArea2(sideA, sideB, angleBeetweenAB);
}

double trapezoidArea(double largerBase, double smallerBase, double height)
{
  return math_trapezoidArea(largerBase, smallerBase, height);
}

double regPolygonArea(double side, int nOfSides)
{
  return math_regPolygonArea(side, nOfSides);
}

double circleArea(double radius)
{
  return math_circleArea(radius);
}

double circularSectorArea1(double angle, double radius)
{
  return math_circularSectorArea1(angle, radius);
}

double circularSectorArea2(double arc, double radius)
{
  return math_circularSectorArea2(arc, radius);
}

double ellipseArea(double semiMajorAxis, double semiMinorAxis)
{
  return math_ellipseArea(semiMajorAxis, semiMinorAxis);
}

double cubeArea(double side)
{
  return math_cubeArea(side);
}

double cuboidArea(double width, double length, double height)
{
  return math_cuboidArea(width, length, height);
}

double prismArea(double baseArea, double basePerimeter, double height)
{
  return math_prismArea(baseArea, basePerimeter, height);
}

double regularPrismArea(double baseSide, int nOfBaseSides, double height)
{
  return math_regularPrismArea(baseSide, nOfBaseSides, height);
}

double pyramidArea(double baseArea, double basePerimeter, double slantHeight)
{
  return math_pyramidArea(baseArea, basePerimeter, slantHeight);
}

double regPyramidArea(double baseSide, int nOfBaseSides, double heigth)
{
  return math_regPyramidArea(baseSide, nOfBaseSides, heigth);
}

double cylinderArea(double baseRadius, double height)
{
  return math_cylinderArea(baseRadius, height);
}

double coneArea(double baseRadius, double height)
{
  return math_coneArea(baseRadius, height);
}

double sphereArea(double radius)
{
  return math_sphereArea(radius);
}

bool isArmstrong(long long num)
{
  return math_isArmstrong(num);
}

double logarithm(double num, double base)
{
  return math_logarithm(num, base);
}

double nthRoot(double radicand, double degree)
{
  return math_nthRoot(radicand, degree);
}

double roundTo(double num, unsigned decimalPlaces)
{
  return math_roundTo(num, decimalPlaces);
}

unsigned long long permutation(unsigned num)
{
  return math_permutation(num);
}

unsigned long long cyclePermutation(unsigned num)
{
  return math_cyclePermutation(num);
}

unsigned long long arrangement(unsigned total, unsigned selected)
{
  return math_arrangement(total, selected);
}

unsigned long long combination(unsigned total, unsigned selected)
{
  return math_combination(total, selected);
}

double permutationlf(unsigned num)
{
  return math_permutationlf(num);
}

double cyclePermutationlf(unsigned num)
{
  return math_cyclePermutationlf(num);
}

double arrangementlf(unsigned total, unsigned selected)
{
  return math_arrangementlf(total, selected);
}

double combinationlf(unsigned total, unsigned selected)
{
  return math_combinationlf(total, selected);
}

unsigned long long factorial(unsigned num)
{
  return math_factorial(num);
}

double factoriallf(unsigned num)
{
  return math_factoriallf(num);
}

int gcd(int x, int y)
{
  return math_gcd(x, y);
}

double deg2rad(double degrees)
{
  return math_deg2rad(degrees);
}

double rad2deg(double radians)
{
  return math_rad2deg(radians);
}

double distancePoints(double a_x, double a_y, double b_x, double b_y)
{
  Point a = {a_x, a_y},
        b = {b_x, b_y};
  return math_distancePoints(a, b);
}

double *midpointPoints(double a_x, double a_y, double b_x, double b_y)
{
  Point a = {a_x, a_y},
        b = {b_x, b_y},
        out = math_midpointPoints(a, b);
  double *result = malloc(sizeof(double) * 2);
  if (result != NULL)
  {
    result[0] = out.x;
    result[1] = out.y;
  }
  return result;
}

double slopeLine(double a_x, double a_y, double b_x, double b_y)
{
  Point a = {a_x, a_y},
        b = {b_x, b_y};
  return math_slopeLine(a, b);
}

double inclinationLine(double a_x, double a_y, double b_x, double b_y)
{
  Point a = {a_x, a_y},
        b = {b_x, b_y};
  return math_inclinationLine(a, b);
}

double lineYIntercept(double a_x, double a_y, double b_x, double b_y)
{
  Point a = {a_x, a_y},
        b = {b_x, b_y};
  return math_lineYIntercept(a, b);
}

double distancePointLine(double inclination, double yIntercept, double p_x, double p_y)
{
  Point p = {p_x, p_y};
  return math_distancePointLine(inclination, yIntercept, p);
}

double circlePerimeter(double radius)
{
  return math_circlePerimeter(radius);
}

int polygonDiagonals(int nOfSides)
{
  return math_polygonDiagonals(nOfSides);
}

double convexPolySumIntAng(double nOfSides)
{
  return math_convexPolySumIntAng(nOfSides);
}

double regPolygonIAng(int nOfSides)
{
  return math_regPolygonIAng(nOfSides);
}

double convexPolyExtAngle(int nOfSides)
{
  return math_convexPolyExtAngle(nOfSides);
}

double simpGrowth(double initial, double rate, double interval)
{
  return math_simpGrowth(initial, rate, interval);
}

double simpGrowthRate(double initial, double final, double interval)
{
  return math_simpGrowthRate(initial, final, interval);
}

double compGrowth(double initial, double rate, double interval)
{
  return math_compGrowth(initial, rate, interval);
}

double compGrowthRate(double initial, double final, double interval)
{
  return math_compGrowthRate(initial, final, interval);
}

bool isHappy(long long num)
{
  return math_isHappy(num);
}

long long lcm(int x, int y)
{
  return math_lcm(x, y);
}

double nPercentOfX(double x, double n)
{
  return math_nPercentOfX(x, n);
}

double nIsWhatPercentOfX(double x, double n)
{
  return math_nIsWhatPercentOfX(x, n);
}

bool isPerfect(long long num)
{
  return math_isPerfect(num);
}

long long *primeFactors(long long num, size_t *size)
{
  Vector out = math_primeFactors(num);
  long long *result = (long long *)vector_get_values(&out);
  *size = out.length;
  vector_free(&out);
  return result;
}

bool isPrime(long long num)
{
  return math_isPrime(num);
}

double binominal(int trials, double successProb, int success)
{
  return math_binominal(trials, successProb, success);
}

double poisson(double lambda, unsigned x)
{
  return math_poisson(lambda, x);
}

double gaussianCDF(double mu, double stdDev, double x)
{
  return math_gaussianCDF(mu, stdDev, x);
}

double mean(const double *arr, size_t length)
{
  return math_mean(arr, length);
}

double trimmedMean(const double *arr, size_t length, double percentage)
{
  return math_trimmedMean(arr, length, percentage);
}

double geometricMean(const double *arr, size_t length)
{
  return math_geometricMean(arr, length);
}

double harmonicMean(const double *arr, size_t length)
{
  return math_harmonicMean(arr, length);
}

double median(const double *arr, size_t length)
{
  return math_median(arr, length);
}

double *mode(const double *arr, size_t length, size_t *size)
{
  Vector out = math_mode(arr, length);
  double *result = (double *)vector_get_values(&out);
  *size = out.length;
  vector_free(&out);
  return result;
}

double min(const double *arr, size_t length)
{
  return math_min(arr, length);
}

double max(const double *arr, size_t length)
{
  return math_max(arr, length);
}

double range(const double *arr, size_t length)
{
  return math_range(arr, length);
}

double midrange(const double *arr, size_t length)
{
  return math_midrange(arr, length);
}

double variance(const double *arr, size_t length)
{
  return math_variance(arr, length);
}

double stdDev(const double *arr, size_t length)
{
  return math_stdDev(arr, length);
}

double sampleVariance(const double *arr, size_t length)
{
  return math_sampleVariance(arr, length);
}

double sampleStdDev(const double *arr, size_t length)
{
  return math_sampleStdDev(arr, length);
}

double hypotenuse(double sideA, double sideB)
{
  return math_hypotenuse(sideA, sideB);
}

double sideRTriangle(double hypotenuse, double sideA)
{
  return math_sideRTriangle(hypotenuse, sideA);
}

double sideTriangleLC(double sideA, double sideB, double oppositeAng)
{
  return math_sideTriangleLC(sideA, sideB, oppositeAng);
}

double angTriangleLC(double oppositeSide, double sideA, double sideB)
{
  return math_angTriangleLC(oppositeSide, sideA, sideB);
}

double sideTriangleLS(double oppositeAng, double sideA, double oppositeAng2A)
{
  return math_sideTriangleLS(oppositeAng, sideA, oppositeAng2A);
}

double angTriangleLS(double oppositeSide, double sideA, double oppositeAng2A)
{
  return math_angTriangleLS(oppositeSide, sideA, oppositeAng2A);
}

double cubeVol(double side)
{
  return math_cubeVol(side);
}

double cuboidVol(double length, double width, double height)
{
  return math_cuboidVol(length, width, height);
}

double prismVol(double baseArea, double height)
{
  return math_prismVol(baseArea, height);
}

double regularPrismVol(double baseSide, int nOfBaseSides, double height)
{
  return math_regularPrismVol(baseSide, nOfBaseSides, height);
}

double pyramidVol(double baseArea, double height)
{
  return math_pyramidVol(baseArea, height);
}

double regPyramidVol(double baseSide, int nOfBaseSides, double height)
{
  return math_regPyramidVol(baseSide, nOfBaseSides, height);
}

double cylinderVol(double baseRadius, double height)
{
  return math_cylinderVol(baseRadius, height);
}

double coneVol(double baseRadius, double height)
{
  return math_coneVol(baseRadius, height);
}

double sphereVol(double radius)
{
  return math_sphereVol(radius);
}