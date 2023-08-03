#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
  // return (double)a.first/a.second>(double)b.first/b.second;
  return a.first*b.second>a.second*b.first;
}

void fractional_knapsack(vector<pair<int, int>> pairs, int knapsack_size){
  
  // SORTING BASED ON PROFIT/WEIGHT
  sort(pairs.begin(), pairs.end(), compare);

  double profit=0.0;
  int current_weight=0;

  cout<<endl;  
  for(int i=0;i<pairs.size();i++){
    if(current_weight+pairs[i].second<=knapsack_size){
      // CALCULATING FOR INTEGER
      current_weight+=pairs[i].second;
      profit+=pairs[i].first;
      cout<<"Selected Profit: "<<pairs[i].first<<" Weight: "<<pairs[i].second<<endl;
    }else{
      // CALCULATING FOR FRACTION
      double remaining_weight=knapsack_size-current_weight;
      if(remaining_weight!=0){
        profit+=((double)pairs[i].first/pairs[i].second)*remaining_weight;
        cout<<"Selected Profit: "<<(pairs[i].first/pairs[i].second)*remaining_weight<<" Weight: "<<remaining_weight<<endl;
      }
      break;
    }
  }

  cout<<"Total Profit: "<<profit<<endl;
}

int main(){
  int knapsack_size, number_of_item, profit, weight;
  vector<pair<int, int>> pairs;

  cout<<"Enter Number Of Item: ";
  cin>>number_of_item;

  for(int i=0;i<number_of_item;i++){
    cout<<"Enter "<<i+1<<"th Item Profit and Weight: ";
    cin>>profit>>weight;
    pairs.push_back(make_pair(profit, weight));
  }

  cout<<"Enter Knapsack Size: ";
  cin>>knapsack_size;

  fractional_knapsack(pairs, knapsack_size);
  return 0;
}