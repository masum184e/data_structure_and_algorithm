#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Node* insert(Node* root, int data){
    if(root == nullptr)return createNode(data);

    if(data < root->data)root->left = insert(root->left, data);
    else root->right = insert(root->right, data);

    return root;
}

void inorder(Node* root){
    if(root == nullptr)return;
    inorder(root->left);
    cout << root->data <<" ";
    inorder(root->right);
}

void preorder(Node* root){
    if(root == nullptr)return;
    cout << root->data <<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root){
    if(root == nullptr)return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data <<" ";
}

int32_t main(){

    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;


    return 0;
}