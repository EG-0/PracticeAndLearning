#include <iostream>
#include <vector>

using std::vector;

//Declaring functions
vector<int> optimal_summands(int n);

int main() {
  int n;
  std::cout << "Enter number of candies: ";
  std::cin >> n;
  
  vector<int> summands = optimal_summands(n);
  
  std::cout << "Number of prize winners: ";
  std::cout << summands.size() << '\n';
  std::cout << "Number of candies for prize winners: ";
  
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  
    std::cout << std::endl;
}

vector<int> optimal_summands(int n) 
{
  vector<int> summands;
  int remainder = n;
  
  //This loop uses various i + 1 or i - 1 because first initial 
  //  value is 1
   for (size_t i = 0; i <= n; ++i)
   {
      if ((i + 1) > remainder)
      {
         summands.at(i - 1) = summands.at(i - 1) + remainder;
         break; //Must exit loop; remainder is 0
      }
      else 
      {
         summands.push_back(i + 1);
         remainder = remainder - (i + 1);
      }
   }

  return summands;
}
