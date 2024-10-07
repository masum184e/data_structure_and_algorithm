#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define MAX_SIZE 100

int stack[MAX_SIZE];
int top=-1;

int isFull(){
    return top==MAX_SIZE-1;
}

int isEmpty(){
    return top==-1;
}

void push(int data){
    (isFull())?cout<<"Stack Overflow"<<endl:stack[++top]=data;
}

int pop(){
    return (isEmpty())?-1:stack[top--];
}

int32_t main(){


    return 0;
}