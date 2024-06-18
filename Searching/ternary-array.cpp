#include<bits/stdc++.h>
using namespace std;

int ternary_search_iterative(int arr[], int left, int right, int search_item){
  while(left<=right){
    int mid1=left+(right-left)/3;
    int mid2=right-(right-left)/3;

    if(arr[mid1]==search_item)return mid1;
    if(arr[mid2]==search_item)return mid2;

    if(arr[mid1]>search_item)right=mid1-1;
    else if(arr[mid2]<search_item)left=mid2+1;
    else{
        left=mid1+1;
        right=mid2-1;
    }
  }

  return -1;
}

int ternary_search_recursive(int arr[], int left, int right, int search_item){
  if(right>=left){
    int mid1=left+(right-left)/3;
    int mid2=right-(right-left)/3;

    if(arr[mid1]==search_item)return mid1;
    if(arr[mid2]==search_item)return mid2;

    if(arr[mid1]>search_item)return ternary_search_recursive(arr, left, mid1-1, search_item);
    else if(arr[mid2]<search_item)return ternary_search_recursive(arr, mid2+1, right, search_item);
    else return ternary_search_recursive(arr, mid1+1, mid2-1, search_item);
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

  found_status=ternary_search_iterative(arr, 0, size-1, search_item);
  cout<<"Iterative Search Result: "<<found_status<<endl;

  found_status=ternary_search_recursive(arr, 0, size-1, search_item);
  cout<<"Recursive Search Result: "<<found_status<<endl;

  return 0;
}