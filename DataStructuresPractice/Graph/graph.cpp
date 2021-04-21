#include "graph.h"
#include <queue>
#include <iostream>

namespace graph_list_basic
{
	Graph::Graph(int V)
	{
	   this -> vertNum = V;
	   adj = new std::list<int>[vertNum];
	   visit = new bool[vertNum];
	}
	
	void Graph::addEdge(int v, int w)
	{
	   adj[v].push_back(w); //Add w to v's list
	}
	
	int Graph::numVertices()
	{
	   return vertNum;
	}
	
	void Graph::BFS(int start)
   {
      // Mark all the vertices as not visited
      bool *visited = new bool[vertNum];
      for (size_t i = 0; i < vertNum; ++i)
         visited[i] = false;
      
      //Queue for BFS
      std::queue<int> bfsQueue;
   
      // Mark the current node as visited and enqueue it
      visited[start] = true;
      bfsQueue.push(start);
   
      // 'i' will be used to get all adjacent vertices of a vertex
      std::list<int>::iterator i;
   
      while(!bfsQueue.empty())
      {
         // Dequeue a vertex from queue and print it
         start = bfsQueue.front();
         std::cout << start << " ";
         bfsQueue.pop();
      
         // Get all adjacent vertices of the dequeued vertex start. If an adjacent
         // has not been visited then mark it visited and enqueue it
         for (i = adj[start].begin(); i != adj[start].end(); ++i)
         {
            if (!visited[*i])
            {
               visited[*i] = true;
               bfsQueue.push(*i);
            }
         } // End for
      } // End while
   } // End method
   
   void Graph::DFS(int start)
   {    
      // Mark current node as explored
      visit[start] = true;
      std::cout << start << " ";
      
      // Recursion for all adjacent vertices
      std::list<int>::iterator i;
      for (i = adj[start].begin(); i != adj[start].end(); ++i)
         if (!visit[*i])
            DFS(*i);
   } // End Method
} // End class
