
// T.C.=S.C.= O(V+E)(linear time)

#include <bits/stdc++.h>
using namespace std;

bool bfsCycleDetection(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, unordered_map<int, int> &parent, int node)
{

    queue<int> q;

    visited[node] = 1;
    parent[node] = -1;

    q.push(node);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();

        for (auto neighbour : adjList[frontNode])
        {
            if (visited[neighbour] && neighbour != parent[frontNode])
            {
                return true;
            }
            
            else if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = frontNode;
            }
        }
    }
    return false;
}

bool dfsCycleDetection(unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &visited, int parent, int node)
{

    visited[node] = true;

    for (auto neighbour : adjList[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = dfsCycleDetection(adjList, visited, node, neighbour);
            if (cycleDetected)
            {
                return true;
            }
        }
        else if (neighbour != parent)
        {
            // cycle is present
            return true;
        }
    }
    return false;
}
string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;

    // prepare adjacency list
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // to handle disconnected components
    unordered_map<int, bool> visited;

    // create to track parent
    unordered_map<int, int> parent;

    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {

         // bool ans = bfsCycleDetection(adjList,visited,parent,i);

            bool ans = dfsCycleDetection(adjList, visited, -1, i);

            if (ans == 1)
            {
                return "Yes";
            }
        }
    }

    return "No";
}