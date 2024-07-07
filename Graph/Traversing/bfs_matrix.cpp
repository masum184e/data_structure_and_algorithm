#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void bfs(vector<vector<ll>> graph, ll source){
    ll vertices=graph.size();
    vector<bool> visited(vertices,false);
    queue<ll>bfsQueue;

    bfsQueue.push(source);
    visited[source]=true;

    cout<<endl<<"BFS Traversal Starting From Node "<<source<<": ";

    while(!bfsQueue.empty()){
        ll current=bfsQueue.front();
        bfsQueue.pop();

        cout<<current<<" ";

        for(ll i=0;i<vertices;i++){
            if(graph[current][i]==1 && !visited[i]){
                bfsQueue.push(i);
                visited[i]=true;
            }
        }
    }
    cout<<endl;
}

int main(){
  ll vertices, edges, root;

  cout<<"Enter Number of Vertices and Edges: ";
  cin>>vertices>>edges;

  vector<vector<ll>> graph(vertices, vector<ll>(vertices, 0));

  // GETTING INPUT
  for(ll i=0;i<edges;i++){
    ll from, to;
    cout<<"Enter "<<i+1<<"th Start and End Node: ";
    cin>>from>>to;
    graph[from][to]=1;
  }

  cout<<"Enter Root Node: ";cin>>root;

  // DISPLAYING GIVEN GRAPH
  cout<<endl<<"Given Graph:"<<endl;
  for(ll i=0;i<vertices;i++){
    for(ll j=0;j<vertices;j++)
      cout<<graph[i][j]<<" ";
    cout<<endl;
  }

  bfs(graph,root);
  
  return 0;
}