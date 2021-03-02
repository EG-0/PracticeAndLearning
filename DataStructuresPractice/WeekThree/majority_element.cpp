#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right);

int main() {
  int n;
  std::cout << "Enter size of list: ";
  std::cin >> n;
  vector<int> a(n);
  std::cout << "Enter numbers in list with spaces: ";
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}

/*
Pre: None
Post: majority element is returned. If no majority element then 
   returns -1
Parameters:
vector<int>& a: List to check for element in
int left: Left most number to search from
int right: Rightmost number - 1 to search to
*/
int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1; //Error checking in case OOB
  if (left + 1 == right) return a[left]; //If broken up into one

  size_t oneCount = 0; //keep count of numOne
  size_t twoCount = 0; //keep count of numTwo
  //Split into separate halves to break up problem
  int numOne = get_majority_element(a, left, (left + right) / 2);
  int numTwo = get_majority_element(a, (left + right) / 2, right);

   //Count how many times the two occur in an array
   for (size_t i = left; i < right; ++i)
   {
      if (numOne == a.at(i))
         ++oneCount;
      if (numTwo == a.at(i))
         ++twoCount;
   }
   
   //If either are more than half then they are a majority element
   if (oneCount > (right - left) / 2)
      return numOne;
   if (twoCount > (right - left) / 2)
      return numTwo;

  return -1;
}
