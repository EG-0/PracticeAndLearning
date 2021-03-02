#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;

int partition2(vector<int> &a, int l, int r);
int partiton3(vector<int>& a, int l, int r);
void randomized_quick_sort(vector<int> &a, int l, int r);

int main() {
  int n;
  std::cout << "Enter number of integers to enter: " << std::endl;
  std::cin >> n;
  vector<int> a(n);
  
  std::cout << "Enter integers with no spaces: ";
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  
  randomized_quick_sort(a, 0, a.size() - 1);
  
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
  std::cout << std::endl;
}

int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}
/*
Function partions array into 3 sections: = x, < x, > x.
Returns: Index used to split next recursive call
Parameters:
vector to be partitioned
left index of vector
right index of vector
Notes:
Written same as the 2-way except no <= only < when comparing elements
*/
int partition3(vector<int>& a, int l, int r)
{
   int x = a[l]; 
   int j = l;
   
   for (size_t i = l + 1; i <= r; ++i)
   {
      if (a[i] < x)
      {
         ++j;
         swap(a[i], a[j]);
      }
   }
      
   swap(a[l], a[j]);
   return j;
}
void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  //int m = partition2(a, l, r);
  int m = partition3(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}
