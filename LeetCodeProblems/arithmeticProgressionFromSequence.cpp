#include <iostream>
#include <vector>
using namespace std;

bool canMakeArithmeticProgression(vector<int>& arr);
void quickSort(vector<int>& sort, int left, int right);
int partion(vector<int>& sort, int left, int right);

int main()
{
   int size;
   vector<int> sort;
   
   sort.push_back(-68);
   sort.push_back(-96);
   sort.push_back(-12);
   sort.push_back(-40);
   sort.push_back(16);

   cout << endl;
   canMakeArithmeticProgression(sort);
   
   cout << endl;
   
   return 0;
}


bool canMakeArithmeticProgression(vector<int>& arr) 
{
   quickSort(arr, 0, arr.size() - 1);
   
   for (int i = 0; i < arr.size(); ++i)
      cout << arr[i] << " ";
   
   bool progression = true;
   int diff = arr[1] - arr[0];
        
   for (int i = 0; i < arr.size() - 1; ++i)
   {
      if ((arr[i + 1] - arr[i]) != diff)
      {
         progression = false;
         break;
      }
   }
     
   return progression;
}
    
void quickSort(vector<int>& sort, int left, int right)
{
   if (left >= right)
      return;
   
   //Index of leftmost pivot
   int lIndex = partion(sort, left, right);
   quickSort(sort, left, lIndex - 1);
   quickSort(sort, lIndex + 1, right);
}
    
int partion(vector<int>& sort, int left, int right)
{
   int lessPivot = left - 1;
        
   //pivot is a middle number
   int pivot = sort[right];

   for (size_t i = left; i <= right - 1; ++i)
   {
      if (sort[i] <=  pivot)
      {
         ++lessPivot;
         int temp = sort[i];
         sort[i] = sort[lessPivot];
         sort[lessPivot] = temp;
      }
   }

   int temp = sort[lessPivot + 1];
   sort[lessPivot + 1] = sort[right];
   sort[right] = temp;
   
   return lessPivot + 1;
}
