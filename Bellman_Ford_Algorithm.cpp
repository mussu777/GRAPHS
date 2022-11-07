#include <bits/stdc++.h>
using namespace std;

// APPROACH 1 : FOR NO NEGATIVE WEIGHT CYCLES

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    //      UPDATING N-1 TIMES

    for (int i = 1; i <= n; i++)
    {
        //         TRAVERSE ALL EDGES
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }

    return dist[dest];
}

// APPROACH 2 : FOR NEGATIVE WEIGHT CYCLES

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e9);
    dist[src] = 0;

    //      UPDATING N-1 TIMES

    for (int i = 1; i <= n; i++)
    {
        //         TRAVERSE ALL EDGES
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    // Checking for Negative Cycle
    bool flag = 0;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
        {
            flag = 1;
        }
    }

    if (flag == 0)
    {
        return dist[dest];
    }
    return -1;
}