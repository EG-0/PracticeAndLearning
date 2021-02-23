#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

//Function declarations
vector<int> optimal_points(vector<Segment> &segments);
void bubble_sort_start(vector<Segment>& segments);
void bubble_sort_end(vector<Segment>& segments);

int main() {
  int n;
  std::cout << "Enter number of segments: ";
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cout << "Enter segments start, segments end: ";
    std::cin >> segments[i].start >> segments[i].end;
  }
  
  vector<int> points = optimal_points(segments);
  
  std::cout << "Points Size: ";
  std::cout << points.size() << "\n";
  std::cout << "Points: ";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  std::cout << std::endl;
}


vector<int> optimal_points(vector<Segment>& segments) 
{
  vector<int> points;
  
  //Sort through segments start positions
  bubble_sort_start(segments);
  bubble_sort_end(segments);
  //Pick an initial point 
  int optPoint = segments.at(0).end;
  points.push_back(optPoint);
  
  //Size_t initialized at 1 because first point is already done
  for (size_t i = 1; i < segments.size(); ++i) 
  {
      if (optPoint < segments[i].start || optPoint > segments[i].end)
      {
         optPoint = segments[i].end;
         points.push_back(optPoint);
      }
  }

  return points;
}

//Function sorts through the start segments smallest to largest
void bubble_sort_start(vector<Segment>& segments)
{
   Segment tempSeg;
   bool swap;
   
   do 
   {
      swap = false;
      for (size_t i = 0; i < segments.size() - 1; ++i)
      {
         if (segments.at(i).start > segments.at(i + 1).start)
         {
            tempSeg.start = segments.at(i + 1).start;
            segments.at(i + 1).start = segments.at(i).start;
            segments.at(i).start = tempSeg.start;
            
            swap = true;
         }
      }
   } 
   while (swap);
}

//Function sorts throught the end segments smallest to largest
void bubble_sort_end(vector<Segment>& segments)
{
   Segment tempSeg;
   bool swap;
   
   do 
   {
      swap = false;
      for (size_t i = 0; i < segments.size() - 1; ++i)
      {
         if (segments.at(i).end > segments.at(i + 1).end)
         {
            tempSeg.end = segments.at(i + 1).end;
            segments.at(i + 1).end = segments.at(i).end;
            segments.at(i).end = tempSeg.end;
               
            swap = true;
         }
      }
   } 
   while (swap);
}
