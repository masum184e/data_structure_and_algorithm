#include<bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int size, int search_item){
  for(int i=0;i<size;i+++)
    if(arr[i]==search_item)return i;
  
  return -1;
}

int main(){
  int size, found_status, search_item;

  cout<<"Enter Size of The Array: ";
  cin>>size;

  int arr[size];
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<size;i++)cin>>arr[i];

  found_status=linear_search(arr, size, search_item);
  cout<<found_status<<endl;

  return 0;
}