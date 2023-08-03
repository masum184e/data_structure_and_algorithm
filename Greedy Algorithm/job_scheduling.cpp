#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.first > b.first;
}

void job_scheduling(vector<pair<int, int>> pairs){

  // SORTING BASED ON PROFIT
  sort(pairs.begin(), pairs.end(), compare);

  // MAXIMUM DEADLINE
  int mx=pairs[0].second;
  for(int i=1;i<pairs.size();i++)mx=max(mx, pairs[i].second);

  // SELECTING JOB
  vector<pair<pair<int, int>, bool>> seleected;
  for(int i=0;i<=mx;i++)seleected.push_back(make_pair(make_pair(-1, -1), false));

  for(int i=0;i<pairs.size();i++){
    int target_slot=pairs[i].second;
      while(target_slot>0 && seleected[target_slot].second)target_slot--;
      if(target_slot>0)seleected[target_slot]=make_pair(make_pair(pairs[i].first, pairs[i].second), true);
  }

  cout<<endl;

  // DISPLAYING SELECTED JOB AND CALCULATING TOTAL PROFIT
  cout<<"Selected Profit And Deadline:"<<endl;
  int total_profit=0;
  for(int i=1;i<=mx;i++){
    if(seleected[i].second){
      pair<int, int> item = seleected[i].first;
      cout<<item.first<<" "<<item.second<<endl;
      total_profit+=item.first;
    }
  }
  cout<<endl<<"Total Profit: "<<total_profit<<endl;
}

int main(){
  int number_of_item, profit, deadline;
  vector<pair<int, int>> pairs;

  cout<<"Enter Number Of Item: ";
  cin>>number_of_item;

  for(int i=0;i<number_of_item;i++){
    cout<<"Enter "<<i+1<<"th Item Profit and Deadline: ";
    cin>>profit>>deadline;
    pairs.push_back(make_pair(profit, deadline));
  }

  job_scheduling(pairs);

  return 0;
}