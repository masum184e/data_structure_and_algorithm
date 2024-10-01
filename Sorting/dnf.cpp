#include<bits/stdc++.h>
using namespace std;

void dnf(vector<int>& nums) {
    int zero, one, two;
    zero = one = 0;
    two = nums.size() - 1;

    while(one<=two){
        if(nums[one]==0){
            swap(nums[one], nums[zero]);
            one++;
            zero++;
        }else if(nums[one]==1){
            one++;
        }else if(nums[one]==2){
            swap(nums[one], nums[two]);
            two--;
        }
    }

}

int main(){
  int size;

  cout<<"Enter Size of The Array: ";
  cin>>size;

  vector<int> arr(size);
  cout<<"Enter The Elements of The Array: ";
  for(int i=0;i<size;i++)cin>>arr[i];

  dnf(arr);

  // DISPLAYING SORTED ARRAY
  cout<<endl<<"Dutch National Flag:";
  for(int i=0;i<size;i++)cout<<" "<<arr[i];

  return 0;
}