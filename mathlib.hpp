static inline int math_gcd(int x, int y)
{
  int result, remainder;
  if (x == 0)
    return abs(y);
  if (y == 0)
    return abs(x);
  remainder = x % y;
  while (remainder)
  {
    x = y;
    y = remainder;
    remainder = x % y;
  }
  result = abs(y);
  return result;
}

static inline double math_simpleGrowth(double initial, double rate, double interval)
{
  if (interval < 0)
    return NAN;
  double result;
  result = initial * (1 + rate * interval);
  return result;
}



static inline double math_simpleGrowthRate(double initial, double final, double interval)
{
  if (initial == 0 || interval <= 0)
    return NAN;
  double result;
  result = (final / initial - 1) / interval;
  return result;
}



static inline double math_compoundedGrowth(double initial, double rate, double interval)
{
  if (interval < 0)
    return NAN;
  double result;
  result = initial * pow((1 + rate), interval);
  return result;
}



static inline double math_compoundedGrowthRate(double initial, double final, double interval)
{
  if (initial == 0 || interval <= 0)
    return NAN;
  double result;
  result = math_nthRoot((final / initial), interval) - 1;
  return result;
}


static inline bool math_isHappy(long long num)
{
  long long sum,
      *numSet = (long long *)malloc(sizeof(*numSet));
  int i, lenNumSet, remainder;
  numSet[0] = num;
  lenNumSet = 1;
  while (true)
  {
    sum = 0;
    while (num > 0)
    {
      remainder = num % 10;
      num /= 10;
      sum += remainder * remainder;
    }
    if (sum == 1)
    {
      free(numSet);
      return true;
    }
    for (i = 0; i < lenNumSet; i++)
      if (numSet[i] == sum)
      {
        free(numSet);
        return false;
      }
    numSet = (long long *)realloc(numSet, sizeof(*numSet) * ++lenNumSet);
    numSet[lenNumSet - 1] = sum;
    num = sum;
  }
}

static inline long long math_lcm(int x, int y)
{
  if (x == 0 || y == 0)
    return 0;
  long long product = (long long) x * (long long) y;
  long long result = llabs(product / math_gcd(x, y));
  return result;
}

