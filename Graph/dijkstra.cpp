#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void printShortestPath(const vector<ll>& parent, ll dest) {
    if (parent[dest]==-1){
        cout<<dest;
        return;
    }
    printShortestPath(parent, parent[dest]);
    cout<<" -> "<<dest;
}

void dijkstra(vector<vector<ll>> graph, ll source){
    ll vertices=graph.size();

    set<pair<ll,ll>> pq;
    vector<ll> distance(vertices,LLONG_MAX);
    vector<ll> parent(vertices, -1);

    pq.insert({0,source});
    distance[source]=0;

    while(!pq.empty()){
        auto it=pq.begin();
        ll node=it->second;
        ll nodeDist=it->first;

        pq.erase(it);

        for(ll i=0;i<vertices;i++){
            if(graph[node][i]!=INT_MAX && distance[node]+graph[node][i]<distance[i]){
                pq.erase({distance[i],i});
                distance[i]=distance[node]+graph[node][i];
                pq.insert({distance[i],i});
                parent[i]=node;
            }
        }
    }

    cout<<endl<<"Minimum Distances From Source Node "<<source<<":"<<endl;
    for(ll i=0;i<vertices;i++){
        if(distance[i]==LLONG_MAX){
            cout<<"Vertex "<<i<<": Not Reachable"<<endl;
        }else{
            cout<<"Vertex "<<i<<": "<<distance[i]<<" Path: ";
            printShortestPath(parent, i);
            cout<<endl;
        }
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
        graph[to][from]=weight;
    }

    int source;
    cout<<"Enter Source Vertex: ";
    cin>>source;

    // DISPLAYING GIVEN GRAPH
    cout<<endl<<"Given Graph:"<<endl;
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++)
        (graph[i][j]==INT_MAX)?cout<<"I"<<" ":cout<<graph[i][j]<<" ";
        cout<<endl;
    }

    dijkstra(graph,source);

    return 0;
}