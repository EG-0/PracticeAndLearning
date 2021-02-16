#include <iostream>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fasterLastNum(long long int n)
{
   int firstNum = 0;
   int secondNum = 1;
   int digit;
   
   if (n <= 1)
   {
      digit = n;
   }
   else
   {
      for (long long int i = 0; i < n; ++i)
      {
         digit = (firstNum % 10) + (secondNum % 10);
         secondNum = firstNum;
         firstNum = (digit % 10);
      }
   }
   return digit % 10;
}

int fibonacci_sum_efficient(long long n)
{
   return fasterLastNum(n + 2) - 1;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << "Efficient Algorithm: ";
    std::cout << fibonacci_sum_efficient(n) << std::endl;
    std::cout << "Naive Algorithm";
    std::cout << fibonacci_sum_naive(n) << std::endl;
}
