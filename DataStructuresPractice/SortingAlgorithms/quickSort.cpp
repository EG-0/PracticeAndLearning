#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;


void quickSort (vector<int>& sort, int left, int right);
int partition (vector<int>& sort, int left, int right, int& rIndex);
int medianOfThree (vector<int>& sort, int a, int b, int c);

int main ()
{
   int size;
   vector<int> sortVec;
   cout << "Type in size of randomized vector: ";
   cin >> size;
   
   for (size_t i = 0; i < size; ++i)
   {
      sortVec.push_back(rand() % 100);
      cout << sortVec.at(i) << " ";
   }
   
   cout << endl;
   quickSort(sortVec, 0, sortVec.size() - 1);
   
   for (size_t i = 0; i < size; ++i)
   {
      cout << sortVec.at(i) << " ";
   }
   
   cout << endl;

   return 0;
}


void quickSort (vector<int>& sort, int left, int right) 
{
   if (left >= right)
      return;
      
   int lIndex; //Holds index of leftmost pivot 
   int rIndex; //Holds index of rightmost pivot
   lIndex = partition(sort, left, right, rIndex);
   quickSort(sort, left, lIndex - 1);
   quickSort(sort, rIndex + 1, right);
}

int partition (vector<int>& sort, int left, int right, int& rIndex)
{
   int i = left - 1; //index of elements less than the pivot
   rIndex = left - 1; //Index of elements equal to pivot
 
   //Calculate pivot - Median of 3 method
   int first = rand() % (right - left) + left;
   int second = rand() % (right - left) + left;
   int third = rand() % (right - left) + left;
   int pivot = sort[medianOfThree(sort, first, second, third)];
   
   for (size_t k = left; k <= right; ++k)
   {
      int temp;
      if (sort[k] < pivot)
      {
         ++i;
         ++rIndex;
         temp = sort[k];
         sort[k] = sort[rIndex];
         sort[rIndex] = sort[i];
         sort[i] = temp;         
      }
      else if (sort[k] == pivot)
      {
         ++rIndex;
         temp = sort[k];
         sort[k] = sort[rIndex];
         sort[rIndex] = temp;
      }
   }
   
   return i + 1;
}

int medianOfThree(vector<int>& sort, int a, int b, int c) 
{
   //Check for a as the middle number
   if ((sort[b] < sort[a] && sort[a] < sort[c]) || (sort[c] < sort[a] && sort[a] < sort[b]))
      return a;
   //Check for b as the middle number
   else if ((sort[c] < sort[b] && sort[b] < sort[a]) || (sort[a] < sort[b] && sort[b] < sort[c]))
      return b;
   //C is the middle number
   else 
      return c;
}
