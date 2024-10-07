#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MAX_SIZE 100

int queue[MAX];
int front = -1;
int rear = -1;

bool isFull(){
    return rear==MAX_SIZE-1;
}

bool isEmpty(){
    return front==-1 || front>rear;
}

void enqueue(int data){
    if(isFull())cout<<"Queue Overflow"<<endl;
    else{
        if(front==-1)front=0;
        queue[++rear]=data;
    }
}

int dequeue(){
    if(isEmpty())return -1;
    else{
        int delItem=queue[front++];
        if(front>rear){
            front--;
            rear--;
        }
        return delItem;
    }
}

int32_t main(){



    return 0;
}