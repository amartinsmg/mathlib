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
  return math_triangle_area_1(base, height);
}

static inline double triangleArea2(double sideA, double sideB, double angleGama)
{
  return math_triangle_area_2(sideA, sideB, angleGama);
}

static inline double triangleArea3(double sideA, double sideB, double sideC)
{
  return math_triangle_area_3(sideA, sideB, sideC);
}

static inline double squareArea(double side)
{
  return math_square_area(side);
}

static inline double rectangleArea(double width, double length)
{
  return math_rectangle_area(width, length);
}

static inline double rhombusArea(double largerDiagonal, double smallerDiagonal)
{
  return math_rhombus_area(largerDiagonal, smallerDiagonal);
}

static inline double parallelogramArea1(double base, double height)
{
  return math_parallelogram_area_1(base, height);
}

static inline double parallelogramArea2(double sideA, double sideB, double angleBetweenAB)
{
  return math_parallelogram_area_2(sideA, sideB, angleBetweenAB);
}

static inline double trapezoidArea(double largerBase, double smallerBase, double height)
{
  return math_trapezoid_area(largerBase, smallerBase, height);
}

static inline double regPolygonArea(double side, int nOfSides)
{
  return math_reg_polygon_area(side, nOfSides);
}

static inline double circleArea(double radius)
{
  return math_circle_area(radius);
}

static inline double circularSectorArea1(double angle, double radius)
{
  return math_circular_sector_area_1(angle, radius);
}

static inline double circularSectorArea2(double arc, double radius)
{
  return math_circular_sector_area_2(arc, radius);
}

static inline double ellipseArea(double semiMajorAxis, double semiMinorAxis)
{
  return math_ellipse_area(semiMajorAxis, semiMinorAxis);
}

static inline double cubeArea(double side)
{
  return math_cube_area(side);
}

static inline double cuboidArea(double width, double length, double height)
{
  return math_cuboid_area(width, length, height);
}

static inline double prismArea(double baseArea, double basePerimeter, double height)
{
  return math_prism_area(baseArea, basePerimeter, height);
}

static inline double regularPrismArea(double baseSide, int nOfBaseSides, double height)
{
  return math_reg_prism_area(baseSide, nOfBaseSides, height);
}

static inline double pyramidArea(double baseArea, double basePerimeter, double slantHeight)
{
  return math_pyramid_area(baseArea, basePerimeter, slantHeight);
}

static inline double regPyramidArea(double baseSide, int nOfBaseSides, double height)
{
  return math_reg_pyramid_area(baseSide, nOfBaseSides, height);
}

static inline double cylinderArea(double baseRadius, double height)
{
  return math_cylinder_area(baseRadius, height);
}

static inline double coneArea(double baseRadius, double height)
{
  return math_cone_area(baseRadius, height);
}

static inline double sphereArea(double radius)
{
  return math_sphere_area(radius);
}

static inline bool isArmstrong(long long num)
{
  return math_is_armstrong(num);
}

static inline double logarithm(double num, double base)
{
  return math_logarithm(num, base);
}

static inline double nthRoot(double radicand, double degree)
{
  return math_nth_root(radicand, degree);
}

static inline double roundTo(double num, unsigned decimalPlaces)
{
  return math_round_to(num, decimalPlaces);
}

static inline unsigned long long permutation(unsigned num)
{
  return math_permutation(num);
}

static inline unsigned long long cyclePermutation(unsigned num)
{
  return math_cycle_permutation(num);
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
  return math_cycle_permutationlf(num);
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
  return math_deg_to_rad(degrees);
}

static inline double rad2deg(double radians)
{
  return math_rad_to_deg(radians);
}

static inline double distancePoints(Point a, Point b)
{
  return math_distance_points(a, b);
}

static inline Point midpoint(Point a, Point b)
{
  return math_midpoint(a, b);
}

static inline double slopeLine(Point a, Point b)
{
  return math_slope_line(a, b);
}

static inline double inclinationLine(Point a, Point b)
{
  return math_inclination_line(a, b);
}

static inline double lineYIntercept(Point a, Point b)
{
  return math_line_y_intercept(a, b);
}

static inline double distancePointLine(double inclination, double yIntercept, Point p)
{
  return math_distance_point_line(inclination, yIntercept, p);
}

static inline double circlePerimeter(double radius)
{
  return math_circle_perimeter(radius);
}

static inline int polygonDiagonals(int nOfSides)
{
  return math_polygon_diagonals(nOfSides);
}

static inline double convexPolySumIntAng(double nOfSides)
{
  return math_convex_poly_sum_i_ang(nOfSides);
}

