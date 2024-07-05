#include <bits/stdc++.h>
using namespace std;
#define int long long int

void bfs(int start, vector<int> adj[], vector<bool>& visited, vector<int>& parent) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
                parent[neighbor] = node;
            }
        }
    }
}

void printShortestPath(const vector<int>& parent, int dest) {
    if (parent[dest]==-1){
        cout<<dest;
        return;
    }
    printShortestPath(parent, parent[dest]);
    cout<<" -> "<<dest;
}

int32_t main() {
    int n, m;
    cout << "Enter Number of Vertices and Edges: ";
    cin >> n >> m;

    vector<int> adj[n + 1];
    for (int i = 0; i < m; i++) {
        cout<<i+1<<"th edge: ";
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> parent(n+1, -1);
    vector<bool> visited(n+1, false);
    int root=1;

    bfs(root,adj,visited,parent);

    cout<<endl;
    for(int i=1;i<=n;i++) {
        if (i!=root) {
            cout<<"Shortest path from "<<root<<" to "<<i<<": ";
            printShortestPath(parent, i);
            cout<<endl;
        }
    }
    
 
    return 0;
}