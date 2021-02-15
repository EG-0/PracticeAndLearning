#include <iostream>


long long lcm_naive(int a, int b);
long long int lcm_efficient(int a, int b);
int gcd_efficient(int a, int b);

int main() {
  int a, b;
  
  std::cout << "Enter Two Numbers: ";
  std::cin >> a >> b;
  //Calculate LCM
  std::cout << "Efficient Algorithm ";
  std::cout << lcm_efficient(a, b) << std::endl;
  std::cout << "Naive Algorithm: ";
  std::cout << lcm_naive(a, b) << std::endl;
  
  return 0;
}

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long int lcm_efficient(int a, int b)
{ 
   //One fast algorithm is a * b / gcd
   //Must convert gcd to a long long to avoid mult issues
   return (long long int) ((a / (long long int)(gcd_efficient(a, b))) * b);
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
