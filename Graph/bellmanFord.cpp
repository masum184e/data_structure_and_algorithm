#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void bellman_ford(vector<vector<ll>> graph, ll source){
  ll vertices=graph.size();

  vector<ll> distance(vertices, LLONG_MAX);
  distance[source]=0;

  // RELAXATION
  for(ll k=1;k<vertices;k++)
    for(ll i=0;i<vertices;i++)
      for(ll j=0;j<vertices;j++)
        if(graph[i][j]!=INT_MAX && distance[j]>distance[i]+graph[i][j])
          distance[j]=distance[i]+graph[i][j];

  // CHECKING NEGATIVE CYCLE
  bool has_negative_cycle = false;
  for(ll i=0;i<vertices;i++){
    for(ll j=0;j<vertices;j++){
      if(graph[i][j]!=LLONG_MAX && distance[j]>distance[i]+graph[i][j]){
        distance[j]=distance[i]+graph[i][j];
        has_negative_cycle=true;
      }
    }
    if(has_negative_cycle)break;
  }

  // DISPLAYING SHORTEST PATH FROM SOURCE VERTEX
  if(has_negative_cycle)cout<<endl<<"The Graph Contain Negative Cycle"<<endl;
  else{
    cout<<endl<<"Minimum Distances From Source Node "<<source<<":"<<endl;
    for(ll i=0;i<vertices;i++)
      (distance[i]==LLONG_MAX)?cout<<"Vertex "<<i<<": Not Reachable"<<endl:cout<<"Vertex "<<i<<": "<<distance[i]<<endl;
  }
}


int main(){
  ll vertices, edges;

  cout<<"Enter Number of Vertices and Edges: ";
  cin>>vertices>>edges;

  // INITIALIZING LOOP NODE 0 AND OTHER INFINITY
    vector<vector<ll>> graph(vertices, vector<ll>(vertices, INT_MAX));
    for(ll i=0;i<vertices;i++)graph[i][i]=0;

  // GETTING INPUT
  for(ll i=0;i<edges;i++){
    ll from, to, weight;
    cout<<"Enter "<<i+1<<"th Edges and Their Weights: ";
    cin>>from>>to>>weight;
    graph[from][to]=weight;
  }

  ll source;
  cout<<"Enter Source Vertex: ";
  cin>>source;

  // DISPLAYING GIVEN GRAPH
  cout<<endl<<"Given Graph:"<<endl;
  for(ll i=0;i<vertices;i++){
    for(ll j=0;j<vertices;j++)
     (graph[i][j]==INT_MAX)?cout<<"I"<<" ":cout<<graph[i][j]<<" ";
    cout<<endl;
  }

  bellman_ford(graph, source);

  return 0;
}