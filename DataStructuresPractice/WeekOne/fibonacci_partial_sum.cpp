#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
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
   //std::cout << "Digit: " << (digit % 10) - 1<< std::endl;
   return digit % 10;
}

int fibonacci_sum_efficient(long long n)
{
   return fasterLastNum(n + 2) - 1;
}

long long get_fib_partial_sum_fast(long long from, long long to)
{
   long long int sum = fibonacci_sum_efficient(to);
   if (to != from)
      sum -= fasterLastNum(from);
   return sum;
}

int main() {
    long long from, to;
    std::cout << "Input numbers from \" \" to \" \": ";
    std::cin >> from >> to;
    std::cout << "Efficient Algorithm: ";
    std::cout << get_fib_partial_sum_fast(from, to) << std::endl;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
}
