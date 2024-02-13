#include <bits/stdc++.h>
using namespace std;

void zero_one_knapsack(vector<pair<int, int>> pairs, int knapsack_size){
  // MEMOIZATION ARRAY
  int arr[pairs.size()+1][knapsack_size+1];

  // FILLING THE MEMOIZATOIN ARRAY WITH BOTTOM UP APPROACH
  for(int i=0;i<=pairs.size();i++){
    for(int j=0;j<=knapsack_size;j++){
      if(i==0 || j==0)arr[i][j]=0;
      else if(pairs[i-1].second<=j){
        arr[i][j]=max(arr[i-1][j],pairs[i-1].first+arr[i-1][j-pairs[i-1].second]);
      }else{
        arr[i][j]=arr[i-1][j];
      }
    }
  }

  // GETTING SELECTED ITEM
  int i,j;
  i=pairs.size();
  j=knapsack_size;
  vector<bool> selected;
  while(i>0 && j>0){
    if(arr[i][j]!=arr[i-1][j]){
      selected.push_back(true);
      j-=pairs[i-1].second;
    }else{
      selected.push_back(false);
    }
    i--;
  }
  reverse(selected.begin(), selected.end());

  cout<<endl;

  // DISPLAYING THE MEMOIZATION ARRAY
  cout<<"Memoization Table:"<<endl;
  for(int i=0;i<=pairs.size();i++){
    for(int j=0;j<=knapsack_size;j++)cout<<arr[i][j]<<" ";
    cout<<endl;
  }

  cout<<endl;

  // DISPLAYING SELECTED ITEM
  cout<<"Selected Items:";
  for(int i=0;i<selected.size();i++)
    if(selected[i])
        cout<<" "<<i+1;

  cout<<endl;

  // DISPLAYING SELECTED ITEM PAIR WISE
  cout<<"Selected Pairs:"<<endl;
  i=0;
  for(auto j: selected){
    if(j==1){
      cout<<pairs[i].first<<" "<<pairs[i].second<<endl;;
    }
    i++;
  }
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


  zero_one_knapsack(pairs, knapsack_size);

  return 0;
}