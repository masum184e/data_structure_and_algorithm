#include<bits/stdc++.h>
using namespace std;

void count_sort(vector<int>& arr, int size){
    int mx = *max_element(arr.begin(), arr.end());

    vector<int> count(mx+1, 0);
    for(int i=0;i<size;i++)count[arr[i]]++;

    for(int i=1;i<=mx;i++)count[i] += count[i-1];

    vector<int> output(size);
    for(int i=size-1;i>=0;i--){
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }

    arr = output;
}

int main(){
  int size;

  cout<<"Enter Size of The Array: ";
  cin>>size;

  vector<int> arr(size);
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<size;i++)cin>>arr[i];

  count_sort(arr, size);

  // DISPLAYING SORTED ARRAY
  cout<<endl<<"Sorted Array:";
  for(int i=0;i<size;i++)cout<<" "<<arr[i];

  return 0;
}