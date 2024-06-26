#include <bits/stdc++.h>
using namespace std;
#define ll long long int

void buildTree(vector<int> &tree, vector<int> &arr, int node, int start, int end) {
    if (start == end) {
        tree[node] = arr[start];
        return;
    } else {
        int mid = (start + end) / 2;
        buildTree(tree, arr, 2 * node + 1, start, mid);
        buildTree(tree, arr, 2 * node + 2, mid + 1, end);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

void updateTree(vector<int> &tree, vector<int> &arr, int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        tree[node] = val;
    } else {
        int mid = (start + end) / 2;
        if (start <= idx && idx <= mid) {
            updateTree(tree, arr, 2 * node + 1, start, mid, idx, val);
        } else {
            updateTree(tree, arr, 2 * node + 2, mid + 1, end, idx, val);
        }
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }
}

int queryTree(vector<int> &tree, int node, int start, int end, int L, int R) {
    // NON OVERLAP
    if (R < start || end < L)return 0;

    // COMPLETE OVERLAP
    if (L <= start && end <= R)return tree[node];
    
    // PARTIAL OVERLAP
    int mid = (start + end) / 2;
    int p1 = queryTree(tree, 2 * node + 1, start, mid, L, R);
    int p2 = queryTree(tree, 2 * node + 2, mid + 1, end, L, R);
    return p1 + p2;
}

int main(){
  int size;

  cout<<"Enter Size of The Array: ";
  cin>>size;

  vector<int> arr(size);
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<size;i++)cin>>arr[i];

  vector<int> tree(4 * size);
  buildTree(tree, arr, 0, 0, size - 1);

   cout << "Sum of values in [1, 3] range = " << queryTree(tree, 0, 0, size - 1, 1, 3) << endl;
   
   // Update the value at index 1
    updateTree(tree, arr, 0, 0, size - 1, 1, 10);

    // Query the sum of values in range [1, 3] after the update
    cout << "Updated sum of values in given range = " << queryTree(tree, 0, 0, size - 1, 1, 3) << endl;


  return 0;
}