#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> printAdjacency(int n, int m, vector<vector<int>> &edges)
{
    // n => Is Number Of Nodes
    // m => Is Number Of edges

    vector<vector<int>> ans(n);

    // For Each Node
    for (int i = 0; i < n; i++)
    {
        ans[i].push_back(i);
    }

    // For Edges
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        ans[u].push_back(v);
        ans[v].push_back(u);
    }

    return ans;
    
}
