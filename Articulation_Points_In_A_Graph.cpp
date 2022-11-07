#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;

int min(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void DFS(int node, int parent, vector<int> &disc, vector<int> &low, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adj, vector<int> &AP, int &timer)
{
    vis[node] = true;
    disc[node] = low[node] = timer++;
    int child = 0;

    for (auto nbr : adj[node])
    {
        if (nbr == parent)
            continue;

        if (!vis[nbr])
        {
            DFS(nbr, node, disc, low, vis, adj, AP, timer);
            low[node] = min(low[node], low[nbr]);

            // Check AP or not
            if (low[nbr] >= disc[node] && parent != -1)
            {
                AP[node] = true;
            }

            child++;
        }

        else
        {
            low[node] = min(low[node], disc[nbr]);
        }
        
    }

    if (parent == -1 && child > 1)
    {
        AP[node] = true;
    }
}

int main()
{

    int n = 5;
    int e = 5;

    vector<pair<int, int>> edges;

    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    // adj list
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0;
    vector<int> disc(n);
    vector<int> low(n);
    unordered_map<int, bool> vis;

    vector<int> AP(n, 0);

    for (int i = 0; i < n; i++)
    {
        disc[i] = -1;
        low[i] = -1;
    }

    // DFS
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            DFS(i, -1, disc, low, vis, adj, AP, timer);
        }
    }

    // Print AP
    cout << "Articulation points are as follows " << endl;
    for (int i = 0; i < n; i++)
    {
        if (AP[i] != 0)
        {
            cout << i << " " << endl;
        }
    }

    return 0;
}