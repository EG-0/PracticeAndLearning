#include <iostream>
#include <vector>
using namespace std;

vector<int> minSubsequence(vector<int>& nums);
void mergeSort(vector<int>& nums, int left, int right);
void merge(vector<int>& nums, int left, int mid, int right);

int main () 
{
   int input;
   vector<int> randomVec;

   randomVec.push_back(4);
   randomVec.push_back(4);
   randomVec.push_back(7);
   randomVec.push_back(6);
   randomVec.push_back(7);
   
   
   vector<int> newVec;
   newVec = minSubsequence(randomVec);
   
   for (int i = 0; i < newVec.size(); ++i)
   {
      cout << newVec[i] << " ";
   }
   
   cout << endl << endl;
   
   return 0;   
}

vector<int> minSubsequence(vector<int>& nums) {
        
    //Sort the array
    mergeSort(nums, 0, nums.size() - 1);
       
    vector<int> strictlyGrtr;

    int sum = 0;
    int tempSum = 0;
        
    //Find sum of all numbers in array excluding last
    for (size_t i = 0; i < nums.size(); ++i)
    {
        tempSum += nums[i];
    }
    
    //Calculate minimum subsequence
    for (int i = nums.size() - 1; i >= 0; --i)
    {
        //If the sum is not greater then all the preciding numbers, increased
        if (sum <= tempSum)
        {
            sum += nums[i];
            tempSum -= nums[i];
            strictlyGrtr.push_back(nums[i]);
        }
        else 
            break;
       
    }
        
    return strictlyGrtr;
}
    
void mergeSort(vector<int>& nums, int left, int right)
{
    if (left >= right)
        return;
        
    int mid = left + (right - left) / 2;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);            
}
    
void merge(vector<int>& nums, int left, int mid, int right)
{
    int lower = mid - left + 1;
    int upper = right - mid; 
        
    vector<int> tempLower;
    vector<int> tempUpper;
        
    for (size_t i = 0; i < lower; ++i)
    {
        tempLower.push_back(nums[left + i]);
    }
        
    for (size_t i = 0; i < upper; ++i)
    {
        tempUpper.push_back(nums[mid + i + 1]);   
    }
        
    int l = 0;
    int u = 0;
    int actual = left;
        
    while (l < lower && u < upper)
    {
        if (tempLower[l] < tempUpper[u])
        {
            nums[actual] = tempLower[l];
            ++l;
        }
        else 
        {
           nums[actual] = tempUpper[u]; 
           ++u;
        }
            
        ++actual;
    }
        
    while (l < lower)
    {
        nums[actual] = tempLower[l];
        ++l;
        ++actual;
    }
        
    while (u < upper)
    {
        nums[actual] = tempUpper[u];
        ++u;
        ++actual;
    }
}
