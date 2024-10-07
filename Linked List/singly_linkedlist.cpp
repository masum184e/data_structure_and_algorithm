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

Node* removeHead(Node* head){
    if(head==nullptr)head;

    Node* temp=head;
    head=head->next;
    delete temp;
}

Node* removeLastNode(Node* head){
    if(head==nullptr)head;
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return head;
    }

    Node* temp=head;
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }

    delete temp->next;
    temp->next=nullptr;

    return head;
}

Node* removeAtPosition(Node* head, int index){
    if(head==nullptr)return head;
    if(index==0)return removeHead(head);

    Node* temp=head;
    while (index-- && temp->next != nullptr) {
        temp = temp->next;
    }

    if (temp == nullptr || temp->next == nullptr) return head;

    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    delete nodeToDelete;

    return head;
}

void displayList(Node* head){
    Node* temp = head;
    
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void displayListRecursive(Node* head){
    if(head==nullptr){
        cout << "NULL" << endl;
        return;
    }
    cout<<head->data<<" -> ";
    displayListRecursive(head->next);
}

int32_t main(){

    Node* head = nullptr;
    
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtBeginning(head, 5);
    displayList(head);
    displayListRecursive(head);

    return 0;
}