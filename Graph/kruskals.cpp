#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int findParent(vector<int>& parent, int i){
    if(parent[i]==i)return i;
    return parent[i]=findParent(parent, parent[i]);
}

void unionSet(vector<int>& parent, vector<int>& rank, int u, int v){
    int uParent=findParent(parent, u);
    int vParent=findParent(parent, v);

    if(rank[uParent]>rank[vParent]) parent[vParent]=uParent;
    else if(rank[uParent]<rank[vParent]) parent[uParent]=vParent;
    else{
        parent[uParent]=vParent;
        rank[vParent]++;
    }
}

bool compare(const vector<int> a, const vector<int> b) {
    return a[2] < b[2];
}

vector<vector<int>> kruskalMST(vector<vector<int>> edge_list, int vertices){
    vector<int> parent(vertices);
    vector<int> rank(vertices, 0);

    for(int i=0;i<vertices;i++)parent[i]=i;
    sort(edge_list.begin(), edge_list.end(), compare);

    vector<vector<int>> mst;
    for(vector<int> edge: edge_list){
        int u=edge[0];
        int v=edge[1];
        int weight=edge[2];

        if(findParent(parent,u)!=findParent(parent,v)){
            mst.push_back(edge);
            unionSet(parent, rank,u,v);
        }
    }

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

    vector<vector<int>> mst = kruskalMST(edge_list, vertices);

    cout<<endl<<"Edges in MST:"<<endl;
    for(vector<int> edge: mst)cout<<edge[0]<<" "<<edge[1]<<" "<<edge[2]<<endl;

    int sum=0;
    for(vector<int> edge: mst)sum+=edge[2];
    cout<<endl<<"Cost of MST: "<<sum<<endl;

    return 0;
}