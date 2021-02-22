#include <iostream>

int get_change(int m);

int main() {
  int m;
  std::cout << "Enter an integer amount: ";
  std::cin >> m;
  std::cout << "Minimum number of 10, 5, and 1 coins to represent"
            << " number: ";
  std::cout << get_change(m) << std::endl;
}

int get_change(int m)
{
   int tenCount, //Keep track of number of 10 cent coins
       fiveCount; //Keep track of number of 5 cent coins
    
   //Find number of 10 coins and remainder
   tenCount = m / 10;
   m = m % 10;
   
   //Find number of 5 coins and remainder
   fiveCount = m / 5;
   m = m % 5;
   
   //All thats left 1 coins -> m 
       
  return tenCount + fiveCount + m;
}
