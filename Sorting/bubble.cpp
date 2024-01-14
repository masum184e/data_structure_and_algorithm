#include<bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int size){
  for(int i=0;i<size-1;i++){
    bool is_sorted = true;
    for(int j=0;j<size-i-1;j++){
      if(arr[j]>arr[j+1]){
        swap(arr[j], arr[j+1]);
        is_sorted=false
      }
    }
    if(is_sorted)break;
  }
}

// is_sorted IS USED FOR TRACKING THE GIVEN ARRAY IS ALREADY SORTED OR NOT
// IF THE GIVEN ARRAY IS ALREADY SORTED, THEN WE DON'T NEED TO SWAP
// IF AT ONE ITERATION NO SWAP IS OCCURED, THAT MEANS WE GOT OUR SORTED ARRAY

int main(){
  int size;

  cout<<"Enter Size of The Array: ";
  cin>>size;

  int arr[size];
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<size;i++)cin>>arr[i];

  bubble_sort(arr, size);

  // DISPLAYING SORTED ARRAY
  cout<<endl<<"Sorted Array:";
  for(int i=0;i<size;i++)cout<<" "<<arr[i];


  return 0;
}