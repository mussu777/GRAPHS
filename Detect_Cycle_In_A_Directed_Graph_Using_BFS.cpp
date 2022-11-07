#include<iostream>
using namespace std;
#include <unordered_map>
#include <list>
#include <queue>

int detectCycleInDirectedGraph(int n, vector< pair <int, int>> &edges)
{
    //     CREATE ADJACENT LIST
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;  //  .first and .second isilye kiye kyunki upper me
        int v = edges[i].second - 1; //   vector ke andar PAIR me diya hua h
        
        adj[u].push_back(v);

    }

    //      FIND ALL INDEGREE
    vector<int> indegree(n);

    for (auto i : adj)
    {
        for (auto j : i.second)
        {
            indegree[j]++;
        }
    }

    //     ZERO INDEGREE WALO KO PUSH KRDO
    queue<int> q;

    for (int i = 0; i < n; i++)     
    {                                
        if (indegree[i] == 0)
            q.push(i);
    }

    //        DO BFS
    int count = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        //   INCREMENT COUNT
        count++;

        //        UPDATE NEIGHBOUR INDEGREE
        for (auto neighbour : adj[front])
        {
            indegree[neighbour]--;

            if (indegree[neighbour] == 0)
                q.push(neighbour);
        }
    }

    if (count == n)
    {
        return false;
    }

    else
    {
        return true;
    }
    
}