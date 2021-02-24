#include <iostream>
#include <cassert>
#include <vector>

using std::vector;

//Function Declarations
int binary_search(const vector<int> &a, int x);
int linear_search(const vector<int> &a, int x);

int main() {
  int n;
    std::cout << "Enter number of inputs: ";
  std::cin >> n;
  vector<int> a(n);
  
      std::cout << "Enter input numbers (in order): ";
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cout << "Enter number of keys: ";
  std::cin >> m;
  vector<int> b(m);
  
  std::cout << "Enter key numbers: ";
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  
  std::cout << "Linear Search: ";
  for (int i = 0; i < m; ++i) {
    
    std::cout << linear_search(a, b[i]) << ' ';
  }
  
  std::cout << std::endl;
  
  std::cout << "Binary Search: ";
  for (int i = 0; i < m; ++i) {
    
    std::cout << binary_search(a, b[i]) << ' ';
  }
  
  std::cout << std::endl;
}

//Given a sorted array/vector find the key and return its index
// if index does not exist for key return -1
int binary_search(const vector<int> &a, int x) {  
  int left = 0, 
      right = (int)a.size(),
      mid = 0;
      
  while (left < right)
  {
      mid = (left + right) / 2;
  
      if (x == a.at(mid))
      {
         return mid;
      }
      else if (x < a.at(mid))
      {
         right = mid - 1;
      }
      else 
      {
         left = mid + 1;
      }
  }
  
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}
