#include<iostream>
using namespace std;
#include <unordered_map>
#include <queue>
#include <list>
#include<algorithm>


vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int d)
{

//   CREATE ADJACENCY LIST 
  unordered_map <int , list<int> > adj ; 
  for ( int i = 0 ; i < edges.size() ; i++ ) {
      int u = edges[i].first ;
      int v = edges[i].second ;
      
      adj[u].push_back(v) ;
      adj[v].push_back(u) ;
  }
  
//       DO BFS 
  unordered_map<int , bool> visited ; 
  unordered_map <int,int> parent ; 
  queue<int> q ; 
  q.push(s) ;
  parent[s] = -1 ; 
  visited[s] = true ; 
  
  while ( !q.empty() ) {
      int front = q.front() ;
      q.pop() ;
      
      // Traverse Neighbour
      for ( auto i : adj[front] ) {
          if ( !visited[i] ) {
          visited[i] = true ; 
          parent[i] = front ; 
          q.push(i) ;
 }
  } 
}

//        PREPARE SHORTEST PATH
        vector <int> ans ; 
        int currentNode = d ; 
        ans.push_back(d) ;

    while ( currentNode != s )
    {
        currentNode = parent[currentNode] ;
        ans.push_back(currentNode) ;         
    } 
        reverse (ans.begin() , ans.end()) ;
        return ans ; 
}