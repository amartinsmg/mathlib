#include <iostream>
#include <cstdlib>
#include <cstring>
#include <mathlib.hpp>
#include "include/test.hpp"

extern "C"
{
#include "include/array_cmp.h"
}

#define SIZE_OF_ARR_1 8
#define SIZE_OF_ARR_2 7

/**
 * @brief Main function to test mathematical algorithms.
 * This is the main function used to test different mathematical algorithms
 * by comparing the results with pre-calculated values. It serves as a testing
 * ground for verifying the correctness of the algorithms.
 *
 * @return An integer representing the exit status of the program.
 */

int main()
{
  char str[100];
  size_t i;
  int status = EXIT_FAILURE;
  long long arr1[SIZE_OF_ARR_1] = {2, 2, 2, 2, 3, 3, 5, 11},
            arr2[SIZE_OF_ARR_2] = {2, 2, 3, 3, 3, 7, 73},
            *arr3 = nullptr,
            *arr4 = nullptr;
  Point out, a, b, c, d, p;
  Vector v = {0};
  double *arr5 = nullptr,
         *arr6 = (double *)malloc(sizeof(*arr6) * SIZE_OF_ARR_1),
         *arr7 = (double *)malloc(sizeof(*arr7) * SIZE_OF_ARR_2);
  ValueWeight *values_weights1 = (ValueWeight *)malloc(sizeof(*values_weights1) * SIZE_OF_ARR_1),
              *values_weights2 = (ValueWeight *)malloc(sizeof(*values_weights2) * SIZE_OF_ARR_2);

  a.x = a.y = 1;
  b.x = 2;
  b.y = 4;
  c.x = 3;
  c.y = 7;
  d.x = 5;
  d.y = 11;
  p.x = p.y = 0;

  for (i = 0; i < SIZE_OF_ARR_1; i++)
    arr6[i] = values_weights1[i].value = values_weights1[SIZE_OF_ARR_1 - 1 - i].weight = (double)arr1[i];
  for (i = 0; i < SIZE_OF_ARR_2; i++)
    arr7[i] = values_weights2[i].value = values_weights2[SIZE_OF_ARR_2 - 1 - i].weight = (double)arr2[i];

  try
  {
    v = Math::primeFactors(7920);

    arr3 = (long long *)vector_get_values(&v);

    vector_free(&v);

    v = Math::primeFactors(55188);

    arr4 = (long long *)vector_get_values(&v);

    vector_free(&v);
    v = Math::mode(arr6, SIZE_OF_ARR_1);
    arr5 = (double *)vector_get_values(&v);

    test(1, arrayCmp(arr1, arr3, SIZE_OF_ARR_1));
    test(2, arrayCmp(arr2, arr4, SIZE_OF_ARR_2));
    test(3, Math::roundTo(M_PI, 2) == 3.14);
    test(4, Math::roundTo(sqrt(2), 2) == 1.41);
    test(5, Math::mean(arr6, SIZE_OF_ARR_1) == 3.75);
    test(6, Math::roundTo(Math::mean(arr7, SIZE_OF_ARR_2), 6) == 13.285714);
    test(7, Math::roundTo(Math::geometricMean(arr6, SIZE_OF_ARR_1), 6) == 3.07143);
    test(8, Math::roundTo(Math::geometricMean(arr7, SIZE_OF_ARR_2), 6) == 4.757802);
    test(9, Math::roundTo(Math::harmonicMean(arr6, SIZE_OF_ARR_1), 6) == 2.704918);
    test(10, Math::roundTo(Math::harmonicMean(arr7, SIZE_OF_ARR_2), 6) == 3.245917);
    test(11, Math::roundTo(Math::trimmedMean(arr6, SIZE_OF_ARR_1, 12), 6) == 2.833333);
    test(12, Math::trimmedMean(arr7, SIZE_OF_ARR_2, 14) == 3.6);
    test(13, Math::median(arr6, SIZE_OF_ARR_1) == 2.5);
    test(14, Math::median(arr7, SIZE_OF_ARR_2) == 3);
    test(15, arr5[0] == 2 && v.length == 1);
    vector_free(&v);
    free(arr5);
    v = Math::mode(arr7, SIZE_OF_ARR_2);
    arr5 = (double *)vector_get_values(&v);
    test(16, arr5[0] == 3 && v.length == 1);
    test(17, Math::min(arr6, SIZE_OF_ARR_1) == 2);
    test(18, Math::min(arr7, SIZE_OF_ARR_2) == 2);
    test(19, Math::max(arr6, SIZE_OF_ARR_1) == 11);
    test(20, Math::max(arr7, SIZE_OF_ARR_2) == 73);
    test(21, Math::range(arr6, SIZE_OF_ARR_1) == 9);
    test(22, Math::range(arr7, SIZE_OF_ARR_2) == 71);
    test(23, Math::midrange(arr6, SIZE_OF_ARR_1) == 4.5);
    test(24, Math::midrange(arr7, SIZE_OF_ARR_2) == 35.5);
    test(25, Math::roundTo(Math::variance(arr6, SIZE_OF_ARR_1), 6) == 8.4375);
    test(26, Math::roundTo(Math::variance(arr7, SIZE_OF_ARR_2), 6) == 596.775510);
    test(27, Math::roundTo(Math::sampleVariance(arr6, SIZE_OF_ARR_1), 6) == 9.642857);
    test(28, Math::roundTo(Math::sampleVariance(arr7, SIZE_OF_ARR_2), 6) == 696.238095);
    test(29, Math::roundTo(Math::stdDev(arr6, SIZE_OF_ARR_1), 6) == 2.904738);
    test(30, Math::roundTo(Math::stdDev(arr7, SIZE_OF_ARR_2), 6) == 24.428989);
    test(31, Math::roundTo(Math::sampleStdDev(arr6, SIZE_OF_ARR_1), 6) == 3.105295);
    test(32, Math::roundTo(Math::sampleStdDev(arr7, SIZE_OF_ARR_2), 6) == 26.386324);
    arr6[3] = 3;
    vector_free(&v);
    free(arr5);
    v = Math::mode(arr6, SIZE_OF_ARR_1);
    arr5 = (double *)vector_get_values(&v);
    test(33, arr5[0] == 2 && arr5[1] == 3 && v.length == 2);
    test(34, Math::roundTo(Math::weightedMean(values_weights1, SIZE_OF_ARR_1), 6) == 2.933333);
    test(35, Math::roundTo(Math::weightedMean(values_weights2, SIZE_OF_ARR_2), 6) == 3.731183);
    test(36, Math::lineYIntercept(a, b) == -2);
    test(37, Math::lineYIntercept(c, d) == 1);
    out = Math::midpointPoints(a, b);
    test(38, out.x == 1.5 && out.y == 2.5);
    out = Math::midpointPoints(c, d);
    test(39, out.x == 4 && out.y == 9);
    test(40, Math::isPrime(7919));
    test(41, !Math::isPrime(5329));
    test(42, Math::isPerfect(6));
    test(43, !Math::isPerfect(7));
    test(44, Math::isHappy(23));
    test(45, !Math::isHappy(73));
    test(46, Math::isArmstrong(370));
    test(47, !Math::isArmstrong(125));
    test(48, Math::nthRoot(4096, 4) == 8);
    test(49, round(Math::nthRoot(389017, 3)) == 73);
    test(50, Math::logarithm(1024, 4) == 5);
    test(51, Math::logarithm(389017, 73) == 3);
    test(52, Math::nPercentOfX(725, 5) == 36.25);
    test(53, Math::nPercentOfX(1024, 25) == 256);
    test(54, Math::nIsWhatPercentOfX(95, 7.6) == 8);
    test(55, Math::nIsWhatPercentOfX(128, 16) == 12.5);
    test(56, Math::simpleGrowth(5, 0.05, 3) == 5.75);
    test(57, Math::simpleGrowth(140, 0.1, 4) == 196);
    test(58, Math::roundTo(Math::simpleGrowthRate(5, 5.5, 4), 6) == 0.025);
    test(59, Math::roundTo(Math::simpleGrowthRate(145, 153, 3), 6) == 0.018391);
    test(60, Math::roundTo(Math::compoundedGrowth(5, 0.2, 3), 6) == 8.64);
    test(61, Math::roundTo(Math::compoundedGrowth(2500, 0.17, 13), 6) == 19246.697092);
    test(62, Math::roundTo(Math::compoundedGrowthRate(5, 8.64, 3), 6) == 0.2);
    test(63, Math::roundTo(Math::compoundedGrowthRate(5200, 7640.50, 5), 6) == 0.08);
    test(64, Math::gcd(40, 96) == 8);
    test(65, Math::gcd(42, 9) == 3);
    test(66, Math::lcm(6, 15) == 30);
    test(67, Math::lcm(39, 9) == 117);
    test(68, Math::factorial(20) == 2432902008176640000);
    test(69, Math::factorial(17) == 355687428096000);
    test(70, Math::permutation(6) == 720);
    test(71, Math::permutation(8) == 40320);
    test(72, Math::cyclePermutation(9) == 40320);
    test(73, Math::cyclePermutation(6) == 120);
    test(74, Math::arrangement(17, 11) == 494010316800);
    test(75, Math::arrangement(9, 6) == 60480);
    test(76, Math::combination(19, 15) == 3876);
    test(77, Math::combination(9, 5) == 126);
    sprintf(str, "%e", Math::factoriallf(60));
    test(78, strcmp(str, "8.320987e+081") == 0 || strcmp(str, "8.320987e+81") == 0);
    sprintf(str, "%e", Math::factoriallf(73));
    test(79, strcmp(str, "4.470115e+105") == 0);
    sprintf(str, "%e", Math::permutationlf(40));
    test(80, strcmp(str, "8.159153e+047") == 0 || strcmp(str, "8.159153e+47") == 0);
    sprintf(str, "%e", Math::permutationlf(27));
    test(81, strcmp(str, "1.088887e+028") == 0 || strcmp(str, "1.088887e+28") == 0);
    sprintf(str, "%e", Math::cyclePermutationlf(36));
    test(82, strcmp(str, "1.033315e+040") == 0 || strcmp(str, "1.033315e+40") == 0);
    sprintf(str, "%e", Math::cyclePermutationlf(33));
    test(83, strcmp(str, "2.631308e+035") == 0 || strcmp(str, "2.631308e+35") == 0);
    test(84, round(Math::arrangementlf(60, 6)) == 36045979200);
    test(85, round(Math::arrangementlf(100, 7)) == 80678106432000);
    test(86, round(Math::combinationlf(30, 21)) == 14307150);
    test(87, round(Math::combinationlf(29, 15)) == 77558760);
    test(88, Math::roundTo(Math::binominal(10, 0.2, 6), 6) == 0.005505);
    test(89, Math::binominal(4, 0.25, 1) == 0.421875);
    test(90, Math::roundTo(Math::poisson(0.45, 4), 5) == 0.00109);
    test(91, Math::roundTo(Math::poisson(0.75, 5), 5) == 0.00093);
    test(92, Math::roundTo(Math::gaussianCDF(0, 1, 3.5), 5) == 0.99977);
    test(93, Math::roundTo(Math::gaussianCDF(150000, 5000, 135000), 5) == 0.00135);
    test(94, Math::hypotenuse(3, 4) == 5);
    test(95, Math::roundTo(Math::hypotenuse(7, 8), 5) == 10.63015);
    test(96, Math::roundTo(Math::sideRTriangle(4, 2), 6) == 3.464102);
    test(97, Math::sideRTriangle(15, 12) == 9);
    test(98, Math::roundTo(Math::sideTriangleLC(4, 3, Math::deg2rad(60)), 6) == 3.605551);
    test(99, Math::roundTo(Math::sideTriangleLC(9, 7, Math::deg2rad(30)), 5) == 4.56955);
    test(100, round(Math::rad2deg(Math::angTriangleLC(2, 4, 3.464102))) == 30);
    test(101, Math::roundTo(Math::angTriangleLC(5, 7, 9), 5) == 0.58569);
    test(102, Math::roundTo(Math::sideTriangleLS(Math::deg2rad(60), 4, Math::deg2rad(45)), 6) == 4.898979);
    test(103, Math::roundTo(Math::sideTriangleLS(Math::deg2rad(45), 8, Math::deg2rad(30)), 5) == 11.31371);
    test(104, round(Math::rad2deg(Math::angTriangleLS(4, 4, Math::deg2rad(45)))) == 45);
    test(105, Math::roundTo(Math::angTriangleLS(10, 8, Math::deg2rad(30)), 5) == 0.67513);
    test(106, Math::triangleArea1(4, 5) == 10);
    test(107, Math::triangleArea1(7, 8) == 28);
    test(108, Math::roundTo(Math::triangleArea2(2, 4, Math::deg2rad(60)), 4) == 3.4641);
    test(109, Math::roundTo(Math::triangleArea2(8, 7, Math::deg2rad(54)), 5) == 22.65248);
    test(110, Math::triangleArea3(3, 4, 5) == 6);
    test(111, Math::roundTo(Math::triangleArea3(10, 8, 5), 5) == 19.81004);
    test(112, Math::squareArea(4) == 16);
    test(113, Math::squareArea(7) == 49);
    test(114, Math::retangleArea(4, 6) == 24);
    test(115, Math::retangleArea(3, 7) == 21);
    test(116, Math::rhombusArea(5, 6) == 15);
    test(117, Math::rhombusArea(7, 8) == 28);
    test(118, Math::parallelogramArea1(3, 5) == 15);
    test(119, Math::parallelogramArea1(4, 7) == 28);
    test(120, Math::roundTo(Math::parallelogramArea2(4, 6, Math::deg2rad(30)), 6) == 12);
    test(121, Math::roundTo(Math::parallelogramArea2(7, 5, Math::deg2rad(36)), 6) == 20.572484);
    test(122, Math::trapezoidArea(7, 5, 3) == 18);
    test(123, Math::trapezoidArea(8, 12, 4) == 40);
    test(124, Math::roundTo(Math::regPolygonArea(7, 3), 5) == 21.21762);
    test(125, Math::roundTo(Math::regPolygonArea(5, 6), 4) == 64.9519);
    test(126, Math::roundTo(Math::circleArea(4), 6) == 50.265482);
    test(127, Math::roundTo(Math::circleArea(8), 6) == 201.06193);
    test(128, Math::roundTo(Math::circularSectorArea1(Math::deg2rad(45), 4), 6) == 6.283185);
    test(129, Math::roundTo(Math::circularSectorArea1(Math::deg2rad(30), 7), 6) == 12.82817);
    test(130, Math::circularSectorArea2(6, 4) == 12);
    test(131, Math::roundTo(Math::circularSectorArea2(3, 5), 6) == 7.5);
    test(132, Math::roundTo(Math::ellipseArea(4, 6), 6) == 75.398224);
    test(133, Math::roundTo(Math::ellipseArea(3, 5), 6) == 47.12389);
    test(134, Math::cubeArea(4) == 96);
    test(135, Math::cubeArea(8) == 384);
    test(136, Math::cuboidArea(4, 5, 6) == 148);
    test(137, Math::cuboidArea(7, 3, 5) == 142);
    test(138, Math::prismArea(16, 16, 5) == 112);
    test(139, Math::prismArea(21.21762, 21, 9) == 231.43524);
    test(140, Math::regularPrismArea(4, 4, 5) == 112);
    test(141, Math::roundTo(Math::regularPrismArea(3, 3, 7), 6) == 70.794229);
    test(142, Math::roundTo(Math::pyramidArea(9, 12, 4.2720018), 6) == 34.632011);
    test(143, Math::pyramidArea(16, 16, 5) == 56);
    test(144, Math::roundTo(Math::regPyramidArea(3, 4, 4), 6) == 34.632011);
    test(145, Math::roundTo(Math::regPyramidArea(4, 6, 7), 6) == 135.292215);
    test(146, Math::roundTo(Math::cylinderArea(2, 5.5), 6) == 94.24778);
    test(147, Math::roundTo(Math::cylinderArea(4, 8), 6) == 301.592895);
    test(148, Math::roundTo(Math::coneArea(4, 6), 6) == 140.88287);
    test(149, Math::roundTo(Math::coneArea(3.5, 7), 6) == 124.53849);
    test(150, Math::roundTo(Math::sphereArea(4), 6) == 201.06193);
    test(151, Math::roundTo(Math::sphereArea(7), 6) == 615.75216);
    test(152, Math::cubeVol(4) == 64);
    test(153, Math::cubeVol(8) == 512);
    test(154, Math::cuboidVol(4, 5, 6) == 120);
    test(155, Math::cuboidVol(7, 3, 5) == 105);
    test(156, round(Math::prismVol(16, 5)) == 80);
    test(157, round(Math::prismVol(20, 7)) == 140);
    test(158, round(Math::regularPrismVol(4, 4, 5)) == 80);
    test(159, Math::roundTo(Math::regularPrismVol(3, 3, 7), 6) == 27.2798);
    test(160, round(Math::pyramidVol(9, 4)) == 12);
    test(161, Math::roundTo(Math::pyramidVol(16, 5), 6) == 26.666667);
    test(162, round(Math::regPyramidVol(3, 4, 4)) == 12);
    test(163, round(Math::regPyramidVol(4, 6, 7)) == 97);
    test(164, Math::roundTo(Math::cylinderVol(2, 5.5), 6) == 69.115038);
    test(165, Math::roundTo(Math::cylinderVol(4, 8), 6) == 402.12386);
    test(166, Math::roundTo(Math::coneVol(4, 6), 6) == 100.530965);
    test(167, Math::roundTo(Math::coneVol(3.5, 7), 6) == 89.79719);
    test(168, Math::roundTo(Math::sphereVol(4), 6) == 268.082573);
    test(169, Math::roundTo(Math::sphereVol(7), 6) == 1436.75504);
    c.x = c.y = -1;
    d.x = 2;
    d.y = 3;
    test(170, Math::distancePoints(c, d) == 5);
    c.x = 1;
    c.y = 2;
    d.x = 7;
    d.y = 11;
    test(171, Math::roundTo(Math::distancePoints(c, d), 6) == 10.816654);
    test(172, Math::roundTo(Math::distancePointLine(3, -2, p), 6) == 0.632456);
    p.x = p.y = 2;
    test(173, Math::roundTo(Math::distancePointLine(1, -5, p), 6) == 3.535534);
    test(174, Math::slopeLine(a, b) == 3);
    c.x = -4;
    c.y = 1;
    d.x = 5;
    d.y = 7;
    test(175, Math::slopeLine(c, d) == 2.0 / 3);
    test(176, Math::roundTo(Math::rad2deg(Math::inclinationLine(a, b)), 6) == 71.565051);
    test(177, Math::roundTo(Math::rad2deg(Math::inclinationLine(c, d)), 6) == 33.690068);
    test(178, Math::roundTo(Math::circlePerimeter(5), 6) == 31.415927);
    test(179, Math::roundTo(Math::circlePerimeter(7), 6) == 43.982297);
    test(180, Math::polygonDiagonals(6) == 9);
    test(181, Math::polygonDiagonals(4) == 2);
    test(182, round(Math::rad2deg(Math::convexPolySumIntAng(5))) == 540);
    test(183, round(Math::rad2deg(Math::convexPolySumIntAng(6))) == 720);
    test(184, round(Math::rad2deg(Math::regPolygonIAng(5))) == 108);
    test(185, round(Math::rad2deg(Math::regPolygonIAng(6))) == 120);
    test(186, round(Math::rad2deg(Math::convexPolyExtAngle(5))) == 72);
    test(187, round(Math::rad2deg(Math::convexPolyExtAngle(6))) == 60);
    test(188, Math::polygonDiagonals(3) == 0);
    test(189, round(Math::rad2deg(Math::convexPolySumIntAng(3))) == 180);
    test(190, round(Math::rad2deg(Math::regPolygonIAng(3))) == 60);
    test(191, round(Math::rad2deg(Math::convexPolyExtAngle(3))) == 120);
    test(192, Math::arrangement(7, 0) == 1);
    test(193, Math::arrangementlf(7, 0) == 1);
    test(194, Math::roundTo(Math::sideTriangleLC(5, 7, Math::deg2rad(179)), 5) == 11.99956);
    test(195, Math::roundTo(Math::logarithm(1000, 10), 6) == 3);

    std::cout << "Passed all tests successfully!\n";

    status = EXIT_SUCCESS;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  vector_free(&v);
  free(arr3);
  free(arr4);
  free(arr5);
  free(arr6);
  free(arr7);
  free(values_weights1);
  free(values_weights2);

  return status;
}
