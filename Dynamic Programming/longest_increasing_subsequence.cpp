#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int lis(vector<int> sequence){
    int sequence_size=sequence.size();
    vector<int> dp(sequence_size, 1);
    vector<int> prev(sequence_size, -1);

    for(int i=1;i<sequence_size;i++){
        for(int j=0;j<i;j++){
            if(sequence[i]>sequence[j]){
                dp[i]=max(dp[i], 1+dp[j]);
                prev[i] = j;
            }
        }
    }

    int lis_end_index = max_element(dp.begin(), dp.end()) - dp.begin();
    vector<int> lis_list;
    while (lis_end_index != -1) {
        lis_list.push_back(sequence[lis_end_index]);
        lis_end_index = prev[lis_end_index];
    }
    reverse(lis_list.begin(), lis_list.end());
    cout<<"LIS:";
    for(auto i:lis_list)cout<<" "<<i;
    cout<<endl;

    return*max_element(dp.begin(), dp.end());
}

int main(){

    int sequence_size;
    cout<<"Enter Sequence Size: ";
    cin>>sequence_size;

    cout<<"Enter Sequence Value: ";
    vector<int> sequence(sequence_size);
    for(int i=0;i<sequence_size;i++)cin>>sequence[i];

    cout<<"Length of LIS: "<<lis(sequence)<<endl;

    return 0;
}