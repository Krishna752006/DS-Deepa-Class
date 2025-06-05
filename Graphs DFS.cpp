#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Graph{
  public:
  map<int, list<int>> adj;
  map<int, bool> visited;
  void addEdge(int i, int j)
  {
      adj[i].push_back(j);
  }
  void DFS()
  {
      for(auto& pair: adj)
      {
          if(!visited[pair.first])
          {
              DFSuntil(pair.first);
          }
      }
  }
  void DFSuntil(int k)
  {
      if(visited[k] != true)
      {
          visited[k] = true;
          cout << k << " ";
      }
      for(auto& i: adj[k])
      {
          if(!visited[i])
          {
              DFSuntil(i);
          }
      }
  }
};
int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 9);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(9, 3);
    cout << "Following is Depth First Traversal \n";
    g.DFS();
    return 0;
}