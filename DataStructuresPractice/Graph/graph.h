// Graph representation based on geeksforgeeks
#ifndef GRAPH_CLASS_LIST_H
#define GRAPH_CLASS_LIST_H
#include <list>

namespace graph_list_basic
{
   class Graph 
   {
      public:
         Graph(int V); // Constructor
         void addEdge(int v, int w); // Adds an edge to the graph
         int numVertices(); // Returns the number of vertices
         void BFS(int start); // Breadth first search on graph
         void DFS(int start); // Depth first search on graph
      private:
         int vertNum; // Number of vertices
         std::list<int> *adj; // Pointer to an array containing adjacency lists
         bool *visit; // Whether or not a node has been visited 
   };
}

#endif
