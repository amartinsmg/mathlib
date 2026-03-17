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
  unsigned nOfModes;
  int i, status;
  long long arr1[SIZE_OF_ARR_1] = {2, 2, 2, 2, 3, 3, 5, 11},
            arr2[SIZE_OF_ARR_2] = {2, 2, 3, 3, 3, 7, 73},
            *arr3 = primeFactors(7920),
            *arr4 = primeFactors(55188);
  double *arr5 = NULL,
         *arr6 = malloc(sizeof(*arr6) * SIZE_OF_ARR_1),
         *arr7 = malloc(sizeof(*arr7) * SIZE_OF_ARR_2),
         *arr8 = equationOfLine(1, 1, 2, 4),
         **matrix1 = malloc(sizeof(*matrix1) * SIZE_OF_ARR_1),
         **matrix2 = malloc(sizeof(*matrix2) * SIZE_OF_ARR_2);

  for (i = 0; i < SIZE_OF_ARR_1; i++)
    matrix1[i] = malloc(sizeof(**matrix1) * 2);
  for (i = 0; i < SIZE_OF_ARR_2; i++)
    matrix2[i] = malloc(sizeof(**matrix2) * 2);
  for (i = 0; i < SIZE_OF_ARR_1; i++)
    arr6[i] = matrix1[i][0] = matrix1[SIZE_OF_ARR_1 - 1 - i][1] = (double)arr1[i];
  for (i = 0; i < SIZE_OF_ARR_2; i++)
    arr7[i] = matrix2[i][0] = matrix2[SIZE_OF_ARR_2 - 1 - i][1] = (double)arr2[i];

  status = test(1, arrayCmp(arr1, arr3, SIZE_OF_ARR_1));
  if (status != 0)
    goto cleanup;
  status = test(2, arrayCmp(arr2, arr4, SIZE_OF_ARR_2));
  if (status != 0)
    goto cleanup;
  status = test(3, roundTo(M_PI, 2) == 3.14);
  if (status != 0)
    goto cleanup;
  status = test(4, roundTo(sqrt(2), 2) == 1.41);
  if (status != 0)
    goto cleanup;
  status = test(5, mean(arr6, 8) == 3.75);
  if (status != 0)
    goto cleanup;
  status = test(6, roundTo(mean(arr7, 7), 6) == 13.285714);
  if (status != 0)
    goto cleanup;
  status = test(7, roundTo(geometricMean(arr6, 8), 6) == 3.07143);
  if (status != 0)
    goto cleanup;
  status = test(8, roundTo(geometricMean(arr7, 7), 6) == 4.757802);
  if (status != 0)
    goto cleanup;
  status = test(9, roundTo(harmonicMean(arr6, 8), 6) == 2.704918);
  if (status != 0)
    goto cleanup;
  status = test(10, roundTo(harmonicMean(arr7, 7), 6) == 3.245917);
  if (status != 0)
    goto cleanup;
  status = test(11, roundTo(trimmedMean(arr6, 8, 12), 6) == 2.833333);
  if (status != 0)
    goto cleanup;
  status = test(12, trimmedMean(arr7, 7, 14) == 3.6);
  if (status != 0)
    goto cleanup;
  status = test(13, median(arr6, 8) == 2.5);
  if (status != 0)
    goto cleanup;
  status = test(14, median(arr7, 7) == 3);
  if (status != 0)
    goto cleanup;
  arr5 = mode(arr6, 8, &nOfModes);
  status = test(15, arr5[0] == 2 && nOfModes == 1);
  if (status != 0)
    goto cleanup;
  free(arr5);
  arr5 = mode(arr7, 7, &nOfModes);
  status = test(16, arr5[0] == 3 && nOfModes == 1);
  if (status != 0)
    goto cleanup;
  status = test(17, min(arr6, 8) == 2);
  if (status != 0)
    goto cleanup;
  status = test(18, min(arr7, 7) == 2);
  if (status != 0)
    goto cleanup;
  status = test(19, max(arr6, 8) == 11);
  if (status != 0)
    goto cleanup;
  status = test(20, max(arr7, 7) == 73);
  if (status != 0)
    goto cleanup;
  status = test(21, range(arr6, 8) == 9);
  if (status != 0)
    goto cleanup;
  status = test(22, range(arr7, 7) == 71);
  if (status != 0)
    goto cleanup;
  status = test(23, midrange(arr6, 8) == 4.5);
  if (status != 0)
    goto cleanup;
  status = test(24, midrange(arr7, 7) == 35.5);
  if (status != 0)
    goto cleanup;
  status = test(25, roundTo(variance(arr6, 8), 6) == 8.4375);
  if (status != 0)
    goto cleanup;
  status = test(26, roundTo(variance(arr7, 7), 6) == 596.775510);
  if (status != 0)
    goto cleanup;
  status = test(27, roundTo(sampleVariance(arr6, 8), 6) == 9.642857);
  if (status != 0)
    goto cleanup;
  status = test(28, roundTo(sampleVariance(arr7, 7), 6) == 696.238095);
  if (status != 0)
    goto cleanup;
  status = test(29, roundTo(standardDeviation(arr6, 8), 6) == 2.904738);
  if (status != 0)
    goto cleanup;
  status = test(30, roundTo(standardDeviation(arr7, 7), 6) == 24.428989);
  if (status != 0)
    goto cleanup;
  status = test(31, roundTo(sampleStandardDeviation(arr6, 8), 6) == 3.105295);
  if (status != 0)
    goto cleanup;
  status = test(32, roundTo(sampleStandardDeviation(arr7, 7), 6) == 26.386324);
  if (status != 0)
    goto cleanup;
  arr6[3] = 3;
  free(arr5);
  arr5 = mode(arr6, 8, &nOfModes);
  status = test(33, arr5[0] == 2 && arr5[1] == 3 && nOfModes == 2);
  if (status != 0)
    goto cleanup;
  status = test(34, roundTo(weightedMean(matrix1, 8), 6) == 2.933333);
  if (status != 0)
    goto cleanup;
  status = test(35, roundTo(weightedMean(matrix2, 7), 6) == 3.731183);
  if (status != 0)
    goto cleanup;
  status = test(36, arr8[0] == 3 && arr8[1] == -2);
  if (status != 0)
    goto cleanup;
  free(arr8);
  arr8 = equationOfLine(3, 7, 5, 11);
  status = test(37, arr8[0] == 2 && arr8[1] == 1);
  if (status != 0)
    goto cleanup;
  free(arr8);
  arr8 = midpointPoints(1, 1, 2, 4);
  status = test(38, arr8[0] == 1.5 && arr8[1] == 2.5);
  if (status != 0)
    goto cleanup;
  free(arr8);
  arr8 = midpointPoints(3, 7, 5, 11);
  status = test(39, arr8[0] == 4 && arr8[1] == 9);
  if (status != 0)
    goto cleanup;
  status = test(40, isPrime(7919));
  if (status != 0)
    goto cleanup;
  status = test(41, !isPrime(5329));
  if (status != 0)
    goto cleanup;
  status = test(42, isPerfect(6));
  if (status != 0)
    goto cleanup;
  status = test(43, !isPerfect(7));
  if (status != 0)
    goto cleanup;
  status = test(44, isHappy(23));
  if (status != 0)
    goto cleanup;
  status = test(45, !isHappy(73));
  if (status != 0)
    goto cleanup;
  status = test(46, isArmstrong(370));
  if (status != 0)
    goto cleanup;
  status = test(47, !isArmstrong(125));
  if (status != 0)
    goto cleanup;
  status = test(48, nthRoot(4096, 4) == 8);
  if (status != 0)
    goto cleanup;
  status = test(49, round(nthRoot(389017, 3)) == 73);
  if (status != 0)
    goto cleanup;
  status = test(50, logarithm(1024, 4) == 5);
  if (status != 0)
    goto cleanup;
  status = test(51, logarithm(389017, 73) == 3);
  if (status != 0)
    goto cleanup;
  status = test(52, nPercentOfX(725, 5) == 36.25);
  if (status != 0)
    goto cleanup;
  status = test(53, nPercentOfX(1024, 25) == 256);
  if (status != 0)
    goto cleanup;
  status = test(54, nIsWhatPercentOfX(95, 7.6) == 8);
  if (status != 0)
    goto cleanup;
  status = test(55, nIsWhatPercentOfX(128, 16) == 12.5);
  if (status != 0)
    goto cleanup;
  status = test(56, simpleGrowth(5, 0.05, 3) == 5.75);
  if (status != 0)
    goto cleanup;
  status = test(57, simpleGrowth(140, 0.1, 4) == 196);
  if (status != 0)
    goto cleanup;
  status = test(58, roundTo(simpleGrowthRate(5, 5.5, 4), 6) == 0.025);
  if (status != 0)
    goto cleanup;
  status = test(59, roundTo(simpleGrowthRate(145, 153, 3), 6) == 0.018391);
  if (status != 0)
    goto cleanup;
  status = test(60, roundTo(compoundedGrowth(5, 0.2, 3), 6) == 8.64);
  if (status != 0)
    goto cleanup;
  status = test(61, roundTo(compoundedGrowth(2500, 0.17, 13), 6) == 19246.697092);
  if (status != 0)
    goto cleanup;
  status = test(62, roundTo(compoundedGrowthRate(5, 8.64, 3), 6) == 0.2);
  if (status != 0)
    goto cleanup;
  status = test(63, roundTo(compoundedGrowthRate(5200, 7640.50, 5), 6) == 0.08);
  if (status != 0)
    goto cleanup;
  status = test(64, gcd(40, 96) == 8);
  if (status != 0)
    goto cleanup;
  status = test(65, gcd(42, 9) == 3);
  if (status != 0)
    goto cleanup;
  status = test(66, lcm(6, 15) == 30);
  if (status != 0)
    goto cleanup;
  status = test(67, lcm(39, 9) == 117);
  if (status != 0)
    goto cleanup;
  status = test(68, factorial(20) == 2432902008176640000);
  if (status != 0)
    goto cleanup;
  status = test(69, factorial(17) == 355687428096000);
  if (status != 0)
    goto cleanup;
  status = test(70, permutation(6) == 720);
  if (status != 0)
    goto cleanup;
  status = test(71, permutation(8) == 40320);
  if (status != 0)
    goto cleanup;
  status = test(72, cyclePermutation(9) == 40320);
  if (status != 0)
    goto cleanup;
  status = test(73, cyclePermutation(6) == 120);
  if (status != 0)
    goto cleanup;
  status = test(74, arrangement(17, 11) == 494010316800);
  if (status != 0)
    goto cleanup;
  status = test(75, arrangement(9, 6) == 60480);
  if (status != 0)
    goto cleanup;
  status = test(76, combination(19, 15) == 3876);
  if (status != 0)
    goto cleanup;
  status = test(77, combination(9, 5) == 126);
  if (status != 0)
    goto cleanup;
  sprintf(str, "%e", factoriallf(60));
  status = test(78, strcmp(str, "8.320987e+081") == 0 || strcmp(str, "8.320987e+81") == 0);
  if (status != 0)
    goto cleanup;
  sprintf(str, "%e", factoriallf(73));
  status = test(79, strcmp(str, "4.470115e+105") == 0);
  if (status != 0)
    goto cleanup;
  sprintf(str, "%e", permutationlf(40));
  status = test(80, strcmp(str, "8.159153e+047") == 0 || strcmp(str, "8.159153e+47") == 0);
  if (status != 0)
    goto cleanup;
  sprintf(str, "%e", permutationlf(27));
  status = test(81, strcmp(str, "1.088887e+028") == 0 || strcmp(str, "1.088887e+28") == 0);
  if (status != 0)
    goto cleanup;
  sprintf(str, "%e", cyclePermutationlf(36));
  status = test(82, strcmp(str, "1.033315e+040") == 0 || strcmp(str, "1.033315e+40") == 0);
  if (status != 0)
    goto cleanup;
  sprintf(str, "%e", cyclePermutationlf(33));
  status = test(83, strcmp(str, "2.631308e+035") == 0 || strcmp(str, "2.631308e+35") == 0);
  if (status != 0)
    goto cleanup;
  status = test(84, round(arrangementlf(60, 6)) == 36045979200);
  if (status != 0)
    goto cleanup;
  status = test(85, round(arrangementlf(100, 7)) == 80678106432000);
  if (status != 0)
    goto cleanup;
  status = test(86, round(combinationlf(30, 21)) == 14307150);
  if (status != 0)
    goto cleanup;
  status = test(87, round(combinationlf(29, 15)) == 77558760);
  if (status != 0)
    goto cleanup;
  status = test(88, roundTo(binominal(10, 0.2, 6), 6) == 0.005505);
  if (status != 0)
    goto cleanup;
  status = test(89, binominal(4, 0.25, 1) == 0.421875);
  if (status != 0)
    goto cleanup;
  status = test(90, roundTo(poisson(0.45, 4), 5) == 0.00109);
  if (status != 0)
    goto cleanup;
  status = test(91, roundTo(poisson(0.75, 5), 5) == 0.00093);
  if (status != 0)
    goto cleanup;
  status = test(92, roundTo(gaussianCDF(0, 1, 3.5), 5) == 0.99977);
  if (status != 0)
    goto cleanup;
  status = test(93, roundTo(gaussianCDF(150000, 5000, 135000), 5) == 0.00135);
  if (status != 0)
    goto cleanup;
  status = test(94, hypotenuse(3, 4) == 5);
  if (status != 0)
    goto cleanup;
  status = test(95, roundTo(hypotenuse(7, 8), 5) == 10.63015);
  if (status != 0)
    goto cleanup;
  status = test(96, roundTo(sideRightTriangle(4, 2), 6) == 3.464102);
  if (status != 0)
    goto cleanup;
  status = test(97, sideRightTriangle(15, 12) == 9);
  if (status != 0)
    goto cleanup;
  status = test(98, roundTo(sideTriangleLC(4, 3, degrees2radians(60)), 6) == 3.605551);
  if (status != 0)
    goto cleanup;
  status = test(99, roundTo(sideTriangleLC(9, 7, degrees2radians(30)), 5) == 4.56955);
  if (status != 0)
    goto cleanup;
  status = test(100, round(radians2degrees(angleTriangleLC(2, 4, 3.464102))) == 30);
  if (status != 0)
    goto cleanup;
  status = test(101, roundTo(angleTriangleLC(5, 7, 9), 5) == 0.58569);
  if (status != 0)
    goto cleanup;
  status = test(102, roundTo(sideTriangleLS(degrees2radians(60), 4, degrees2radians(45)), 6) == 4.898979);
  if (status != 0)
    goto cleanup;
  status = test(103, roundTo(sideTriangleLS(degrees2radians(45), 8, degrees2radians(30)), 5) == 11.31371);
  if (status != 0)
    goto cleanup;
  status = test(104, round(radians2degrees(angleTriangleLS(4, 4, degrees2radians(45)))) == 45);
  if (status != 0)
    goto cleanup;
  status = test(105, roundTo(angleTriangleLS(10, 8, degrees2radians(30)), 5) == 0.67513);
  if (status != 0)
    goto cleanup;
  status = test(106, triangleArea1(4, 5) == 10);
  if (status != 0)
    goto cleanup;
  status = test(107, triangleArea1(7, 8) == 28);
  if (status != 0)
    goto cleanup;
  status = test(108, roundTo(triangleArea2(2, 4, degrees2radians(60)), 4) == 3.4641);
  if (status != 0)
    goto cleanup;
  status = test(109, roundTo(triangleArea2(8, 7, degrees2radians(54)), 5) == 22.65248);
  if (status != 0)
    goto cleanup;
  status = test(110, triangleArea3(3, 4, 5) == 6);
  if (status != 0)
    goto cleanup;
  status = test(111, roundTo(triangleArea3(10, 8, 5), 5) == 19.81004);
  if (status != 0)
    goto cleanup;
  status = test(112, squareArea(4) == 16);
  if (status != 0)
    goto cleanup;
  status = test(113, squareArea(7) == 49);
  if (status != 0)
    goto cleanup;
  status = test(114, retangleArea(4, 6) == 24);
  if (status != 0)
    goto cleanup;
  status = test(115, retangleArea(3, 7) == 21);
  if (status != 0)
    goto cleanup;
  status = test(116, rhombusArea(5, 6) == 15);
  if (status != 0)
    goto cleanup;
  status = test(117, rhombusArea(7, 8) == 28);
  if (status != 0)
    goto cleanup;
  status = test(118, parallelogramArea1(3, 5) == 15);
  if (status != 0)
    goto cleanup;
  status = test(119, parallelogramArea1(4, 7) == 28);
  if (status != 0)
    goto cleanup;
  status = test(120, roundTo(parallelogramArea2(4, 6, degrees2radians(30)), 6) == 12);
  if (status != 0)
    goto cleanup;
  status = test(121, roundTo(parallelogramArea2(7, 5, degrees2radians(36)), 6) == 20.572484);
  if (status != 0)
    goto cleanup;
  status = test(122, trapezoidArea(7, 5, 3) == 18);
  if (status != 0)
    goto cleanup;
  status = test(123, trapezoidArea(8, 12, 4) == 40);
  if (status != 0)
    goto cleanup;
  status = test(124, roundTo(regularPolygonArea(7, 3), 5) == 21.21762);
  if (status != 0)
    goto cleanup;
  status = test(125, roundTo(regularPolygonArea(5, 6), 4) == 64.9519);
  if (status != 0)
    goto cleanup;
  status = test(126, roundTo(circleArea(4), 6) == 50.265482);
  if (status != 0)
    goto cleanup;
  status = test(127, roundTo(circleArea(8), 6) == 201.06193);
  if (status != 0)
    goto cleanup;
  status = test(128, roundTo(circularSectorArea1(degrees2radians(45), 4), 6) == 6.283185);
  if (status != 0)
    goto cleanup;
  status = test(129, roundTo(circularSectorArea1(degrees2radians(30), 7), 6) == 12.82817);
  if (status != 0)
    goto cleanup;
  status = test(130, circularSectorArea2(6, 4) == 12);
  if (status != 0)
    goto cleanup;
  status = test(131, roundTo(circularSectorArea2(3, 5), 6) == 7.5);
  if (status != 0)
    goto cleanup;
  status = test(132, roundTo(ellipseArea(4, 6), 6) == 75.398224);
  if (status != 0)
    goto cleanup;
  status = test(133, roundTo(ellipseArea(3, 5), 6) == 47.12389);
  if (status != 0)
    goto cleanup;
  status = test(134, cubeArea(4) == 96);
  if (status != 0)
    goto cleanup;
  status = test(135, cubeArea(8) == 384);
  if (status != 0)
    goto cleanup;
  status = test(136, cuboidArea(4, 5, 6) == 148);
  if (status != 0)
    goto cleanup;
  status = test(137, cuboidArea(7, 3, 5) == 142);
  if (status != 0)
    goto cleanup;
  status = test(138, prismArea(16, 16, 5) == 112);
  if (status != 0)
    goto cleanup;
  status = test(139, prismArea(21.21762, 21, 9) == 231.43524);
  if (status != 0)
    goto cleanup;
  status = test(140, regularPrismArea(4, 4, 5) == 112);
  if (status != 0)
    goto cleanup;
  status = test(141, roundTo(regularPrismArea(3, 3, 7), 6) == 70.794229);
  if (status != 0)
    goto cleanup;
  status = test(142, roundTo(pyramidArea(9, 12, 4.2720018), 6) == 34.632011);
  if (status != 0)
    goto cleanup;
  status = test(143, pyramidArea(16, 16, 5) == 56);
  if (status != 0)
    goto cleanup;
  status = test(144, roundTo(regularPyramidArea(3, 4, 4), 6) == 34.632011);
  if (status != 0)
    goto cleanup;
  status = test(145, roundTo(regularPyramidArea(4, 6, 7), 6) == 135.292215);
  if (status != 0)
    goto cleanup;
  status = test(146, roundTo(cylinderArea(2, 5.5), 6) == 94.24778);
  if (status != 0)
    goto cleanup;
  status = test(147, roundTo(cylinderArea(4, 8), 6) == 301.592895);
  if (status != 0)
    goto cleanup;
  status = test(148, roundTo(coneArea(4, 6), 6) == 140.88287);
  if (status != 0)
    goto cleanup;
  status = test(149, roundTo(coneArea(3.5, 7), 6) == 124.53849);
  if (status != 0)
    goto cleanup;
  status = test(150, roundTo(sphereArea(4), 6) == 201.06193);
  if (status != 0)
    goto cleanup;
  status = test(151, roundTo(sphereArea(7), 6) == 615.75216);
  if (status != 0)
    goto cleanup;
  status = test(152, cubeVol(4) == 64);
  if (status != 0)
    goto cleanup;
  status = test(153, cubeVol(8) == 512);
  if (status != 0)
    goto cleanup;
  status = test(154, cuboidVol(4, 5, 6) == 120);
  if (status != 0)
    goto cleanup;
  status = test(155, cuboidVol(7, 3, 5) == 105);
  if (status != 0)
    goto cleanup;
  status = test(156, round(prismVol(16, 5)) == 80);
  if (status != 0)
    goto cleanup;
  status = test(157, round(prismVol(20, 7)) == 140);
  if (status != 0)
    goto cleanup;
  status = test(158, round(regularPrismVol(4, 4, 5)) == 80);
  if (status != 0)
    goto cleanup;
  status = test(159, roundTo(regularPrismVol(3, 3, 7), 6) == 27.2798);
  if (status != 0)
    goto cleanup;
  status = test(160, round(pyramidVol(9, 4)) == 12);
  if (status != 0)
    goto cleanup;
  status = test(161, roundTo(pyramidVol(16, 5), 6) == 26.666667);
  if (status != 0)
    goto cleanup;
  status = test(162, round(regularPyramidVol(3, 4, 4)) == 12);
  if (status != 0)
    goto cleanup;
  status = test(163, round(regularPyramidVol(4, 6, 7)) == 97);
  if (status != 0)
    goto cleanup;
  status = test(164, roundTo(cylinderVol(2, 5.5), 6) == 69.115038);
  if (status != 0)
    goto cleanup;
  status = test(165, roundTo(cylinderVol(4, 8), 6) == 402.12386);
  if (status != 0)
    goto cleanup;
  status = test(166, roundTo(coneVol(4, 6), 6) == 100.530965);
  if (status != 0)
    goto cleanup;
  status = test(167, roundTo(coneVol(3.5, 7), 6) == 89.79719);
  if (status != 0)
    goto cleanup;
  status = test(168, roundTo(sphereVol(4), 6) == 268.082573);
  if (status != 0)
    goto cleanup;
  status = test(169, roundTo(sphereVol(7), 6) == 1436.75504);
  if (status != 0)
    goto cleanup;
  status = test(170, distancePoints(-1, -1, 2, 3) == 5);
  if (status != 0)
    goto cleanup;
  status = test(171, roundTo(distancePoints(1, 2, 7, 11), 6) == 10.816654);
  if (status != 0)
    goto cleanup;
  status = test(172, roundTo(distancePointLine(3, -2, 0, 0), 6) == 0.632456);
  if (status != 0)
    goto cleanup;
  status = test(173, roundTo(distancePointLine(1, -5, 2, 2), 6) == 3.535534);
  if (status != 0)
    goto cleanup;
  status = test(174, slopeOfLine(1, 1, 2, 4) == 3);
  if (status != 0)
    goto cleanup;
  status = test(175, slopeOfLine(-4, 1, 5, 7) == 2.0 / 3);
  if (status != 0)
    goto cleanup;
  status = test(176, roundTo(radians2degrees(angleOfInclineLine(1, 1, 2, 4)), 6) == 71.565051);
  if (status != 0)
    goto cleanup;
  status = test(177, roundTo(radians2degrees(angleOfInclineLine(-4, 1, 5, 7)), 6) == 33.690068);
  if (status != 0)
    goto cleanup;
  status = test(178, roundTo(circlePerimeter(5), 6) == 31.415927);
  if (status != 0)
    goto cleanup;
  status = test(179, roundTo(circlePerimeter(7), 6) == 43.982297);
  if (status != 0)
    goto cleanup;
  status = test(180, nOfDiagnonalsPolygon(6) == 9);
  if (status != 0)
    goto cleanup;
  status = test(181, nOfDiagnonalsPolygon(4) == 2);
  if (status != 0)
    goto cleanup;
  status = test(182, round(radians2degrees(convexPolygonSumInteriorAngles(5))) == 540);
  if (status != 0)
    goto cleanup;
  status = test(183, round(radians2degrees(convexPolygonSumInteriorAngles(6))) == 720);
  if (status != 0)
    goto cleanup;
  status = test(184, round(radians2degrees(regularPolygonInteriorAngle(5))) == 108);
  if (status != 0)
    goto cleanup;
  status = test(185, round(radians2degrees(regularPolygonInteriorAngle(6))) == 120);
  if (status != 0)
    goto cleanup;
  status = test(186, round(radians2degrees(convexPolygonExteriorAngle(5))) == 72);
  if (status != 0)
    goto cleanup;
  status = test(187, round(radians2degrees(convexPolygonExteriorAngle(6))) == 60);
  if (status != 0)
    goto cleanup;
  status = test(188, nOfDiagnonalsPolygon(3) == 0);
  if (status != 0)
    goto cleanup;
  status = test(189, round(radians2degrees(convexPolygonSumInteriorAngles(3))) == 180);
  if (status != 0)
    goto cleanup;
  status = test(190, round(radians2degrees(regularPolygonInteriorAngle(3))) == 60);
  if (status != 0)
    goto cleanup;
  status = test(191, round(radians2degrees(convexPolygonExteriorAngle(3))) == 120);
  if (status != 0)
    goto cleanup;
  status = test(192, arrangement(7, 0) == 1);
  if (status != 0)
    goto cleanup;
  status = test(193, arrangementlf(7, 0) == 1);
  if (status != 0)
    goto cleanup;
  status = test(194, roundTo(sideTriangleLC(5, 7, degrees2radians(179)), 5) == 11.99956);
  if (status != 0)
    goto cleanup;
  status = test(195, roundTo(logarithm(1000, 10), 6) == 3);
  if (status != 0)
    goto cleanup;

  puts("Passed all tests successfully!\n");

cleanup:
  free(arr3);
  free(arr4);
  free(arr5);
  free(arr6);
  free(arr7);
  free(arr8);
  for (i = 0; i < SIZE_OF_ARR_1; i++)
    free(matrix1[i]);
  for (i = 0; i < SIZE_OF_ARR_2; i++)
    free(matrix2[i]);
  free(matrix1);
  free(matrix2);

  return status;
}