static inline double regPolygonIAng(int nOfSides)
{
  return math_reg_polygon_i_ang(nOfSides);
}

static inline double convexPolyExtAngle(int nOfSides)
{
  return math_convex_poly_ext_ang(nOfSides);
}

static inline double simpGrowth(double initial, double rate, double interval)
{
  return math_simp_growth(initial, rate, interval);
}

static inline double simpGrowthRate(double initial, double final, double interval)
{
  return math_simp_growthRate(initial, final, interval);
}

static inline double compGrowth(double initial, double rate, double interval)
{
  return math_comp_growth(initial, rate, interval);
}

static inline double compGrowthRate(double initial, double final, double interval)
{
  return math_comp_growthRate(initial, final, interval);
}

static inline bool isHappy(long long num)
{
  return math_is_happy(num);
}

static inline long long lcm(long long x, long long y)
{
  return math_lcm(x, y);
}

static inline double nPercentOfX(double x, double n)
{
  return math_n_percent_of_x(x, n);
}

static inline double nIsWhatPercentOfX(double x, double n)
{
  return math_n_is_what_percent_of_x(x, n);
}

static inline bool isPerfect(long long num)
{
  return math_is_perfect(num);
}

static inline std::vector<long long> primeFactors(long long num)
{
  Vector out = math_prime_factors(num);
  long long *arr = (long long *)vector_get_values(&out);
  std::vector<long long> result(arr, arr + out.length);
  vector_free(&out);
  free(arr);
  return result;
}

static inline bool isPrime(long long num)
{
  return math_is_prime(num);
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
  return math_gaussian_CDF(mu, stdDev, x);
}

static inline double mean(const std::vector<double> v)
{
  return math_mean(v.data(), v.size());
}

static inline double trimmedMean(const std::vector<double> v, double percentage)
{
  return math_trimmed_mean(v.data(), v.size(), percentage);
}

static inline double geometricMean(const std::vector<double> v)
{
  return math_geometric_mean(v.data(), v.size());
}

static inline double harmonicMean(const std::vector<double> v)
{
  return math_harmonic_mean(v.data(), v.size());
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
  return math_std_dev(v.data(), v.size());
}

static inline double sampleVariance(const std::vector<double> v)
{
  return math_sample_variance(v.data(), v.size());
}

static inline double sampleStdDev(const std::vector<double> v)
{
  return math_sample_std_dev(v.data(), v.size());
}

static inline double hypotenuse(double sideA, double sideB)
{
  return math_hypotenuse(sideA, sideB);
}

static inline double sideRTriangle(double hypotenuse, double sideA)
{
  return math_side_r_triangle(hypotenuse, sideA);
}

static inline double sideTriangleLC(double sideA, double sideB, double oppositeAng)
{
  return math_side_triangle_l_cos(sideA, sideB, oppositeAng);
}

static inline double angTriangleLC(double oppositeSide, double sideA, double sideB)
{
  return math_ang_triangle_l_cos(oppositeSide, sideA, sideB);
}

static inline double sideTriangleLS(double oppositeAng, double sideA, double oppositeAng2A)
{
  return math_side_triangle_l_sin(oppositeAng, sideA, oppositeAng2A);
}

static inline double angTriangleLS(double oppositeSide, double sideA, double oppositeAng2A)
{
  return math_ang_triangle_l_sin(oppositeSide, sideA, oppositeAng2A);
}

static inline double cubeVol(double side)
{
  return math_cube_vol(side);
}

static inline double cuboidVol(double length, double width, double height)
{
  return math_cuboid_vol(length, width, height);
}

static inline double prismVol(double baseArea, double height)
{
  return math_prism_vol(baseArea, height);
}

static inline double regularPrismVol(double baseSide, int nOfBaseSides, double height)
{
  return math_reg_prism_vol(baseSide, nOfBaseSides, height);
}

static inline double pyramidVol(double baseArea, double height)
{
  return math_pyramid_vol(baseArea, height);
}

static inline double regPyramidVol(double baseSide, int nOfBaseSides, double height)
{
  return math_reg_pyramid_vol(baseSide, nOfBaseSides, height);
}

static inline double cylinderVol(double baseRadius, double height)
{
  return math_cylinder_vol(baseRadius, height);
}

static inline double coneVol(double baseRadius, double height)
{
  return math_cone_vol(baseRadius, height);
}

static inline double sphereVol(double radius)
{
  return math_sphere_vol(radius);
}

} // namespace Math

#endif /* MATHLIB_HPP */
