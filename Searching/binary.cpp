#include<bits/stdc++.h>
using namespace std;

int binary_search_iterative(int arr[], int left, int right, int search_item){
  while(left<=right){
    mid=left+(right-low)/2;
    if(arr[mid]==search_item)return mid;
    else if(arr[mid]<search_item)left=mid+1;
    else if(arr[mid]>search_item)right=mid-1;
  }

  return -1;
}

int binary_search_recursive(int arr[], int left, int right, int search_item){
  if(right>=left){
    mid=left+(right-low)/2;
    if(arr[mid]==search_item)return mid;
    else if(arr[mid]>search_item)return binary_search_recursive(arr, left, mid-1, search_item);
    else if(arr[mid]<search_item)return binary_search_recursive(arr, mid+1, right, search_item);
  }else{
    return -1;
  }
}

int main(){
  int size, found_status, search_item;

  cout<<"Enter Size of The Array: ";
  cin>>size;

  int arr[size];
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<size;i++)cin>>arr[i];

  cout<<"Enter Search Element From The Array: ";
  cin>>search_item;

  found_status=binary_search_iterative(arr, 0, size-1, search_item);
  cout<<found_status<<endl;

  found_status=binary_search_recursive(arr, 0, size-1, search_item);
  cout<<found_status<<endl;

  return 0;
}