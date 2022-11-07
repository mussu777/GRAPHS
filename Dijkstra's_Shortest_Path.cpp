#include <bits/stdc++.h> 
using namespace std;

#include <unordered_map>
#include <list>
#include <set>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) 
{
// CREATE ADJANCENCY LIST 
   unordered_map <int, list<pair <int,int> > > adj ; 
   for ( int i = 0 ; i < edges ; i++ ) 
   {
       int u = vec[i][0] ;
       int v = vec[i][1] ;
       int w = vec[i][2] ;
              
       adj[u].push_back(make_pair(v,w)) ; 
       adj[v].push_back(make_pair(u,w)) ; 
   } 
    
//     CREATION OF DISTANCE ARRAY WITH INFINITE VALUE INITIALLY
     vector <int> dist(vertices) ;
   
   for ( int i = 0 ; i < vertices ; i++ ) 
       dist[i] = INT_MAX ; 
   
//      CREATION OF SET ON BASIS (DISTANCE , NODE)
       set<pair<int,int> > st ; 
   
//      INITIALISE DISTANCE AND SET WITH SOURCE NODE
      dist[source] = 0 ;
      st.insert(make_pair(0,source)) ;
   
      while ( !st.empty() ) 
     {
//          FETCH TOP RECORD 
       auto top = *(st.begin()) ;
       
       int nodeDistance = top.first ; 
       int topNode = top.second ;
       
//          REMOVE TO RECORD NOW  
       st.erase(st.begin()) ;
       
//          TRAVERSE ON NEIGHBOUR 
  for ( auto neighbour : adj[topNode])
  {
       if ( nodeDistance + neighbour.second < dist[neighbour.first] ) 
    {
       auto record = st.find(make_pair (dist[neighbour.first] , neighbour.first)) ;
        
//          IF RECORD FOUND , THEN ERASE IT 
           if ( record != st.end())
        {
            st.erase(record) ;
       }      
          
//          DISTANCE UPDATE 
      dist[neighbour.first] = nodeDistance + neighbour.second ;
//          RECORD PUSH IN SET 
      st.insert(make_pair(dist[neighbour.first] , neighbour.first)) ; 
       }
       }
 }
      return dist ; 
}
