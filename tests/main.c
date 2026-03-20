#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mathlib.h>
#include "include/array_cmp.h"
#include "include/test.h"

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
  size_t nOfModes, i;
  int status;
  long long arr1[SIZE_OF_ARR_1] = {2, 2, 2, 2, 3, 3, 5, 11},
            arr2[SIZE_OF_ARR_2] = {2, 2, 3, 3, 3, 7, 73},
            *arr3 = NULL,
            *arr4 = NULL;
  Point out, a, b, c, d, p;
  double *arr5 = NULL,
         *arr6 = malloc(sizeof(*arr6) * SIZE_OF_ARR_1),
         *arr7 = malloc(sizeof(*arr7) * SIZE_OF_ARR_2);
  ValueWeight *values_weights1 = malloc(sizeof(*values_weights1) * SIZE_OF_ARR_1),
              *values_weights2 = malloc(sizeof(*values_weights2) * SIZE_OF_ARR_2);

  arr3 = math_primeFactors(7920);
  arr4 = math_primeFactors(55188);

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

  arr5 = math_mode(arr6, SIZE_OF_ARR_1, &nOfModes);

  status = test(1, arrayCmp(arr1, arr3, SIZE_OF_ARR_1));
  if (status != 0)
    goto cleanup;
  status = test(2, arrayCmp(arr2, arr4, SIZE_OF_ARR_2));
  if (status != 0)
    goto cleanup;
  status = test(3, math_roundTo(M_PI, 2) == 3.14);
  if (status != 0)
    goto cleanup;
  status = test(4, math_roundTo(sqrt(2), 2) == 1.41);
  if (status != 0)
    goto cleanup;
  status = test(5, math_mean(arr6, SIZE_OF_ARR_1) == 3.75);
  if (status != 0)
    goto cleanup;
  status = test(6, math_roundTo(math_mean(arr7, SIZE_OF_ARR_2), 6) == 13.285714);
  if (status != 0)
    goto cleanup;
  status = test(7, math_roundTo(math_geometricMean(arr6, SIZE_OF_ARR_1), 6) == 3.07143);
  if (status != 0)
    goto cleanup;
  status = test(8, math_roundTo(math_geometricMean(arr7, SIZE_OF_ARR_2), 6) == 4.757802);
  if (status != 0)
    goto cleanup;
  status = test(9, math_roundTo(math_harmonicMean(arr6, SIZE_OF_ARR_1), 6) == 2.704918);
  if (status != 0)
    goto cleanup;
  status = test(10, math_roundTo(math_harmonicMean(arr7, SIZE_OF_ARR_2), 6) == 3.245917);
  if (status != 0)
    goto cleanup;
  status = test(11, math_roundTo(math_trimmedMean(arr6, SIZE_OF_ARR_1, 12), 6) == 2.833333);
  if (status != 0)
    goto cleanup;
  status = test(12, math_trimmedMean(arr7, SIZE_OF_ARR_2, 14) == 3.6);
  if (status != 0)
    goto cleanup;
  status = test(13, math_median(arr6, SIZE_OF_ARR_1) == 2.5);
  if (status != 0)
    goto cleanup;
  status = test(14, math_median(arr7, SIZE_OF_ARR_2) == 3);
  if (status != 0)
    goto cleanup;
  status = test(15, arr5[0] == 2 && nOfModes == 1);
  if (status != 0)
    goto cleanup;
  free(arr5);
  arr5 = math_mode(arr7, SIZE_OF_ARR_2, &nOfModes);
  status = test(16, arr5[0] == 3 && nOfModes == 1);
  if (status != 0)
    goto cleanup;
  status = test(17, math_min(arr6, SIZE_OF_ARR_1) == 2);
  if (status != 0)
    goto cleanup;
  status = test(18, math_min(arr7, SIZE_OF_ARR_2) == 2);
  if (status != 0)
    goto cleanup;
  status = test(19, math_max(arr6, SIZE_OF_ARR_1) == 11);
  if (status != 0)
    goto cleanup;
  status = test(20, math_max(arr7, SIZE_OF_ARR_2) == 73);
  if (status != 0)
    goto cleanup;
  status = test(21, math_range(arr6, SIZE_OF_ARR_1) == 9);
  if (status != 0)
    goto cleanup;
  status = test(22, math_range(arr7, SIZE_OF_ARR_2) == 71);
  if (status != 0)
    goto cleanup;
  status = test(23, math_midrange(arr6, SIZE_OF_ARR_1) == 4.5);
  if (status != 0)
    goto cleanup;
  status = test(24, math_midrange(arr7, SIZE_OF_ARR_2) == 35.5);
  if (status != 0)
    goto cleanup;
  status = test(25, math_roundTo(math_variance(arr6, SIZE_OF_ARR_1), 6) == 8.4375);
  if (status != 0)
    goto cleanup;
  status = test(26, math_roundTo(math_variance(arr7, SIZE_OF_ARR_2), 6) == 596.775510);
  if (status != 0)
    goto cleanup;
  status = test(27, math_roundTo(math_sampleVariance(arr6, SIZE_OF_ARR_1), 6) == 9.642857);
  if (status != 0)
    goto cleanup;
  status = test(28, math_roundTo(math_sampleVariance(arr7, SIZE_OF_ARR_2), 6) == 696.238095);
  if (status != 0)
    goto cleanup;
  status = test(29, math_roundTo(math_standardDeviation(arr6, SIZE_OF_ARR_1), 6) == 2.904738);
  if (status != 0)
    goto cleanup;
  status = test(30, math_roundTo(math_standardDeviation(arr7, SIZE_OF_ARR_2), 6) == 24.428989);
  if (status != 0)
    goto cleanup;
  status = test(31, math_roundTo(math_sampleStandardDeviation(arr6, SIZE_OF_ARR_1), 6) == 3.105295);
  if (status != 0)
    goto cleanup;
  status = test(32, math_roundTo(math_sampleStandardDeviation(arr7, SIZE_OF_ARR_2), 6) == 26.386324);
  if (status != 0)
    goto cleanup;
  arr6[3] = 3;
  free(arr5);
  arr5 = math_mode(arr6, SIZE_OF_ARR_1, &nOfModes);
  status = test(33, arr5[0] == 2 && arr5[1] == 3 && nOfModes == 2);
  if (status != 0)
    goto cleanup;
  status = test(34, math_roundTo(math_weightedMean(values_weights1, SIZE_OF_ARR_1), 6) == 2.933333);
  if (status != 0)
    goto cleanup;
  status = test(35, math_roundTo(math_weightedMean(values_weights2, SIZE_OF_ARR_2), 6) == 3.731183);
  if (status != 0)
    goto cleanup;
  status = test(36, math_lineYIntercept(a, b) == -2);
  if (status != 0)
    goto cleanup;
  status = test(37, math_lineYIntercept(c, d) == 1);
  if (status != 0)
    goto cleanup;
  out = math_midpointPoints(a, b);
  status = test(38, out.x == 1.5 && out.y == 2.5);
  if (status != 0)
    goto cleanup;
  out = math_midpointPoints(c, d);
  status = test(39, out.x == 4 && out.y == 9);
  if (status != 0)
    goto cleanup;
  status = test(40, math_isPrime(7919));
  if (status != 0)
    goto cleanup;
  status = test(41, !math_isPrime(5329));
  if (status != 0)
    goto cleanup;
  status = test(42, math_isPerfect(6));
  if (status != 0)
    goto cleanup;
  status = test(43, !math_isPerfect(7));
  if (status != 0)
    goto cleanup;
  status = test(44, math_isHappy(23));
  if (status != 0)
    goto cleanup;
  status = test(45, !math_isHappy(73));
  if (status != 0)
    goto cleanup;
  status = test(46, math_isArmstrong(370));
  if (status != 0)
    goto cleanup;
  status = test(47, !math_isArmstrong(125));
  if (status != 0)
    goto cleanup;
  status = test(48, math_nthRoot(4096, 4) == 8);
  if (status != 0)
    goto cleanup;
  status = test(49, round(math_nthRoot(389017, 3)) == 73);
  if (status != 0)
    goto cleanup;
  status = test(50, math_logarithm(1024, 4) == 5);
  if (status != 0)
    goto cleanup;
  status = test(51, math_logarithm(389017, 73) == 3);
  if (status != 0)
    goto cleanup;
  status = test(52, math_nPercentOfX(725, 5) == 36.25);
  if (status != 0)
    goto cleanup;
  status = test(53, math_nPercentOfX(1024, 25) == 256);
  if (status != 0)
    goto cleanup;
  status = test(54, math_nIsWhatPercentOfX(95, 7.6) == 8);
  if (status != 0)
    goto cleanup;
  status = test(55, math_nIsWhatPercentOfX(128, 16) == 12.5);
  if (status != 0)
    goto cleanup;
  status = test(56, math_simpleGrowth(5, 0.05, 3) == 5.75);
  if (status != 0)
    goto cleanup;
  status = test(57, math_simpleGrowth(140, 0.1, 4) == 196);
  if (status != 0)
    goto cleanup;
  status = test(58, math_roundTo(math_simpleGrowthRate(5, 5.5, 4), 6) == 0.025);
  if (status != 0)
    goto cleanup;
  status = test(59, math_roundTo(math_simpleGrowthRate(145, 153, 3), 6) == 0.018391);
  if (status != 0)
    goto cleanup;
  status = test(60, math_roundTo(math_compoundedGrowth(5, 0.2, 3), 6) == 8.64);
  if (status != 0)
    goto cleanup;
  status = test(61, math_roundTo(math_compoundedGrowth(2500, 0.17, 13), 6) == 19246.697092);
  if (status != 0)
    goto cleanup;
  status = test(62, math_roundTo(math_compoundedGrowthRate(5, 8.64, 3), 6) == 0.2);
  if (status != 0)
    goto cleanup;
  status = test(63, math_roundTo(math_compoundedGrowthRate(5200, 7640.50, 5), 6) == 0.08);
  if (status != 0)
    goto cleanup;
  status = test(64, math_gcd(40, 96) == 8);
  if (status != 0)
    goto cleanup;
  status = test(65, math_gcd(42, 9) == 3);
  if (status != 0)
    goto cleanup;
  status = test(66, math_lcm(6, 15) == 30);
  if (status != 0)
    goto cleanup;
  status = test(67, math_lcm(39, 9) == 117);
  if (status != 0)
    goto cleanup;
  status = test(68, math_factorial(20) == 2432902008176640000);
  if (status != 0)
    goto cleanup;
  status = test(69, math_factorial(17) == 355687428096000);
  if (status != 0)
    goto cleanup;
  status = test(70, math_permutation(6) == 720);
  if (status != 0)
    goto cleanup;
  status = test(71, math_permutation(8) == 40320);
  if (status != 0)
    goto cleanup;
  status = test(72, math_cyclePermutation(9) == 40320);
  if (status != 0)
    goto cleanup;
  status = test(73, math_cyclePermutation(6) == 120);
  if (status != 0)
    goto cleanup;
  status = test(74, math_arrangement(17, 11) == 494010316800);
  if (status != 0)
    goto cleanup;
  status = test(75, math_arrangement(9, 6) == 60480);
  if (status != 0)
    goto cleanup;
  status = test(76, math_combination(19, 15) == 3876);
  if (status != 0)
    goto cleanup;
  status = test(77, math_combination(9, 5) == 126);
  if (status != 0)
    goto cleanup;
  sprintf(str, "%e", math_factoriallf(60));
  status = test(78, strcmp(str, "8.320987e+081") == 0 || strcmp(str, "8.320987e+81") == 0);
  if (status != 0)
    goto cleanup;
  sprintf(str, "%e", math_factoriallf(73));
  status = test(79, strcmp(str, "4.470115e+105") == 0);
  if (status != 0)
    goto cleanup;
  sprintf(str, "%e", math_permutationlf(40));
  status = test(80, strcmp(str, "8.159153e+047") == 0 || strcmp(str, "8.159153e+47") == 0);
  if (status != 0)
    goto cleanup;
  sprintf(str, "%e", math_permutationlf(27));
  status = test(81, strcmp(str, "1.088887e+028") == 0 || strcmp(str, "1.088887e+28") == 0);
  if (status != 0)
    goto cleanup;
  sprintf(str, "%e", math_cyclePermutationlf(36));
  status = test(82, strcmp(str, "1.033315e+040") == 0 || strcmp(str, "1.033315e+40") == 0);
  if (status != 0)
    goto cleanup;
  sprintf(str, "%e", math_cyclePermutationlf(33));
  status = test(83, strcmp(str, "2.631308e+035") == 0 || strcmp(str, "2.631308e+35") == 0);
  if (status != 0)
    goto cleanup;
  status = test(84, round(math_arrangementlf(60, 6)) == 36045979200);
  if (status != 0)
    goto cleanup;
  status = test(85, round(math_arrangementlf(100, 7)) == 80678106432000);
  if (status != 0)
    goto cleanup;
  status = test(86, round(math_combinationlf(30, 21)) == 14307150);
  if (status != 0)
    goto cleanup;
  status = test(87, round(math_combinationlf(29, 15)) == 77558760);
  if (status != 0)
    goto cleanup;
  status = test(88, math_roundTo(math_binominal(10, 0.2, 6), 6) == 0.005505);
  if (status != 0)
    goto cleanup;
  status = test(89, math_binominal(4, 0.25, 1) == 0.421875);
  if (status != 0)
    goto cleanup;
  status = test(90, math_roundTo(math_poisson(0.45, 4), 5) == 0.00109);
  if (status != 0)
    goto cleanup;
  status = test(91, math_roundTo(math_poisson(0.75, 5), 5) == 0.00093);
  if (status != 0)
    goto cleanup;
  status = test(92, math_roundTo(math_gaussianCDF(0, 1, 3.5), 5) == 0.99977);
  if (status != 0)
    goto cleanup;
  status = test(93, math_roundTo(math_gaussianCDF(150000, 5000, 135000), 5) == 0.00135);
  if (status != 0)
    goto cleanup;
  status = test(94, math_hypotenuse(3, 4) == 5);
  if (status != 0)
    goto cleanup;
  status = test(95, math_roundTo(math_hypotenuse(7, 8), 5) == 10.63015);
  if (status != 0)
    goto cleanup;
  status = test(96, math_roundTo(math_sideRTriangle(4, 2), 6) == 3.464102);
  if (status != 0)
    goto cleanup;
  status = test(97, math_sideRTriangle(15, 12) == 9);
  if (status != 0)
    goto cleanup;
  status = test(98, math_roundTo(math_sideTriangleLC(4, 3, math_deg2rad(60)), 6) == 3.605551);
  if (status != 0)
    goto cleanup;
  status = test(99, math_roundTo(math_sideTriangleLC(9, 7, math_deg2rad(30)), 5) == 4.56955);
  if (status != 0)
    goto cleanup;
  status = test(100, round(math_rad2deg(math_angTriangleLC(2, 4, 3.464102))) == 30);
  if (status != 0)
    goto cleanup;
  status = test(101, math_roundTo(math_angTriangleLC(5, 7, 9), 5) == 0.58569);
  if (status != 0)
    goto cleanup;
  status = test(102, math_roundTo(math_sideTriangleLS(math_deg2rad(60), 4, math_deg2rad(45)), 6) == 4.898979);
  if (status != 0)
    goto cleanup;
  status = test(103, math_roundTo(math_sideTriangleLS(math_deg2rad(45), 8, math_deg2rad(30)), 5) == 11.31371);
  if (status != 0)
    goto cleanup;
  status = test(104, round(math_rad2deg(math_angTriangleLS(4, 4, math_deg2rad(45)))) == 45);
  if (status != 0)
    goto cleanup;
  status = test(105, math_roundTo(math_angTriangleLS(10, 8, math_deg2rad(30)), 5) == 0.67513);
  if (status != 0)
    goto cleanup;
  status = test(106, math_triangleArea1(4, 5) == 10);
  if (status != 0)
    goto cleanup;
  status = test(107, math_triangleArea1(7, 8) == 28);
  if (status != 0)
    goto cleanup;
  status = test(108, math_roundTo(math_triangleArea2(2, 4, math_deg2rad(60)), 4) == 3.4641);
  if (status != 0)
    goto cleanup;
  status = test(109, math_roundTo(math_triangleArea2(8, 7, math_deg2rad(54)), 5) == 22.65248);
  if (status != 0)
    goto cleanup;
  status = test(110, math_triangleArea3(3, 4, 5) == 6);
  if (status != 0)
    goto cleanup;
  status = test(111, math_roundTo(math_triangleArea3(10, 8, 5), 5) == 19.81004);
  if (status != 0)
    goto cleanup;
  status = test(112, math_squareArea(4) == 16);
  if (status != 0)
    goto cleanup;
  status = test(113, math_squareArea(7) == 49);
  if (status != 0)
    goto cleanup;
  status = test(114, math_retangleArea(4, 6) == 24);
  if (status != 0)
    goto cleanup;
  status = test(115, math_retangleArea(3, 7) == 21);
  if (status != 0)
    goto cleanup;
  status = test(116, math_rhombusArea(5, 6) == 15);
  if (status != 0)
    goto cleanup;
  status = test(117, math_rhombusArea(7, 8) == 28);
  if (status != 0)
    goto cleanup;
  status = test(118, math_parallelogramArea1(3, 5) == 15);
  if (status != 0)
    goto cleanup;
  status = test(119, math_parallelogramArea1(4, 7) == 28);
  if (status != 0)
    goto cleanup;
  status = test(120, math_roundTo(math_parallelogramArea2(4, 6, math_deg2rad(30)), 6) == 12);
  if (status != 0)
    goto cleanup;
  status = test(121, math_roundTo(math_parallelogramArea2(7, 5, math_deg2rad(36)), 6) == 20.572484);
  if (status != 0)
    goto cleanup;
  status = test(122, math_trapezoidArea(7, 5, 3) == 18);
  if (status != 0)
    goto cleanup;
  status = test(123, math_trapezoidArea(8, 12, 4) == 40);
  if (status != 0)
    goto cleanup;
  status = test(124, math_roundTo(math_regPolygonArea(7, 3), 5) == 21.21762);
  if (status != 0)
    goto cleanup;
  status = test(125, math_roundTo(math_regPolygonArea(5, 6), 4) == 64.9519);
  if (status != 0)
    goto cleanup;
  status = test(126, math_roundTo(math_circleArea(4), 6) == 50.265482);
  if (status != 0)
    goto cleanup;
  status = test(127, math_roundTo(math_circleArea(8), 6) == 201.06193);
  if (status != 0)
    goto cleanup;
  status = test(128, math_roundTo(math_circularSectorArea1(math_deg2rad(45), 4), 6) == 6.283185);
  if (status != 0)
    goto cleanup;
  status = test(129, math_roundTo(math_circularSectorArea1(math_deg2rad(30), 7), 6) == 12.82817);
  if (status != 0)
    goto cleanup;
  status = test(130, math_circularSectorArea2(6, 4) == 12);
  if (status != 0)
    goto cleanup;
  status = test(131, math_roundTo(math_circularSectorArea2(3, 5), 6) == 7.5);
  if (status != 0)
    goto cleanup;
  status = test(132, math_roundTo(math_ellipseArea(4, 6), 6) == 75.398224);
  if (status != 0)
    goto cleanup;
  status = test(133, math_roundTo(math_ellipseArea(3, 5), 6) == 47.12389);
  if (status != 0)
    goto cleanup;
  status = test(134, math_cubeArea(4) == 96);
  if (status != 0)
    goto cleanup;
  status = test(135, math_cubeArea(8) == 384);
  if (status != 0)
    goto cleanup;
  status = test(136, math_cuboidArea(4, 5, 6) == 148);
  if (status != 0)
    goto cleanup;
  status = test(137, math_cuboidArea(7, 3, 5) == 142);
  if (status != 0)
    goto cleanup;
  status = test(138, math_prismArea(16, 16, 5) == 112);
  if (status != 0)
    goto cleanup;
  status = test(139, math_prismArea(21.21762, 21, 9) == 231.43524);
  if (status != 0)
    goto cleanup;
  status = test(140, math_regularPrismArea(4, 4, 5) == 112);
  if (status != 0)
    goto cleanup;
  status = test(141, math_roundTo(math_regularPrismArea(3, 3, 7), 6) == 70.794229);
  if (status != 0)
    goto cleanup;
  status = test(142, math_roundTo(math_pyramidArea(9, 12, 4.2720018), 6) == 34.632011);
  if (status != 0)
    goto cleanup;
  status = test(143, math_pyramidArea(16, 16, 5) == 56);
  if (status != 0)
    goto cleanup;
  status = test(144, math_roundTo(math_regPyramidArea(3, 4, 4), 6) == 34.632011);
  if (status != 0)
    goto cleanup;
  status = test(145, math_roundTo(math_regPyramidArea(4, 6, 7), 6) == 135.292215);
  if (status != 0)
    goto cleanup;
  status = test(146, math_roundTo(math_cylinderArea(2, 5.5), 6) == 94.24778);
  if (status != 0)
    goto cleanup;
  status = test(147, math_roundTo(math_cylinderArea(4, 8), 6) == 301.592895);
  if (status != 0)
    goto cleanup;
  status = test(148, math_roundTo(math_coneArea(4, 6), 6) == 140.88287);
  if (status != 0)
    goto cleanup;
  status = test(149, math_roundTo(math_coneArea(3.5, 7), 6) == 124.53849);
  if (status != 0)
    goto cleanup;
  status = test(150, math_roundTo(math_sphereArea(4), 6) == 201.06193);
  if (status != 0)
    goto cleanup;
  status = test(151, math_roundTo(math_sphereArea(7), 6) == 615.75216);
  if (status != 0)
    goto cleanup;
  status = test(152, math_cubeVol(4) == 64);
  if (status != 0)
    goto cleanup;
  status = test(153, math_cubeVol(8) == 512);
  if (status != 0)
    goto cleanup;
  status = test(154, math_cuboidVol(4, 5, 6) == 120);
  if (status != 0)
    goto cleanup;
  status = test(155, math_cuboidVol(7, 3, 5) == 105);
  if (status != 0)
    goto cleanup;
  status = test(156, round(math_prismVol(16, 5)) == 80);
  if (status != 0)
    goto cleanup;
  status = test(157, round(math_prismVol(20, 7)) == 140);
  if (status != 0)
    goto cleanup;
  status = test(158, round(math_regularPrismVol(4, 4, 5)) == 80);
  if (status != 0)
    goto cleanup;
  status = test(159, math_roundTo(math_regularPrismVol(3, 3, 7), 6) == 27.2798);
  if (status != 0)
    goto cleanup;
  status = test(160, round(math_pyramidVol(9, 4)) == 12);
  if (status != 0)
    goto cleanup;
  status = test(161, math_roundTo(math_pyramidVol(16, 5), 6) == 26.666667);
  if (status != 0)
    goto cleanup;
  status = test(162, round(math_regPyramidVol(3, 4, 4)) == 12);
  if (status != 0)
    goto cleanup;
  status = test(163, round(math_regPyramidVol(4, 6, 7)) == 97);
  if (status != 0)
    goto cleanup;
  status = test(164, math_roundTo(math_cylinderVol(2, 5.5), 6) == 69.115038);
  if (status != 0)
    goto cleanup;
  status = test(165, math_roundTo(math_cylinderVol(4, 8), 6) == 402.12386);
  if (status != 0)
    goto cleanup;
  status = test(166, math_roundTo(math_coneVol(4, 6), 6) == 100.530965);
  if (status != 0)
    goto cleanup;
  status = test(167, math_roundTo(math_coneVol(3.5, 7), 6) == 89.79719);
  if (status != 0)
    goto cleanup;
  status = test(168, math_roundTo(math_sphereVol(4), 6) == 268.082573);
  if (status != 0)
    goto cleanup;
  status = test(169, math_roundTo(math_sphereVol(7), 6) == 1436.75504);
  if (status != 0)
    goto cleanup;
  c.x = c.y = -1;
  d.x = 2;
  d.y = 3;
  status = test(170, math_distancePoints(c, d) == 5);
  if (status != 0)
    goto cleanup;
  c.x = 1;
  c.y = 2;
  d.x = 7;
  d.y = 11;
  status = test(171, math_roundTo(math_distancePoints(c, d), 6) == 10.816654);
  if (status != 0)
    goto cleanup;
  status = test(172, math_roundTo(math_distancePointLine(3, -2, p), 6) == 0.632456);
  if (status != 0)
    goto cleanup;
  p.x = p.y = 2;
  status = test(173, math_roundTo(math_distancePointLine(1, -5, p), 6) == 3.535534);
  if (status != 0)
    goto cleanup;
  status = test(174, math_slopeLine(a, b) == 3);
  if (status != 0)
    goto cleanup;
  c.x = -4;
  c.y = 1;
  d.x = 5;
  d.y = 7;
  status = test(175, math_slopeLine(c, d) == 2.0 / 3);
  if (status != 0)
    goto cleanup;
  status = test(176, math_roundTo(math_rad2deg(math_inclinationLine(a, b)), 6) == 71.565051);
  if (status != 0)
    goto cleanup;
  status = test(177, math_roundTo(math_rad2deg(math_inclinationLine(c, d)), 6) == 33.690068);
  if (status != 0)
    goto cleanup;
  status = test(178, math_roundTo(math_circlePerimeter(5), 6) == 31.415927);
  if (status != 0)
    goto cleanup;
  status = test(179, math_roundTo(math_circlePerimeter(7), 6) == 43.982297);
  if (status != 0)
    goto cleanup;
  status = test(180, math_polygonDiagonals(6) == 9);
  if (status != 0)
    goto cleanup;
  status = test(181, math_polygonDiagonals(4) == 2);
  if (status != 0)
    goto cleanup;
  status = test(182, round(math_rad2deg(math_convexPolySumIntAng(5))) == 540);
  if (status != 0)
    goto cleanup;
  status = test(183, round(math_rad2deg(math_convexPolySumIntAng(6))) == 720);
  if (status != 0)
    goto cleanup;
  status = test(184, round(math_rad2deg(math_regPolygonIAng(5))) == 108);
  if (status != 0)
    goto cleanup;
  status = test(185, round(math_rad2deg(math_regPolygonIAng(6))) == 120);
  if (status != 0)
    goto cleanup;
  status = test(186, round(math_rad2deg(math_convexPolyExtAngle(5))) == 72);
  if (status != 0)
    goto cleanup;
  status = test(187, round(math_rad2deg(math_convexPolyExtAngle(6))) == 60);
  if (status != 0)
    goto cleanup;
  status = test(188, math_polygonDiagonals(3) == 0);
  if (status != 0)
    goto cleanup;
  status = test(189, round(math_rad2deg(math_convexPolySumIntAng(3))) == 180);
  if (status != 0)
    goto cleanup;
  status = test(190, round(math_rad2deg(math_regPolygonIAng(3))) == 60);
  if (status != 0)
    goto cleanup;
  status = test(191, round(math_rad2deg(math_convexPolyExtAngle(3))) == 120);
  if (status != 0)
    goto cleanup;
  status = test(192, math_arrangement(7, 0) == 1);
  if (status != 0)
    goto cleanup;
  status = test(193, math_arrangementlf(7, 0) == 1);
  if (status != 0)
    goto cleanup;
  status = test(194, math_roundTo(math_sideTriangleLC(5, 7, math_deg2rad(179)), 5) == 11.99956);
  if (status != 0)
    goto cleanup;
  status = test(195, math_roundTo(math_logarithm(1000, 10), 6) == 3);
  if (status != 0)
    goto cleanup;

  puts("Passed all tests successfully!\n");

cleanup:
  free(arr3);
  free(arr4);
  free(arr5);
  free(arr6);
  free(arr7);
  free(values_weights1);
  free(values_weights2);

  return status;
}
