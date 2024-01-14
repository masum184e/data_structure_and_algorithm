#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right){
    int i,j,k,size_l,size_r;

    size_l=mid-left+1;
    size_r=right-mid;

    int L[size_l],R[size_r];

    for(i=0;i<size_l;i++)L[i]=arr[left+i];
    for(j=0;j<size_r;j++)R[j]=arr[mid+1+j];

    i=0;
    j=0;
    k=left;

    while(i<size_l && j<size_r){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }

    while(i<size_l){
        arr[k]=L[i];
        i++;
        k++;
    }

    while(j<size_r){
        arr[k]=R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int left, int right){
    if(left>=right)return;

    int mid=left+(right-left)/2;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);

    merge(arr,left,mid,right);
}

int main(){
  int size;

  cout<<"Enter Size of The Array: ";
  cin>>size;

  int arr[size];
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<size;i++)cin>>arr[i];

  merge_sort(arr, 0, size);

  // DISPLAYING SORTED ARRAY
  cout<<endl<<"Sorted Array:";
  for(int i=0;i<size;i++)cout<<" "<<arr[i];

  return 0;
}