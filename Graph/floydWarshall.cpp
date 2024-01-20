#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void floydWarshall(vector<vector<ll>> graph){
    ll vertices=graph.size();

    for(ll k=0;k<vertices;k++){
        for(ll i=0;i<vertices;i++){
            for(ll j=0;j<vertices;j++){
                if(graph[i][k]!=INT_MAX && graph[k][j]!=INT_MAX && graph[i][k]+graph[k][j] < graph[i][j]){
                    graph[i][j]=graph[i][k] + graph[k][j];
                }
            }
        }
    }

    // DISPLAYING SHORTEST PATH
    cout<<endl<<"Shortest Path Between Pair Of Vertices:"<<endl;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++)
        (graph[i][j]==INT_MAX)?cout<<"I"<<" ":cout<<graph[i][j]<<" ";
        cout<<endl;
    }

}

int main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);
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

    // DISPLAYING GIVEN GRAPH
    cout<<endl<<"Given Graph:"<<endl;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++)
        (graph[i][j]==INT_MAX)?cout<<"I"<<" ":cout<<graph[i][j]<<" ";
        cout<<endl;
    }

    floydWarshall(graph);

    return 0;
}