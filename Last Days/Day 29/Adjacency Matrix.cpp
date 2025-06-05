/*
Write a C++ program to demonstrate Adjacency Matrix
 representation of undirected and unweighted graph
 
Sample Output:
Adjacency Matrix Representation
0 1 1 0
1 0 1 0
1 1 0 1
0 0 1 0

 */
 #include <bits/stdc++.h>
 using namespace std;
 
 void addEdge(vector<vector<int>> &mat, int i, int j)
 {
     mat[i][j] = 1;
     mat[j][i] = 1;
 }
 
 void displayMatrix(vector<vector<int>> &mat)
 {
    for (int i = 0;i<mat.size();i++)
    {
        for(int j = 0;j<mat[i].size();j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }
 }
 
 int main()
 {
 
     int V = 4;
     vector<vector<int>> mat(V, vector<int>(V, 0));
     addEdge(mat, 0, 1);
     addEdge(mat, 0, 2);
     addEdge(mat, 1, 2);
     addEdge(mat, 2, 3);
     cout << "Adjacency Matrix Representation" << endl;
     displayMatrix(mat);
 
     return 0;
 }