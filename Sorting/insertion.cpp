#include<bits/stdc++.h>
using namespace std;

void recursive_insertion_sort(int arr[], int size){
  if(size<=1)return;

  recursive_insertion_sort(arr, size-1);
  int item,j;
  item=arr[size-1];
  j=size-2;

  while(j>=0 && arr[j]>item){
    arr[j+1]=arr[j];
    j--;
  }
  arr[j+1]=item;
}

void insertion_sort(int arr[], int size){
  for(int i=1;i<size;i++){
    int item,j;

    item=arr[i];
    j=i-1;

    while(j>=0 && arr[j]>item){
      arr[j+1]=arr[j];
      j=j-1;
    }
    arr[j+1]=item;
  }

}

int main(){
  int size;

  cout<<"Enter Size of The Array: ";
  cin>>size;

  int arr[size];
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<size;i++)cin>>arr[i];

  insertion_sort(arr, size);

  // DISPLAYING SORTED ARRAY
  cout<<endl<<"Sorted Array:";
  for(int i=0;i<size;i++)cout<<" "<<arr[i];


  return 0;
}