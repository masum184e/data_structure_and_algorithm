// FLOYD WARSHAL ALGORITHM
#include<bits/stdc++.h>
using namespace std;

void floyd_warshal(vector<vector<int>> graph){

  // CALCULATING SHORTEST PATH
  for(int k=0;k<graph.size();k++)
    for(int i=0;i<graph.size();i++)
      for(int j=0;j<graph.size();j++)
        if(graph[i][j]>(graph[i][k]+graph[k][j]) && graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX)
          graph[i][j]=graph[i][k]+graph[k][j];

  // DISPLAYING ALL PAIR SHORTEST PATH
  cout<<endl<<"All Pairs Shortest Path:"<<endl;
  for(int i=0;i<graph.size();i++){
    for(int j=0;j<graph.size();j++)
      (graph[i][j]==INT_MAX)?cout<<"INT_MAX ":cout<<graph[i][j]<<" ";
    cout<<endl;
  }
}

int main(){
  int vertices, edges;

  cout<<"Enter Number of Vertices and Edges: ";
  cin>>vertices>>edges;

  // INITIALIZING LOOP NODE 0 AND OTHER INFINITY
  vector<vector<int>> graph;
  for(int i=0;i<vertices;i++){
    vector<int> v;
    for(int j=0;j<vertices;j++)v.push_back(INT_MAX);

    graph.push_back(v);
    graph[i][i]=0;
  }

  // GETTING INPUT
  for(int i=0;i<edges;i++){
    int from, to, weight;
    cout<<"Enter "<<i+1<<"th Edges and Their Weights: ";
    cin>>from>>to>>weight;
    graph[from-1][to-1]=weight;
  }

  // DISPLAYING GIVEN GRAPH
  cout<<endl<<"Given Graph:"<<endl;
  for(int i=0;i<vertices;i++){
    for(int j=0;j<vertices;j++)
      cout<<graph[i][j]<<" ";
    cout<<endl;
  }

  floyd_warshal(graph);

  return 0;
}