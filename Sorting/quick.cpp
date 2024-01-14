#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high){
    int pivot=arr[high];
    int i=low-1;

    for(int j=low;j<=high;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }

    swap(arr[i+1],arr[high]);
    return i+1;
}

void quick_sort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}

int main(){
  int size;

  cout<<"Enter Size of The Array: ";
  cin>>size;

  int arr[size];
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<size;i++)cin>>arr[i];

  quick_sort(arr, 0, size);

  // DISPLAYING SORTED ARRAY
  cout<<endl<<"Sorted Array:";
  for(int i=0;i<size;i++)cout<<" "<<arr[i];


  return 0;
}