#include <iostream>

long long int fibonacci_fast(long long int n) {
   long long int firstNum = 0; //Base case = 0
   long long int secondNum = 1; //Base case = 1
   long long int sum = 0;
   
   //Gives proper sum if n is one of the base cases
   if (n <= 1)
   {
      sum = n;
   }
   //Returns sum if not a proper base case
   else
   {
      sum = 1;
      for (size_t i = 0; i < n; ++i)
      {
         sum = firstNum + secondNum;
         secondNum = firstNum;
         firstNum = sum;
      }
   }
   return sum;
}

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}


long long int fib_efficient(long long int n, long long int m)
{
   if (m == 1)
      return 0;
      
   long long int firstNum = 1;
   long long int secondNum = 1;
   long long int digit;
   long long int last = 1; //Starting last at 1 because 3rd FibNumber is 1
   long long int length = 2; //Start off at 0 -> 0, 1 auto added to length
   
   
   //Find Pisano Sequence Length of Divisor
   for (long long int i = 2; i < n; ++i)
   {
      digit = (firstNum % m) + (secondNum % m);
      secondNum = firstNum;
      firstNum = (digit % m);
      
      if (digit % m == 1)
      {
         if (last == 0)
         {
            length += i - 2; //Important to subtract 2 from this
            break;
         }
      }
      
      last = digit % m;      
   }

   //If length is 2, n was not long enough to find sequence of m
   if (length == 2)
   {
      digit %= m;
   }
   else 
   {
      digit = n % length;
      digit = fibonacci_fast(digit) % m;
   }
 
   return digit;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << "Efficient Algorithm: ";
    std::cout << fib_efficient(n, m) << std::endl;
    std::cout << "Naive Algorithm: ";
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';
}
