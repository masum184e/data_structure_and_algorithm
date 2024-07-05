#include <bits/stdc++.h>
using namespace std;
#define int long long int

void dfs(int node, vector<int> adj[], vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited);
        }
    }
}

void count_connected_component(vector<int> adj[], int n){
    vector<bool> visited(n + 1, false);
    vector<int> roots;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            roots.push_back(i);
            dfs(i, adj, visited);
        }
    }
    
    cout << "Number of connected components: ";
    int sz = roots.size();
    if (sz == 1) {
        cout << "0" << endl;
    } else {
        cout << sz << endl;
        cout << "Root of each component: ";
        for (int i = 0; i < sz; i++) {
            cout << roots[i] << " ";
        }
        cout << endl;
    }
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
    
    count_connected_component(adj, n);
 
    return 0;
}
