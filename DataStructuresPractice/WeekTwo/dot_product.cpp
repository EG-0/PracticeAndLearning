#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

long long max_dot_product(vector<int> a, vector<int> b);
void bubble_sort(vector<int>& a);

int main() {
  size_t n;
  std::cout << "Enter number of slots";
  std::cin >> n;
  vector<int> a(n), b(n);
  
  std::cout << "Enter expected profit per click per slot: ";
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  
  std::cout << "Enter expected number of clicks per day: ";
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  
  std::cout << "Maximized Revenue: ";
  std::cout << max_dot_product(a, b) << std::endl;
}

long long max_dot_product(vector<int> a, vector<int> b) {
  //Sort A and B
  bubble_sort(a);
  bubble_sort(b);
  
  long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }
  return result;
}

//Basic Sort function; sorts through vector in reverse order
void bubble_sort(vector<int>& a)
{
   bool swap; //Used to tell if sorted
   int temp; //Temporary variable
   
   do 
   {  
      swap = false; //Must reset to avoid infinite loop
      for (int i = a.size() - 1; i > 0; --i)
      {
         if (a.at(i) > a.at(i - 1))
         {
            temp = a.at(i - 1);
            a.at(i - 1) = a.at(i);
            a.at(i) = temp;
            swap = true;
         }
      }
   } while (swap);
}
