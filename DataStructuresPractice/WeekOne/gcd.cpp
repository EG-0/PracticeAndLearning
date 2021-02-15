#include <iostream>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int gcd_efficient(int a, int b)
{
   int tempNum = -1; //temporary variable to help with calculation
   //Checking preconditions to ensure caluclations goes as intended
   if (b > a)
   {
      tempNum = a;
      a = b;
      b = tempNum;
   }
   
   //Euclidean Alg., b becomes remainder of a / b, a becomes prev. b
   while (b != 0)
   {
      tempNum = b;
      b = a % b;
      a = tempNum;
   }

   //a is returned when remainder is 0, as it means the gcd is found
   return a;
}

int main() {
  int a, b;
  std::cout << "Enter Two Numbers" << std::endl;
  std::cin >> a >> b;
  std::cout << "Naive Algorithm: ";
  std::cout << gcd_naive(a, b) << std::endl;
  std::cout << "Efficient Algorithm: ";
  std::cout << gcd_efficient(a, b) << std::endl;
  return 0;
}
