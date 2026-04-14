#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif /* M_PI */

#ifndef PROBABILITY_DISTRIBUTION_H
#define PROBABILITY_DISTRIBUTION_H

#include "combinatorics.h"

/**
 * @brief Calculate the binomial probability mass function (PMF).
 *
 * @param trials The number of trials.
 * @param success_prob The success probability.
 * @param success The number of successful outcomes.
 *
 * @return The probability of exactly `success` successes in `trials` Bernoulli trials.
 */

static inline double math_binominal(int trials, double success_prob, int success)
{
  if (trials < 0 || success < 0 || success > trials ||
      success_prob < 0 || success_prob > 1)
    return NAN;
  double result = math_combinationlf(trials, success) *
                  pow(success_prob, success) *
                  pow((1 - success_prob), (trials - success));
  return result;
}

/**
 * @brief Calculate the Poisson probability.
 *
 * @param lambda The mean value.
 * @param x The number of occurrences.
 *
 * @return The Poisson probability.
 */

static inline double math_poisson(double lambda, int x)
{
  if (lambda < 0 || x < 0)
    return NAN;
  double result = exp(-lambda) * pow(lambda, x) / math_factoriallf(x);
  return result;
}

/**
 * @brief Calculate the cumulative distribution function (CDF) of a Gaussian distribution.
 *
 * @param mu The mean value of the Gaussian distribution.
 * @param std_dev The standard deviation of the Gaussian distribution.
 * @param x The input value.
 *
 * @return The cumulative distribution function (CDF) value.
 */

static inline double math_gaussian_CDF(double mu, double std_dev, double x)
{
  if (std_dev < 0)
    return NAN;
  if (std_dev == 0)
    return (x < mu) ? 0.0 : 1.0;
  double phi, result, z,
      denominator = 1,
      sum = 0;
  int i;
  z = (x - mu) / std_dev;
  phi = exp(-pow(z, 2) / 2) / sqrt(2 * M_PI);
  for (i = 1; i <= 100; i += 2)
  {
    denominator *= i;
    sum += pow(z, i) / denominator;
  }
  result = 0.5 + phi * sum;
  return result;
}

#endif /* PROBABILITY_DISTRIBUTION_H */
