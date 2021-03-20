#include <iostream>
#include <vector>
using namespace std;

int binarySearchIter(vector<int>& sort, int key);
int binarySearchRecur(vector<int>& sort, int key, int left, int right);

int main()
{
   vector<int> sort;   
   int key;
   
   for (size_t i = 0; i < 1000; ++i)
   {
      sort.push_back(i + 1);
   }

   cout << "Enter a number to search for between 0 and " << sort.size() - 1 << ": ";
   cin >> key;
   
   cout << "BinarySearchIter: " << binarySearchIter(sort, key);
   cout << endl;
   cout << "BinarySearchRecur: " << binarySearchRecur(sort, key, 0, sort.size() - 1);
   cout << endl;
  
   return 0;
}

//Returns either the index of element, -1 if not found
int binarySearchIter(vector<int>& sort, int key)
{
   int startIndex = 0;
   int endIndex = sort.size() - 1;
   
   while (startIndex <= endIndex)
   {
      int mid = (startIndex + endIndex) / 2;
      if (sort[mid] < key)
      {
         startIndex = mid + 1;
      }
      else if (sort[mid] > key)
      {
         endIndex = mid - 1;
      }
      else
         return mid;
   }
   
   return -1;
}

//Returns either the index of element, -1 if not found
int binarySearchRecur(vector<int>& sort, int key, int left, int right) 
{     
   if (left <= right)
   {
      int mid = (left + right) / 2;
      if (sort[mid] == key)
         return mid;
      if (sort[mid] < key)
         return binarySearchRecur(sort, key, mid + 1, right);
      if (sort[mid] > key)
         return binarySearchRecur(sort, key, left, mid - 1);
   }
   
   return -1;
}
