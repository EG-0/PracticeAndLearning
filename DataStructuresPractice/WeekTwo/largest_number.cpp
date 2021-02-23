#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

string largest_number(vector<string> a);
bool is_greater_or_equal(string numOne, string numTwo);

int main() {
  int n;
  
  std::cout << "Enter number of numbers: ";
  std::cin >> n;
  
  vector<string> a(n);
  
  for (size_t i = 0; i < a.size(); i++) 
  {
    std::cout << "Enter numbers: ";
    std::cin >> a[i];
  }
  
  std::cout << "Largest possible number: ";
  std::cout << largest_number(a);
  std::cout << std::endl;
}

string largest_number(vector<string> a) 
{
   string result = "";
   size_t element;
   
   while (a.size() > 0)
   {
      string maxDigit = "-1";
      
      for (size_t i = 0; i < a.size(); ++i)
      {
         if (is_greater_or_equal(a.at(i), maxDigit))
         {
            maxDigit = a.at(i);
            element = i;
         }     
      }
       result += maxDigit;
       a.erase(a.begin() + element);
   }
  
  return result;
}

//Determines how to get largest number from given string ints
bool is_greater_or_equal(string numOne, string numTwo)
{   
   string orderOne = numOne + numTwo;
   string orderTwo = numTwo + numOne;
   
   return (stoi(orderOne) > stoi(orderTwo));
}
