#include<bits/stdc++.h>
using namespace std;

void selection_sort(int arr[], int size){
  for(int i=0;i<size-1;i++){
    int min_index = i;
    for(int j=i+1;j<size;j++)
      if(arr[j]<arr[min_index])
        min_index=j;
    if(min_index!=i)
      swap(arr[min_index], arr[i]);
  }
}

int main(){
  int size;

  cout<<"Enter Size of The Array: ";
  cin>>size;

  int arr[size];
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<size;i++)cin>>arr[i];

  selection_sort(arr, size);

  // DISPLAYING SORTED ARRAY
  cout<<endl<<"Sorted Array:";
  for(int i=0;i<size;i++)cout<<" "<<arr[i];


  return 0;
}