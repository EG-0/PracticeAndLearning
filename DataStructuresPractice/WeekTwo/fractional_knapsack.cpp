// Not the most efficient implementation, unsure if last vdivw
//    vector was needed...
#include <iostream>
#include <vector>
#include <iomanip>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, 
         vector<int> values);
void bubble_sort(vector<int>& weights, vector<int>& values, 
         vector<double>& vdivw);


int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << std::fixed << std::setprecision(4) 
      << optimal_value << std::endl;
  
  return 0;
}

double get_optimal_value(int capacity, vector<int> weights,
         vector<int> values) 
{
  double value = 0.0;
  vector<double> vdivw (values.size());

  //Initialize vector with values and divide by weights
  for (size_t i = 0; i < vdivw.size(); ++i)
  {
      vdivw.at(i) = (double)values.at(i) / (double)weights.at(i);
  }

   //Sort weights / values
   bubble_sort(weights, values, vdivw);
   
  //Add maximum value to value variable
  for (int i = vdivw.size() - 1; i >= 0; --i)
  {
      //weight is less then capacity add whole vdivw
      if (weights.at(i) < capacity)
      {
         value += vdivw.at(i) * weights.at(i);
         capacity -= weights.at(i); //Must decrease avail. cap. w/ weight
      }
      //add part of the number and exit loop
      else
      {
         value += capacity * vdivw.at(i);
         break;
      }
  }
  
  return value;
}


void bubble_sort(vector<int>& weights, vector<int>& values, 
         vector<double>& vdivw)
{
   bool swap = false; //Variable to tell if vector is sorted
   double temp; //Temporary variable
   
   do
   {
      //Must reinitialize to avoid infin. loop
      swap = false;
      
      for (size_t i = 0; i < vdivw.size() - 1; ++i)
      {
         //Comparing values to next vector element
         if (vdivw.at(i) > vdivw.at(i + 1))
         {
            swap = true;
            temp = vdivw.at(i + 1);
            vdivw.at(i + 1) = vdivw.at(i);
            vdivw.at(i) = temp;
            
            temp = values.at(i + 1);
            values.at(i + 1) = values.at(i);
            values.at(i) = temp;
            
            temp = weights.at(i + 1);
            weights.at(i + 1) = weights.at(i);
            values.at(i) = temp;
         }
      }
   } while (swap);
}
