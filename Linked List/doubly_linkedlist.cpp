#include <bits/stdc++.h>
using namespace std;
#define int long long int

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
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
    newNode->prev = temp;

    return head;
}

Node* insertAtBeginning(Node* head, int data){
    Node* newNode = createNode(data);

    newNode->next = head;
    head->prev = newNode;

    return newNode;
}

Node* insertAtIndex(Node* head, int data, int index){
    if(index<0){
        cout<<"Invalid index."<<endl;
        return head;
    }

    if(index==0)
        return insertAtBeginning(head, data);

    Node* newNode=createNode(data);
    Node* temp = head;
    while (index-- && temp->next != nullptr) {
        temp = temp->next;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;

    return head;
}

Node* removeHead(Node* head){
    if(head==nullptr)return head;

    Node* temp=head;
    head=head->next;

    if (head != nullptr) {
        head->prev = nullptr;
    }

    delete temp;

    return head;
}

Node* removeLastNode(Node* head){
    if(head==nullptr)head;
    if(head->next==nullptr){
        delete head;
        head=nullptr;
        return head;
    }

    Node* temp=head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }

    temp->prev->next = nullptr;
    delete temp;

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

    if (temp->next != nullptr) {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != nullptr) {
        temp->prev->next = temp->next;
    }

    delete temp;

    return head;
}

Node* reverseDLL(Node* head){
    if(head==nullptr)return nullptr;

    Node* temp = nullptr;
    Node* current = head;
    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }    

    if(temp!=nullptr)head=temp->prev;

    return head;
}

void displayForward(Node* head){
    Node* temp = head;
    
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void displayBackward(Node* head){
    if (head == nullptr) return;

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int32_t main(){

    Node* head = nullptr;
    
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtBeginning(head, 5);

    cout<<"Display Forward  : ";displayForward(head);
    cout<<"Display Backward : ";displayBackward(head);

    return 0;
}