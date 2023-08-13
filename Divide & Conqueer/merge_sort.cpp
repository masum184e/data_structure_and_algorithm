#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int start, int mid, int end){
  int left_arr_size, right_arr_size;

  left_arr_size=mid-start+1;
  right_arr_size=end-mid;

  int left_arr[left_arr_size], right_arr[right_arr_size];

  for(int i=0;i<left_arr_size;i++)
    left_arr[i]=arr[start+i];

  for(int i=0;i<right_arr_size;i++)
    right_arr[i]=arr[mid+1+i];
  
  int i,j,k;
  i=j=0;
  k=start;

  // OPTIMAL MERGE PATTERN
  while(i<left_arr_size && j<right_arr_size){
    if(left_arr[i]<=right_arr[j]){
      arr[k]=left_arr[i];
      i++;
    }else{
      arr[k]=right_arr[j];
      j++;
    }
    k++;
  }

  // FOR REMAING ITEM
  while(i<left_arr_size){
    arr[k]=left_arr[i];
    i++;
    k++;
  }
  while(j<right_arr_size){
    arr[k]=right_arr[j];
    j++;
    k++;
  }
}

void merge_sort(int arr[], int start, int end){
    if(start>=end)return;

    int mid=start+(end-start)/2;

    merge_sort(arr, start, mid);
    merge_sort(arr, mid+1, end);

    merge(arr, start, mid, end);
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

  merge_sort(arr, start, end);

  cout<<endl<<"Sorted Array:";
  for(int i=0;i<number_of_item;i++)cout<<" "<<arr[i];
  
  return 0;
}