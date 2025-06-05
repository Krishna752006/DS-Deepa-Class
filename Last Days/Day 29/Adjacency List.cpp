/*
Write a C++ program to print the 
adjanceny list of a graph

Sample Output:
Adjacency List Representation:
0: 1 2
1: 0 2
2: 0 1 3
3: 2

*/

#include <iostream>
#include <vector>
using namespace std;

// Function to add an edge between two vertices
void addEdge(vector<vector<int>>& adj, int i, int j) {
   adj[i].push_back(j);
   adj[j].push_back(i);
}

// Function to display the adjacency list
void displayAdjList(const vector<vector<int>>& adj) {
    for(int i = 0;i < adj.size();i++)
    {
        cout << i << ": ";
        for(int j : adj[i])
        {
            cout << j << " ";
        }
        cout << "\n";
    }
}


int main() {
      int V = 4;
    vector<vector<int>> adj(V); 

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 2);
    addEdge(adj, 2, 3);

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);

    return 0;
}