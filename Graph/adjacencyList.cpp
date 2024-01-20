#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void adjacencyList(vector<vector<ll>> graph) {
    ll vertices=graph.size();

    cout<<endl<<"Adjacency List:"<<endl;
    for(ll i=0;i<vertices;i++) {
        cout<<"Node "<<i<<": ";
        bool hasNeighbor=false;
        for (ll j=0;j<vertices;j++) {
            if(graph[i][j]==1) {
                if(hasNeighbor) {
                    cout<< "->";
                }
                cout<<j;
                hasNeighbor=true;
            }
        }
        cout << endl;
    }
}

int main(){
  ll vertices, edges;

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

  // DISPLAYING GIVEN GRAPH
  cout<<endl<<"Given Graph:"<<endl;
  for(ll i=0;i<vertices;i++){
    for(ll j=0;j<vertices;j++)
      cout<<graph[i][j]<<" ";
    cout<<endl;
  }

  adjacencyList(graph);
  
  return 0;
}