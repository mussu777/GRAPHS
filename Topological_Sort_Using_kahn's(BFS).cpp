#include<bits/stdc++.h>
using namespace std;

// APPROACH : kahn's Algo

#include <unordered_map>
#include <list> 
#include <queue>

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
//     CREATE ADJACENT LIST
   unordered_map <int, list<int> > adj ; 
   for ( int i = 0 ; i < e ; i++ ) 
   {
       int u = edges[i][0] ;
       int v = edges[i][1] ;
       adj[u].push_back(v) ;
   }
   
//      FIND ALL INDEGREE 
   vector <int> indegree (v);
   
   for ( auto i : adj ) 
   {
       for ( auto j : i.second )  
       {
           indegree[j]++ ;
       }
   }
   
//     ZERO INDEGREE WALO KO PUSH KRDO 
      queue <int> q ; 
      for ( int i = 0 ; i < v ; i++ ) 
    {
       if ( indegree[i] == 0 ) 
          q.push(i) ;
   }
   
//        DO BFS 
   vector <int> ans ; 
   
   while ( !q.empty() ) {
       int front = q.front() ;
        q.pop() ;
       
//         STORE ANSWER 
       ans.push_back(front) ;
       
//        UPDATE NEIGHBOUR INDEGREE 
       for ( auto neighbour : adj[front] ) 
       {
           indegree[neighbour]-- ; 
           
           if ( indegree[neighbour] == 0 )
               q.push(neighbour) ;
       }
   }
       return ans ;  
}