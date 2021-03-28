//Based on code from:
// https://www.codewithc.com/breadth-first-search-in-c/
#include <iostream>
#include <ctime>
using namespace std;

struct node
{
   int info;
   node *next;
};

class Queue
{
   public:
      Queue();
      ~Queue();
      bool isEmpty();
      void enqueue(int);
      int dequeue();
      void display();
   private:
      node *front;
      node *rear;
};

void Queue::display()
{
   node *p = new node;
   p = front;
   if (front == nullptr)
   {
      cout << "Nothing to display" << endl;
   }
   else
   {
      while(p != nullptr)
      {
         cout<<endl<< p -> info;
         p = p -> next;
      }
   }
}

Queue::Queue()
{
   front = nullptr;
   rear = nullptr;
}

Queue::~Queue()
{
   delete front;
}

void Queue::enqueue(int data)
{
   node *temp = new node();
   temp -> info = data;
   temp -> next = nullptr;
   if (front == nullptr)
   {
      front = temp;
   }
   else 
   {
      rear -> next = temp;
   }
   
   rear = temp;
}

int Queue::dequeue() 
{
   node *temp = new node();
   int value;
   
   if (front == nullptr)
   {
      cout << "Queue is empty" << endl;
   }
   else 
   {
      temp = front;
      value = temp -> info;
      front = front -> next;
      delete temp;
   }
   return value;
}

bool Queue::isEmpty()
{
   return (front == nullptr);
}

class Graph {
   public:
      Graph(int size = 2);
      ~Graph();
      bool isConnected(int, int);
      void addEdge(int u, int v);
      void BFS(int );
   private:
      int n; //Represents the number of vertices in the graph
      int **A; //A is stroing the edge between two vertices
};

Graph::Graph(int size)
{
   int i, j;
   if (size < 2) 
      n = 2;
   else 
      n = size;
   
   A = new int*[n];
   for (i = 0; i < n; ++i)
      A[i] = new int[n];
    
   for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
         A[i][j] = 0;  
}

Graph::~Graph()
{
   for (int i = 0; i < n; ++i)
      delete [] A[i];
   delete [] A;
}

bool Graph::isConnected(int u, int v)
{
   return (A[u - 1][v - 1] == 1);
}

void Graph::addEdge(int u, int v) 
{
   A[u - 1][v - 1] = 1;
   A[v - 1][u - 1] = 1;
}

void Graph::BFS(int s)
{
   Queue Q;
   
   bool *explored = new bool[n+1]; //Keeps track of explored vertices
   
   for (int i = 1; i <= n; ++i) //initialization of all veritces as unexplored
      explored[i] = false;
      
   Q.enqueue(s); //Pushing of initial vertes to the queue
   explored[s] = true; //marking it as explored
   
   cout << "Breadth first search starting from vertex ";
   cout << s << " : " << endl;
   
   //Unless the queue is empty is to be performed
   while (!Q.isEmpty())
   {
      //Pop the vertex from the queue
      int v = Q.dequeue();
      
      //Display the explored vertices
      cout << v << " ";
      
      //From the explored vertex v try to explore all the connected vertices
      for (int w = 1; w <= n; ++w)
      {
         //Explores the vertex w if it is connect to v and and if it is unexplored
         if (isConnected(v, w) && !explored[w])
         {
            //Adds the vertex w to the queue
            Q.enqueue(w);
            //Marks the vertex w as visited
            explored[w] = true;
         }
      }
   }
   
   cout << endl;
   delete [] explored;\
}

int main() 
{
   //Creates a grpah with 12 vertices
   Graph g(12);
   
   //Adds edges to the graph
   g.addEdge(1, 2);
   g.addEdge(1, 3);
   g.addEdge(2, 4);
   g.addEdge(3, 4);
   g.addEdge(3, 6);
   g.addEdge(4, 7);
   g.addEdge(5, 6);
   g.addEdge(5, 7);
   clock_t t1;
   t1 = clock();
   
   //Explores all vertices findable form vertex 1
   g.BFS(1);
   float diff = (double)(clock() - t1) / CLOCKS_PER_SEC;
   cout << endl << "The time taken for BFS: " << diff << endl;

}
