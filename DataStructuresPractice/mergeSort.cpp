#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

void mergeSort(vector<int>& sortVec, int left, int right);
void merge(vector<int>& sortVec, int left, int mid, int right);
int main () 
{
   int input;
   vector <int> randomVec;

   cout << "Input size of vector to be sorted: ";
   cin >> input;
   cout << endl;
   
   for (size_t i = 0; i < input; ++i)
   {
      randomVec.push_back(rand() % 100);
      cout << randomVec.at(i) << " ";
   }
   
   cout << endl << endl;
   mergeSort(randomVec, 0, randomVec.size() - 1);
   
   for (size_t i = 0; i < input; ++i)
   {
      cout << randomVec.at(i) << " ";
   }

   cout << endl << endl;

   return 0;
   
}
/*
Breaks Up Vector to prepare for merging
Parameters:
Vector to be sorted
Left (inclusive) index
Right (inclusive) index
*/
void mergeSort(vector<int>& sortVec, int left, int right) 
{
   if (left >= right)
      return;
   mergeSort(sortVec, left, (left + right) / 2);
   mergeSort(sortVec, (left + right) / 2 + 1, right);
   merge(sortVec, left, (left + right) / 2, right);
}
/*
Merges broken up parts of vector together
Parameters:
Vector to be merged
Left (inclusive) index
Mid index
Right (inclusive) index
*/
void merge(vector<int>& sortVec, int left, int mid, int right)
{
   int lower = mid - left + 1; //Size of lower temp array
   int upper = right - mid; //Size of upper temp array
   
   vector <int> tempLower; //Vector to hold lower half 
   vector <int> tempUpper; //Vector to hold upper half
   
   //Initialize temporary vectors with values
   for (size_t i = 0; i < lower; ++i)
   {
      tempLower.push_back(sortVec.at(left + i));
   }
   
   for (size_t i = 0; i < upper; ++i) 
   {
      tempUpper.push_back(sortVec.at(mid + 1 + i));
   }
   
   size_t l = 0;
   size_t u = 0;
   size_t actual = left;
   
   //Copy Ordered values into original vector
   while (l < lower && u < upper)
   {
      if (tempLower.at(l) < tempUpper.at(u))
      {
         sortVec.at(actual) = tempLower.at(l);
         ++l;
      }
      else
      {
         sortVec.at(actual) = tempUpper.at(u);
         ++u;
      }
      ++actual;
   }
   
   //Copy any remaining values from lower vector
   while (l < lower)
   {
      sortVec.at(actual) = tempLower.at(l);
      ++l;
      ++actual;
   }

   //Copy any remaining values into upper vector
   while (u < upper) 
   {
      sortVec.at(actual) = tempUpper.at(u);
      ++u;
      ++actual;
   }
}
