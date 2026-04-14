#include "mathlib.h"
#include <stdlib.h>

void freeArray(void *ptr)
{
  free(ptr);
}

double triangleArea1(double base, double height)
{
  return math_triangle_area_1(base, height);
}

double triangleArea2(double sideA, double sideB, double angleGama)
{
  return math_triangle_area_2(sideA, sideB, angleGama);
}

double triangleArea3(double sideA, double sideB, double sideC)
{
  return math_triangle_area_3(sideA, sideB, sideC);
}

double squareArea(double side)
{
  return math_square_area(side);
}

double rectangleArea(double width, double length)
{
  return math_rectangle_area(width, length);
}

double rhombusArea(double largerDiagonal, double smallerDiagonal)
{
  return math_rhombus_area(largerDiagonal, smallerDiagonal);
}

double parallelogramArea1(double base, double height)
{
  return math_parallelogram_area_1(base, height);
}

double parallelogramArea2(double sideA, double sideB, double angleBetweenAB)
{
  return math_parallelogram_area_2(sideA, sideB, angleBetweenAB);
}

double trapezoidArea(double largerBase, double smallerBase, double height)
{
  return math_trapezoid_area(largerBase, smallerBase, height);
}

double regPolygonArea(double side, int nOfSides)
{
  return math_reg_polygon_area(side, nOfSides);
}

double circleArea(double radius)
{
  return math_circle_area(radius);
}

double circularSectorArea1(double angle, double radius)
{
  return math_circular_sector_area_1(angle, radius);
}

double circularSectorArea2(double arc, double radius)
{
  return math_circular_sector_area_2(arc, radius);
}

double ellipseArea(double semiMajorAxis, double semiMinorAxis)
{
  return math_ellipse_area(semiMajorAxis, semiMinorAxis);
}

double cubeArea(double side)
{
  return math_cube_area(side);
}

double cuboidArea(double width, double length, double height)
{
  return math_cuboid_area(width, length, height);
}

double prismArea(double baseArea, double basePerimeter, double height)
{
  return math_prism_area(baseArea, basePerimeter, height);
}

double regularPrismArea(double baseSide, int nOfBaseSides, double height)
{
  return math_reg_prism_area(baseSide, nOfBaseSides, height);
}

double pyramidArea(double baseArea, double basePerimeter, double slantHeight)
{
  return math_pyramid_area(baseArea, basePerimeter, slantHeight);
}

double regPyramidArea(double baseSide, int nOfBaseSides, double height)
{
  return math_reg_pyramid_area(baseSide, nOfBaseSides, height);
}

double cylinderArea(double baseRadius, double height)
{
  return math_cylinder_area(baseRadius, height);
}

double coneArea(double baseRadius, double height)
{
  return math_cone_area(baseRadius, height);
}

double sphereArea(double radius)
{
  return math_sphere_area(radius);
}

bool isArmstrong(long long num)
{
  return math_is_armstrong(num);
}

double logarithm(double num, double base)
{
  return math_logarithm(num, base);
}

double nthRoot(double radicand, double degree)
{
  return math_nth_root(radicand, degree);
}

double roundTo(double num, unsigned decimalPlaces)
{
  return math_round_to(num, decimalPlaces);
}

unsigned long long permutation(unsigned num)
{
  return math_permutation(num);
}

unsigned long long cyclePermutation(unsigned num)
{
  return math_cycle_permutation(num);
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
  return math_cycle_permutationlf(num);
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
  return math_deg_to_rad(degrees);
}

double rad2deg(double radians)
{
  return math_rad_to_deg(radians);
}

double distancePoints(double aX, double aY, double bX, double bY)
{
  Point a = {aX, aY},
        b = {bX, bY};
  return math_distance_points(a, b);
}

double *midpoint(double aX, double aY, double bX, double bY)
{
  Point a = {aX, aY},
        b = {bX, bY},
        out = math_midpoint(a, b);
  double *result = malloc(sizeof(double) * 2);
  if (result != NULL)
  {
    result[0] = out.x;
    result[1] = out.y;
  }
  return result;
}

double slopeLine(double aX, double aY, double bX, double bY)
{
  Point a = {aX, aY},
        b = {bX, bY};
  return math_slope_line(a, b);
}

double inclinationLine(double aX, double aY, double bX, double bY)
{
  Point a = {aX, aY},
        b = {bX, bY};
  return math_inclination_line(a, b);
}

double lineYIntercept(double aX, double aY, double bX, double bY)
{
  Point a = {aX, aY},
        b = {bX, bY};
  return math_line_y_intercept(a, b);
}

