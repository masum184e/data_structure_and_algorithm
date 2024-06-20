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

void updateRange(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int L, int R, int val) {
    // NON OVERLAP
    if (start > end || start > R || end < L) return;

    // COMPLETE OVERLAP
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];

        if (start != end) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (start >= L && end <= R) {
        tree[node] += (end - start + 1) * val;

        if (start != end) {
            lazy[2 * node + 1] += val;
            lazy[2 * node + 2] += val;
        }

        return;
    }

    // PARTIAL OVERLAP
    int mid = (start + end) / 2;
    updateRange(tree, lazy, 2 * node + 1, start, mid, L, R, val);
    updateRange(tree, lazy, 2 * node + 2, mid + 1, end, L, R, val);

    tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    return;
}

int queryRange(vector<int> &tree, vector<int> &lazy, int node, int start, int end, int L, int R) {
    // NON OVERLAP
    if (start > end || start > R || end < L) return 0;

    // COMPLETE OVERLAP
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];

        if (start != end) {
            lazy[2 * node + 1] += lazy[node];
            lazy[2 * node + 2] += lazy[node];
        }

        lazy[node] = 0;
    }

    if (start >= L && end <= R) return tree[node];

    // PARTIAL OVERLAP
    int mid = (start + end) / 2;
    int p1 = queryRange(tree, lazy, 2 * node + 1, start, mid, L, R);
    int p2 = queryRange(tree, lazy, 2 * node + 2, mid + 1, end, L, R);

    return p1 + p2;
}

int main() {
    int size;

    cout << "Enter Size of The Array: ";
    cin >> size;

    vector<int> arr(size);
    cout << "Enter The Elements of The Array: ";
    for (int i = 0; i < size; i++) cin >> arr[i];

    vector<int> tree(4 * size);
    vector<int> lazy(4 * size, 0);
    buildTree(tree, arr, 0, 0, size - 1);

    cout << "Sum of values in [1, 3] range = " << queryRange(tree, lazy, 0, 0, size - 1, 1, 3) << endl;

    // Update the values in range [1, 3] by adding 10
    updateRange(tree, lazy, 0, 0, size - 1, 1, 3, 10);

    // Query the sum of values in range [1, 3] after the update
    cout << "Updated sum of values in given range = " << queryRange(tree, lazy, 0, 0, size - 1, 1, 3) << endl;

    return 0;
}
