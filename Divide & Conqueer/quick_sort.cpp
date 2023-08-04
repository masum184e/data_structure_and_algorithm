#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
  int pivot, index;
  pivot=arr[high];
  index=low-1;

  for(int j=low;j<high;j++)
    if(arr[j]<=pivot){
      index++;
      swap(arr[index], arr[j]);
    }
  swap(arr[index+1], arr[high]);
  return index+1;
}

void quick_sort(int arr[], int low, int high){
  if(low<high){
    int pivot_index;
    pivot_index=partition(arr, low, high);
    quick_sort(arr, low, pivot_index-1);
    quick_sort(arr, pivot_index+1, high);
  }
}
int main(){
  int number_of_item, start, end;

  cout<<"Enter Size of The Array: ";
  cin>>number_of_item;

  int arr[number_of_item];
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<number_of_item;i++)cin>>arr[i];

  cout<<"Enter The Begining And Ending Index: ";
  cin>>start>>end;

  quick_sort(arr, start, end);

  cout<<endl<<"Sorted Array:";
  for(int i=0;i<number_of_item;i++)cout<<" "<<arr[i];
  
  return 0;
}