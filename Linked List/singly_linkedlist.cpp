#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

Node* insertAtEnd(Node* head, int data){
    Node* newNode = createNode(data);
    
    if (head == nullptr) {
        return newNode;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
    return head;
}

Node* insertAtBeginning(Node* head, int data){
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

void displayList(Node* head){
    Node* temp = head;
    
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int32_t main(){

    Node* head = nullptr;
    
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtBeginning(head, 5);
    displayList(head);

    return 0;
}