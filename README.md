# Mathematical Algorithms

This project consists of a small mathematical library developed in C, with support for C++. It provides a set of functions for basic calculations and some more advanced operations, including simple geometry and statistical routines. The goal is to offer a lightweight and practical solution for performing common mathematical tasks efficiently.

## Features

The project includes implementations of the following mathematical algorithms:

| File                                                                    | Features                                                                                                                                                                                                                                                                                                                                                                                                                                      |
| ----------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| [area_shape.h](./include/math/area_shape.h)                             | Area calculations for shapes such as triangles, squares, rectangles, diamonds, parallelograms, trapezoids, regular pentagons, circles, circular sectors, and ellipses                                                                                                                                                                                                                                                                         |
| [area_surface.h](./include/math/area_surface.h)                         | Surface area calculations for objects such as cubes, cuboids, prisms, regular prisms, pyramids, regular pyramids, cylinders, cones, and spheres                                                                                                                                                                                                                                                                                               |
| [armstrong_numbers.h](./include/math/armstrong_numbers.h)               | Armstrong number determination                                                                                                                                                                                                                                                                                                                                                                                                                |
| [basic_operations.h](./include/math/basic_operations.h)                 | Basic operations, including rounding to a specified number of decimal places, nth root calculation, and logarithm calculation in a given base                                                                                                                                                                                                                                                                                                 |
| [combinatorics.h](./include/math/combinatorics.h)                       | Combinatorial analysis, including permutation, circular permutation, arrangement, and combination                                                                                                                                                                                                                                                                                                                                             |
| [factorial.h](./include/math/factorial.h)                               | Factorial calculation                                                                                                                                                                                                                                                                                                                                                                                                                         |
| [gcd.h](./include/math/gcd.h)                                           | Greatest common divisor calculation                                                                                                                                                                                                                                                                                                                                                                                                           |
| [geometry.h](./include/math/geometry.h)                                 | Geometry-related functions, such as conversion between degrees and radians, distance between two points, midpoint between two points, slope of a line, angle of incline of a line, equation of a line, distance between a point and a line, circle perimeter calculation, number of diagonals in a polygon, sum of internal angles of a convex polygon, each internal angle of a regular polygon, and each external angle of a convex polygon |
| [growth.h](./include/math/growth.h)                                     | Growth calculations, including value after simple growth, rate of simple growth, value after compound growth, and rate of compound growth                                                                                                                                                                                                                                                                                                     |
| [happy_numbers.h](./include/math/happy_numbers.h)                       | Happy numbers determination                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [lcm.h](./include/math/lcm.h)                                           | Least common multiple calculation                                                                                                                                                                                                                                                                                                                                                                                                             |
| [percentage.h](./include/math/percentage.h)                             | Percentage calculations, such as finding x percent of a number and determining what percentage one number represents of another                                                                                                                                                                                                                                                                                                               |
| [perfect_numbers.h](./include/math/perfect_numbers.h)                   | Perfect numbers determination                                                                                                                                                                                                                                                                                                                                                                                                                 |
| [prime_factorization.h](./include/math/prime_factorization.h)           | Prime factorization of numbers                                                                                                                                                                                                                                                                                                                                                                                                                |
| [prime_numbers.h](./include/math/prime_numbers.h)                       | Prime numbers determination                                                                                                                                                                                                                                                                                                                                                                                                                   |
| [probability_distribution.h](./include/math/probability_distribution.h) | Probability distributions, including binomial, Poisson, and Gaussian distributions                                                                                                                                                                                                                                                                                                                                                            |
| [statistics.h](./include/math/statistics.h)                             | Statistical analysis functions, such as mean, trimmed mean, geometric mean, harmonic mean, median, mode, maximum value, minimum value, range, midrange, variance, standard deviation, sample variance, and sample standard deviation                                                                                                                                                                                                          |
| [trigonometry.h](./include/math/trigonometry.h)                         | Trigonometry functions, including calculation of the hypotenuse of a right triangle, calculation of a side of a right triangle, side calculation using the law of cosines, angle calculation using the law of cosines, side calculation using the law of sines, angle calculation using the law of sines                                                                                                                                      |
| [volume.h](./include/math/volume.h)                                     | Volume calculations for objects such as cubes, cuboids, prisms, regular prisms, pyramids, regular pyramids, cylinders, cones, and spheres                                                                                                                                                                                                                                                                                                     |

The project aims to provide a comprehensive and efficient set of mathematical functions to assist in various calculations and analyses.

## Getting Started

To compile and run the test file, follow these steps:

1. **Clone the repository:**

```sh
git clone https://github.com/amartinsmg/MathAlgorithms.git
```

2. **Change to the project directory:**

```sh
cd MathAlgorithms
```

3. **Build and run the tests:**
   The following command uses the Makefile to compile the code and automatically execute the test suite:

```sh
make test
```

## Usage

The test program provided allows you to evaluate the correctness of the implemented mathematical algorithms. It calls each function and compares the results with pre-calculated values to validate the accuracy of the algorithms. By running the test program, you can ensure that the functions are functioning correctly and producing expected results.

## Contributing

Contributions are welcome! If you find a bug or have a suggestion for an improvement, please open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](./LICENSE) file for details.
