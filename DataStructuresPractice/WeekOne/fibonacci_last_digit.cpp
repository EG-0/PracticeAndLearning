#include <iostream>

int get_fibonacci_last_digit_naive(int n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;

    for (int i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % 10;
}
int fasterLastNum(int n)
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
      for (size_t i = 0; i < n; ++i)
      {
         digit = (firstNum % 10) + (secondNum % 10);
         secondNum = firstNum;
         firstNum = (digit % 10);
      }
   }
   
   return digit % 10;
}
//Basic Tester
// Naive algorithm was given, testing on optomized algorithm
bool testSolution ()
{
   bool bothEqual = true;
   
   //Cannot test naive algorithm to high in case of overflow
   for (size_t i = 0; i < 40; ++i)
   {
      if (fasterLastNum(i) != get_fibonacci_last_digit_naive(i))
      {
         bothEqual = false;    
         break;  
      }
   }
   return bothEqual;
}
int main() {
    int n;
    std::cout << "Input an integer: ";
    std::cin >> n;
    std::cout << get_fibonacci_last_digit_naive(n) << '\n';
    std::cout << fasterLastNum(n) << std::endl;
    
    if (testSolution())
      std::cout << "True" << std::endl;
    else
      std::cout << "False" << std::endl; 
    }
