#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <mathlib.hpp>

void test(int code, bool condition)
{
  std::cout << "Test #" << code << ": ";
  if (condition)
    std::cout << "Passed!\n";
  else
  {
    std::cout << "Failed!\n\n";
    throw std::invalid_argument("Condition is false!");
  }
}

int main(void)
{
  char str[100];
  size_t i;
  int status = EXIT_FAILURE;
  Point out,
      a = {1, 1},
      b = {2, 4},
      c = {3, 7},
      d = {5, 11},
      e = {-1, -1},
      f = {2, 3},
      g = {1, 2},
      h = {7, 11},
      j = {-4, 1},
      k = {5, 7},
      p = {0};
  std::vector<double> vecLf1 = {2, 2, 2, 2, 3, 3, 5, 11},
                      vecLf2 = {2, 2, 3, 3, 3, 7, 73};

  try
  {
    test(1, Math::primeFactors(7920) == std::vector<long long>{2, 2, 2, 2, 3, 3, 5, 11});
    test(2, Math::primeFactors(55188) == std::vector<long long>{2, 2, 3, 3, 3, 7, 73});
    test(3, Math::roundTo(M_PI, 2) == 3.14);
    test(4, Math::roundTo(sqrt(2), 2) == 1.41);
    test(5, Math::mean(vecLf1) == 3.75);
    test(6, Math::roundTo(Math::mean(vecLf2), 6) == 13.285714);
    test(7, Math::roundTo(Math::geometricMean(vecLf1), 6) == 3.07143);
    test(8, Math::roundTo(Math::geometricMean(vecLf2), 6) == 4.757802);
    test(9, Math::roundTo(Math::harmonicMean(vecLf1), 6) == 2.704918);
    test(10, Math::roundTo(Math::harmonicMean(vecLf2), 6) == 3.245917);
    test(11, Math::roundTo(Math::trimmedMean(vecLf1, 12), 6) == 2.833333);
    test(12, Math::trimmedMean(vecLf2, 14) == 3.6);
    test(13, Math::median(vecLf1) == 2.5);
    test(14, Math::median(vecLf2) == 3);
    test(15, Math::mode(vecLf1) == std::vector<double>{2});
    test(16, Math::mode(vecLf2) == std::vector<double>{3});
    test(17, Math::min(vecLf1) == 2);
    test(18, Math::min(vecLf2) == 2);
    test(19, Math::max(vecLf1) == 11);
    test(20, Math::max(vecLf2) == 73);
    test(21, Math::range(vecLf1) == 9);
    test(22, Math::range(vecLf2) == 71);
    test(23, Math::midrange(vecLf1) == 4.5);
    test(24, Math::midrange(vecLf2) == 35.5);
    test(25, Math::roundTo(Math::variance(vecLf1), 6) == 8.4375);
    test(26, Math::roundTo(Math::variance(vecLf2), 6) == 596.775510);
    test(27, Math::roundTo(Math::sampleVariance(vecLf1), 6) == 9.642857);
    test(28, Math::roundTo(Math::sampleVariance(vecLf2), 6) == 696.238095);
    test(29, Math::roundTo(Math::stdDev(vecLf1), 6) == 2.904738);
    test(30, Math::roundTo(Math::stdDev(vecLf2), 6) == 24.428989);
    test(31, Math::roundTo(Math::sampleStdDev(vecLf1), 6) == 3.105295);
    test(32, Math::roundTo(Math::sampleStdDev(vecLf2), 6) == 26.386324);
    vecLf1[3] = 3;
    test(33, Math::mode(vecLf1) == std::vector<double>{2, 3}); // This was test 33, so the next one should be 34
    test(34, Math::lineYIntercept(a, b) == -2);
    test(35, Math::lineYIntercept(c, d) == 1);
    out = Math::midpointPoints(a, b);
    test(36, out.x == 1.5 && out.y == 2.5);
    out = Math::midpointPoints(c, d);
    test(37, out.x == 4 && out.y == 9);
    test(38, Math::isPrime(7919));
    test(39, !Math::isPrime(5329));
    test(40, Math::isPerfect(6));
    test(41, !Math::isPerfect(7));
    test(42, Math::isHappy(23));
    test(43, !Math::isHappy(73));
    test(44, Math::isArmstrong(370));
    test(45, !Math::isArmstrong(125));
    test(46, Math::nthRoot(4096, 4) == 8);
    test(47, round(Math::nthRoot(389017, 3)) == 73);
    test(48, Math::logarithm(1024, 4) == 5);
    test(49, Math::logarithm(389017, 73) == 3);
    test(50, Math::nPercentOfX(725, 5) == 36.25);
    test(51, Math::nPercentOfX(1024, 25) == 256);
    test(52, Math::nIsWhatPercentOfX(95, 7.6) == 8);
    test(53, Math::nIsWhatPercentOfX(128, 16) == 12.5);
    test(54, Math::simpGrowth(5, 0.05, 3) == 5.75);
    test(55, Math::simpGrowth(140, 0.1, 4) == 196);
    test(56, Math::roundTo(Math::simpGrowthRate(5, 5.5, 4), 6) == 0.025);
    test(57, Math::roundTo(Math::simpGrowthRate(145, 153, 3), 6) == 0.018391);
    test(58, Math::roundTo(Math::compGrowth(5, 0.2, 3), 6) == 8.64);
    test(59, Math::roundTo(Math::compGrowth(2500, 0.17, 13), 6) == 19246.697092);
    test(60, Math::roundTo(Math::compGrowthRate(5, 8.64, 3), 6) == 0.2);
    test(61, Math::roundTo(Math::compGrowthRate(5200, 7640.50, 5), 6) == 0.08);
    test(62, Math::gcd(40, 96) == 8);
    test(63, Math::gcd(42, 9) == 3);
    test(64, Math::lcm(6, 15) == 30);
    test(65, Math::lcm(39, 9) == 117);
    test(66, Math::factorial(20) == 2432902008176640000);
    test(67, Math::factorial(17) == 355687428096000);
    test(68, Math::permutation(6) == 720);
    test(69, Math::permutation(8) == 40320);
    test(70, Math::cyclePermutation(9) == 40320);
    test(71, Math::cyclePermutation(6) == 120);
    test(72, Math::arrangement(17, 11) == 494010316800);
    test(73, Math::arrangement(9, 6) == 60480);
    test(74, Math::combination(19, 15) == 3876);
    test(75, Math::combination(9, 5) == 126);
    sprintf(str, "%e", Math::factoriallf(60));
    test(76, strcmp(str, "8.320987e+081") == 0 || strcmp(str, "8.320987e+81") == 0);
    sprintf(str, "%e", Math::factoriallf(73));
    test(77, strcmp(str, "4.470115e+105") == 0);
    sprintf(str, "%e", Math::permutationlf(40));
    test(78, strcmp(str, "8.159153e+047") == 0 || strcmp(str, "8.159153e+47") == 0);
    sprintf(str, "%e", Math::permutationlf(27));
    test(79, strcmp(str, "1.088887e+028") == 0 || strcmp(str, "1.088887e+28") == 0);
    sprintf(str, "%e", Math::cyclePermutationlf(36));
    test(80, strcmp(str, "1.033315e+040") == 0 || strcmp(str, "1.033315e+40") == 0);
    sprintf(str, "%e", Math::cyclePermutationlf(33));
    test(81, strcmp(str, "2.631308e+035") == 0 || strcmp(str, "2.631308e+35") == 0);
    test(82, round(Math::arrangementlf(60, 6)) == 36045979200);
    test(83, round(Math::arrangementlf(100, 7)) == 80678106432000);
    test(84, round(Math::combinationlf(30, 21)) == 14307150);
    test(85, round(Math::combinationlf(29, 15)) == 77558760);
    test(86, Math::roundTo(Math::binominal(10, 0.2, 6), 6) == 0.005505);
    test(87, Math::binominal(4, 0.25, 1) == 0.421875);
    test(88, Math::roundTo(Math::poisson(0.45, 4), 5) == 0.00109);
    test(89, Math::roundTo(Math::poisson(0.75, 5), 5) == 0.00093);
    test(90, Math::roundTo(Math::gaussianCDF(0, 1, 3.5), 5) == 0.99977);
    test(91, Math::roundTo(Math::gaussianCDF(150000, 5000, 135000), 5) == 0.00135);
    test(92, Math::hypotenuse(3, 4) == 5);
    test(93, Math::roundTo(Math::hypotenuse(7, 8), 5) == 10.63015);
    test(94, Math::roundTo(Math::sideRTriangle(4, 2), 6) == 3.464102);
    test(95, Math::sideRTriangle(15, 12) == 9);
    test(96, Math::roundTo(Math::sideTriangleLC(4, 3, Math::deg2rad(60)), 6) == 3.605551);
    test(97, Math::roundTo(Math::sideTriangleLC(9, 7, Math::deg2rad(30)), 5) == 4.56955);
    test(98, round(Math::rad2deg(Math::angTriangleLC(2, 4, 3.464102))) == 30);
    test(99, Math::roundTo(Math::angTriangleLC(5, 7, 9), 5) == 0.58569);
    test(100, Math::roundTo(Math::sideTriangleLS(Math::deg2rad(60), 4, Math::deg2rad(45)), 6) == 4.898979);
    test(101, Math::roundTo(Math::sideTriangleLS(Math::deg2rad(45), 8, Math::deg2rad(30)), 5) == 11.31371);
    test(102, round(Math::rad2deg(Math::angTriangleLS(4, 4, Math::deg2rad(45)))) == 45);
    test(103, Math::roundTo(Math::angTriangleLS(10, 8, Math::deg2rad(30)), 5) == 0.67513);
    test(104, Math::triangleArea1(4, 5) == 10);
    test(105, Math::triangleArea1(7, 8) == 28);
    test(106, Math::roundTo(Math::triangleArea2(2, 4, Math::deg2rad(60)), 4) == 3.4641);
    test(107, Math::roundTo(Math::triangleArea2(8, 7, Math::deg2rad(54)), 5) == 22.65248);
    test(108, Math::triangleArea3(3, 4, 5) == 6);
    test(109, Math::roundTo(Math::triangleArea3(10, 8, 5), 5) == 19.81004);
    test(110, Math::squareArea(4) == 16);
    test(111, Math::squareArea(7) == 49);
    test(112, Math::rectangleArea(4, 6) == 24);
    test(113, Math::rectangleArea(3, 7) == 21);
    test(114, Math::rhombusArea(5, 6) == 15);
    test(115, Math::rhombusArea(7, 8) == 28);
    test(116, Math::parallelogramArea1(3, 5) == 15);
    test(117, Math::parallelogramArea1(4, 7) == 28);
    test(118, Math::roundTo(Math::parallelogramArea2(4, 6, Math::deg2rad(30)), 6) == 12);
    test(119, Math::roundTo(Math::parallelogramArea2(7, 5, Math::deg2rad(36)), 6) == 20.572484);
    test(120, Math::trapezoidArea(7, 5, 3) == 18);
    test(121, Math::trapezoidArea(8, 12, 4) == 40);
    test(122, Math::roundTo(Math::regPolygonArea(7, 3), 5) == 21.21762);
    test(123, Math::roundTo(Math::regPolygonArea(5, 6), 4) == 64.9519);
    test(124, Math::roundTo(Math::circleArea(4), 6) == 50.265482);
    test(125, Math::roundTo(Math::circleArea(8), 6) == 201.06193);
    test(126, Math::roundTo(Math::circularSectorArea1(Math::deg2rad(45), 4), 6) == 6.283185);
    test(127, Math::roundTo(Math::circularSectorArea1(Math::deg2rad(30), 7), 6) == 12.82817);
    test(128, Math::circularSectorArea2(6, 4) == 12);
    test(129, Math::roundTo(Math::circularSectorArea2(3, 5), 6) == 7.5);
    test(130, Math::roundTo(Math::ellipseArea(4, 6), 6) == 75.398224);
    test(131, Math::roundTo(Math::ellipseArea(3, 5), 6) == 47.12389);
    test(132, Math::cubeArea(4) == 96);
    test(133, Math::cubeArea(8) == 384);
    test(134, Math::cuboidArea(4, 5, 6) == 148);
    test(135, Math::cuboidArea(7, 3, 5) == 142);
    test(136, Math::prismArea(16, 16, 5) == 112);
    test(137, Math::prismArea(21.21762, 21, 9) == 231.43524);
    test(138, Math::regularPrismArea(4, 4, 5) == 112);
    test(139, Math::roundTo(Math::regularPrismArea(3, 3, 7), 6) == 70.794229);
    test(140, Math::roundTo(Math::pyramidArea(9, 12, 4.2720018), 6) == 34.632011);
    test(141, Math::pyramidArea(16, 16, 5) == 56);
    test(142, Math::roundTo(Math::regPyramidArea(3, 4, 4), 6) == 34.632011);
    test(143, Math::roundTo(Math::regPyramidArea(4, 6, 7), 6) == 135.292215);
    test(144, Math::roundTo(Math::cylinderArea(2, 5.5), 6) == 94.24778);
    test(145, Math::roundTo(Math::cylinderArea(4, 8), 6) == 301.592895);
    test(146, Math::roundTo(Math::coneArea(4, 6), 6) == 140.88287);
    test(147, Math::roundTo(Math::coneArea(3.5, 7), 6) == 124.53849);
    test(148, Math::roundTo(Math::sphereArea(4), 6) == 201.06193);
    test(149, Math::roundTo(Math::sphereArea(7), 6) == 615.75216);
    test(150, Math::cubeVol(4) == 64);
    test(151, Math::cubeVol(8) == 512);
    test(152, Math::cuboidVol(4, 5, 6) == 120);
    test(153, Math::cuboidVol(7, 3, 5) == 105);
    test(154, round(Math::prismVol(16, 5)) == 80);
    test(155, round(Math::prismVol(20, 7)) == 140);
    test(156, round(Math::regularPrismVol(4, 4, 5)) == 80);
    test(157, Math::roundTo(Math::regularPrismVol(3, 3, 7), 6) == 27.2798);
    test(158, round(Math::pyramidVol(9, 4)) == 12);
    test(159, Math::roundTo(Math::pyramidVol(16, 5), 6) == 26.666667);
    test(160, round(Math::regPyramidVol(3, 4, 4)) == 12);
    test(161, round(Math::regPyramidVol(4, 6, 7)) == 97);
    test(162, Math::roundTo(Math::cylinderVol(2, 5.5), 6) == 69.115038);
    test(163, Math::roundTo(Math::cylinderVol(4, 8), 6) == 402.12386);
    test(164, Math::roundTo(Math::coneVol(4, 6), 6) == 100.530965);
    test(165, Math::roundTo(Math::coneVol(3.5, 7), 6) == 89.79719);
    test(166, Math::roundTo(Math::sphereVol(4), 6) == 268.082573);
    test(167, Math::roundTo(Math::sphereVol(7), 6) == 1436.75504);
    test(168, Math::distancePoints(e, f) == 5);
    test(169, Math::roundTo(Math::distancePoints(g, h), 6) == 10.816654);
    test(170, Math::roundTo(Math::distancePointLine(3, -2, p), 6) == 0.632456);
    p.x = p.y = 2;
    test(171, Math::roundTo(Math::distancePointLine(1, -5, p), 6) == 3.535534);
    test(172, Math::slopeLine(a, b) == 3);
    test(173, Math::slopeLine(j, k) == 2.0 / 3);
    test(174, Math::roundTo(Math::rad2deg(Math::inclinationLine(a, b)), 6) == 71.565051);
    test(175, Math::roundTo(Math::rad2deg(Math::inclinationLine(j, k)), 6) == 33.690068);
    test(176, Math::roundTo(Math::circlePerimeter(5), 6) == 31.415927);
    test(177, Math::roundTo(Math::circlePerimeter(7), 6) == 43.982297);
    test(178, Math::polygonDiagonals(6) == 9);
    test(179, Math::polygonDiagonals(4) == 2);
    test(180, round(Math::rad2deg(Math::convexPolySumIntAng(5))) == 540);
    test(181, round(Math::rad2deg(Math::convexPolySumIntAng(6))) == 720);
    test(182, round(Math::rad2deg(Math::regPolygonIAng(5))) == 108);
    test(183, round(Math::rad2deg(Math::regPolygonIAng(6))) == 120);
    test(184, round(Math::rad2deg(Math::convexPolyExtAngle(5))) == 72);
    test(185, round(Math::rad2deg(Math::convexPolyExtAngle(6))) == 60);
    test(186, Math::polygonDiagonals(3) == 0);
    test(187, round(Math::rad2deg(Math::convexPolySumIntAng(3))) == 180);
    test(188, round(Math::rad2deg(Math::regPolygonIAng(3))) == 60);
    test(189, round(Math::rad2deg(Math::convexPolyExtAngle(3))) == 120);
    test(190, Math::arrangement(7, 0) == 1);
    test(191, Math::arrangementlf(7, 0) == 1);
    test(192, Math::roundTo(Math::sideTriangleLC(5, 7, Math::deg2rad(179)), 5) == 11.99956);
    test(193, Math::roundTo(Math::logarithm(1000, 10), 6) == 3);

    std::cout << "Passed all tests successfully!\n";

    status = EXIT_SUCCESS;
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }

  return status;
}
