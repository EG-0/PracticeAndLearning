#include <iostream>
#include "graph.h"
#include <queue>
using namespace graph_list_basic;

int main ()
{
   Graph g(4);
   g.addEdge(0, 1);
   g.addEdge(0, 2);
   g.addEdge(1, 2);
   g.addEdge(2, 0);
   g.addEdge(2, 3);
   g.addEdge(3, 3);
   
   size_t num;
   std::cin >> num;
   std::cout << "BFS of number " <<  num << std::endl;
   g.BFS(num);
   std::cout << std::endl;
   
   std::cout << "DFS of number " << num << std::endl;
   g.DFS(num);
   std::cout << std::endl;
  
   return 0;
}
