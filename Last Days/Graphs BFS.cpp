#include <iostream>
#include <list>
#include <map>
#include <queue>
using namespace std;

class Graph {
    map<int, list<int>> adj;

public:
    void addEdge(int v, int w) {
        adj[v].push_back(w); // directed edge from v to w
    }

    void BFS(int s) {
        map<int, bool> visited;
        queue<int> q;

        visited[s] = true;
        q.push(s);

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cout << node << " ";

            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    cout << "Following is Breadth First Traversal: ";
    g.BFS(2);
    return 0;
}