double distancePointLine(double inclination, double yIntercept, double pX, double pY)
{
  Point p = {pX, pY};
  return math_distance_point_line(inclination, yIntercept, p);
}

double circlePerimeter(double radius)
{
  return math_circle_perimeter(radius);
}

int polygonDiagonals(int nOfSides)
{
  return math_polygon_diagonals(nOfSides);
}

double convexPolySumIntAng(double nOfSides)
{
  return math_convex_poly_sum_i_ang(nOfSides);
}

double regPolygonIAng(int nOfSides)
{
  return math_reg_polygon_i_ang(nOfSides);
}

double convexPolyExtAngle(int nOfSides)
{
  return math_convex_poly_ext_ang(nOfSides);
}

double simpGrowth(double initial, double rate, double interval)
{
  return math_simp_growth(initial, rate, interval);
}

double simpGrowthRate(double initial, double final, double interval)
{
  return math_simp_growthRate(initial, final, interval);
}

double compGrowth(double initial, double rate, double interval)
{
  return math_comp_growth(initial, rate, interval);
}

double compGrowthRate(double initial, double final, double interval)
{
  return math_comp_growthRate(initial, final, interval);
}

bool isHappy(long long num)
{
  return math_is_happy(num);
}

long long lcm(int x, int y)
{
  return math_lcm(x, y);
}

double nPercentOfX(double x, double n)
{
  return math_n_percent_of_x(x, n);
}

double nIsWhatPercentOfX(double x, double n)
{
  return math_n_is_what_percent_of_x(x, n);
}

bool isPerfect(long long num)
{
  return math_is_perfect(num);
}

long long *primeFactors(long long num, size_t *size)
{
  Vector out = math_prime_factors(num);
  long long *result = (long long *)vector_get_values(&out);
  *size = out.length;
  vector_free(&out);
  return result;
}

bool isPrime(long long num)
{
  return math_is_prime(num);
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
  return math_gaussian_CDF(mu, stdDev, x);
}

double mean(const double *arr, size_t length)
{
  return math_mean(arr, length);
}

double trimmedMean(const double *arr, size_t length, double percentage)
{
  return math_trimmed_mean(arr, length, percentage);
}

double geometricMean(const double *arr, size_t length)
{
  return math_geometric_mean(arr, length);
}

double harmonicMean(const double *arr, size_t length)
{
  return math_harmonic_mean(arr, length);
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
  return math_std_dev(arr, length);
}

double sampleVariance(const double *arr, size_t length)
{
  return math_sample_variance(arr, length);
}

double sampleStdDev(const double *arr, size_t length)
{
  return math_sample_std_dev(arr, length);
}

double hypotenuse(double sideA, double sideB)
{
  return math_hypotenuse(sideA, sideB);
}

double sideRTriangle(double hypotenuse, double sideA)
{
  return math_side_r_triangle(hypotenuse, sideA);
}

double sideTriangleLC(double sideA, double sideB, double oppositeAng)
{
  return math_side_triangle_l_cos(sideA, sideB, oppositeAng);
}

double angTriangleLC(double oppositeSide, double sideA, double sideB)
{
  return math_ang_triangle_l_cos(oppositeSide, sideA, sideB);
}

double sideTriangleLS(double oppositeAng, double sideA, double oppositeAng2A)
{
  return math_side_triangle_l_sin(oppositeAng, sideA, oppositeAng2A);
}

double angTriangleLS(double oppositeSide, double sideA, double oppositeAng2A)
{
  return math_ang_triangle_l_sin(oppositeSide, sideA, oppositeAng2A);
}

double cubeVol(double side)
{
  return math_cube_vol(side);
}

double cuboidVol(double length, double width, double height)
{
  return math_cuboid_vol(length, width, height);
}

double prismVol(double baseArea, double height)
{
  return math_prism_vol(baseArea, height);
}

double regularPrism_vol(double baseSide, int nOfBaseSides, double height)
{
  return math_reg_prism_vol(baseSide, nOfBaseSides, height);
}

double pyramidVol(double baseArea, double height)
{
  return math_pyramid_vol(baseArea, height);
}

double regPyramidVol(double baseSide, int nOfBaseSides, double height)
{
  return math_reg_pyramid_vol(baseSide, nOfBaseSides, height);
}

double cylinderVol(double baseRadius, double height)
{
  return math_cylinder_vol(baseRadius, height);
}

double coneVol(double baseRadius, double height)
{
  return math_cone_vol(baseRadius, height);
}

double sphereVol(double radius)
{
  return math_sphere_vol(radius);
}