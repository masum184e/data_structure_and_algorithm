#include <bits/stdc++.h>
using namespace std;
#define ll long long int

vector<vector<int>> primsMST(vector<vector<int>> edge_list, int vertices, int src){
    vector<vector<pair<int, int>>> adj(vertices);
    for (auto edge : edge_list) {
        int from=edge[0], to=edge[1], weight=edge[2];
        adj[from].push_back({to, weight});
        adj[to].push_back({from, weight});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<bool> visited(vertices, false);
    vector<int> parent(vertices, -1);
    vector<int> key(vertices, INT_MAX);
    vector<vector<int>> mst;

    pq.push({0, src});
    key[src]=0;

    while(!pq.empty()){
        int u=pq.top().second;
        pq.pop();
        visited[u]=true;

        for (auto neighbor:adj[u]) {
            int v=neighbor.first;
            int weight=neighbor.second;
            if (!visited[v] && weight<key[v]) {
                parent[v]=u;
                key[v]=weight;
                pq.push({key[v],v});
            }
        }
    }

    for (int i=1;i<vertices;i++)mst.push_back({parent[i],i,key[i]});

    return mst;
}

int main(){

    int vertices, edges;
    cout<<"Enter Number of Vertices and Edges: ";
    cin>>vertices>>edges;

    vector<vector<int>> edge_list;
    for(int i=0;i<edges;i++){
        int from, to, weight;
        cout<<"Enter "<<i<<"th edges index and weight: ";
        cin>>from>>to>>weight;
        edge_list.push_back({from, to, weight});
    }

    int src;
    cout<<"Enter Source Vertice Index: ";cin>>src;

    vector<vector<int>> mst = primsMST(edge_list, vertices, src);

    cout<<endl<<"Edges in MST:"<<endl;
    for(vector<int> edge: mst)cout<<edge[0]<<" "<<edge[1]<<" "<<edge[2]<<endl;

    int sum=0;
    for(vector<int> edge: mst)sum+=edge[2];
    cout<<endl<<"Cost of MST: "<<sum<<endl;

    return 0;
}