#include <bits/stdc++.h>
using namespace std;

#include <unordered_map>
#include <list>
#include <stack>

void dfs(int node, unordered_map<int, bool> &vis, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;
    for (auto neighbour : adj[node])
    {
        if (!vis[neighbour])
        {
            dfs(neighbour, vis, st, adj);
        }
    }
    //  TOPO LOGIC
    st.push(node);
}

void revDfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj)
{
    vis[node] = true;

    for (auto neighbour : adj[node])
    {
        if (!vis[neighbour])
        {
            revDfs(neighbour, vis, adj);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    // CREATE ADJACENCY LIST
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
    }

    //  TOPO SORT
    stack<int> st;
    unordered_map<int, bool> vis;

    for (int i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, st, adj);
        }
    }

    //  CREATE TRANSPOSE GRAPH
    unordered_map<int, list<int>> transpose;

    for (int i = 0; i < v; i++)
    {
        vis[i] = false;
        for (auto neighbour : adj[i])
        {
            transpose[neighbour].push_back(i);
        }
    }
    // DFS CALL USING ABOVE ORDERING
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!vis[top])
        {
            count++;
            revDfs(top, vis, transpose);
        }
    }
    return count;
}