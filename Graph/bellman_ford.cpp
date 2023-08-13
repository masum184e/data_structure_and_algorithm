#include<bits/stdc++.h>
using namespace std;

void bellman_ford(vector<vector<int>> graph, int source_vertex){
  int vertices_number=graph.size();

  vector<int> distance(vertices_number, INT_MAX);
  distance[source_vertex-1]=0;

  // RELAXATION
  for(int k=1;k<vertices_number;k++)
    for(int i=0;i<vertices_number;i++)
      for(int j=0;j<vertices_number;j++)
        if(graph[i][j]!=INT_MAX && distance[j]>distance[i]+graph[i][j])
          distance[j]=distance[i]+graph[i][j];

  // CHECKING NEGATIVE CYCLE
  bool has_negative_cycle = false;
  for(int i=0;i<vertices_number;i++){
    for(int j=0;j<vertices_number;j++){
      if(graph[i][j]!=INT_MAX && distance[j]>distance[i]+graph[i][j]){
        distance[j]=distance[i]+graph[i][j];
        has_negative_cycle=true;
      }
    }
    if(has_negative_cycle)break;
  }

  cout<<endl;

  // DISPLAYING SHORTEST PATH FROM SOURCE VERTEX
  if(has_negative_cycle)cout<<"The Graph Contain Negative Cycle"<<endl;
  else{
    cout<<"Shortest Path From Source Vertex:"<<endl;
    for(int i=0;i<vertices_number;i++){
      cout<<"Vertex "<<i+1<<": ";
      (distance[i]==INT_MAX)?cout<<"INT_MAX"<<endl:cout<<distance[i]<<endl;
    }
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

  int source_vertex;
  cout<<"Enter Source Vertex: ";
  cin>>source_vertex;

  // DISPLAYING GIVEN GRAPH
  cout<<endl<<"Given Graph:"<<endl;
  for(int i=0;i<vertices;i++){
    for(int j=0;j<vertices;j++)
     (graph[i][j]==INT_MAX)?cout<<"I"<<" ":cout<<graph[i][j]<<" ";
    cout<<endl;
  }

  bellman_ford(graph, source_vertex);

  return 0;
}