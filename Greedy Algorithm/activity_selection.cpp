#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

void activity_selection(vector<pair<int, int>> pairs){
  
  // SORTING BASED ON ENDING TIME OF THE SEMINARS
  sort(pairs.begin(), pairs.end(), compare);

  // STORING SELECTED SEMINAR
  vector<pair<int, int>> selected_seminars;

  // SELECTING FIRST SEMINAR
  selected_seminars.push_back(pairs[0]);

  // SELECTION CALCULATION FOR OTHER SEMINAR
  for(int i=1;i<pairs.size();i++){
    if(pairs[i].first>=selected_seminars.back().second){
      //vector_name.back() METHOD IS USED TO ACCESS THE LAST ELEMENT OF THE VECTOR
      selected_seminars.push_back(pairs[i]);
    }
  }

  // DISPLAYING SELECTED SEMINARS
  cout << "Selected Seminars:" << endl;
  for (auto seminar : selected_seminars) {
      cout << "Start Time: " << seminar.first << ", End Time: " << seminar.second << endl;
  }
}

int main(){
  vector<pair<int, int>> pairs;
  int number_of_seminer, start, end;
  cout<<"Enter Number of Seminar: ";
  cin>>number_of_seminer;

  for(int i=0;i<number_of_seminer;i++){
    cout<<i+1<<"th Seminar Start and End Time: ";
    cin>>start>>end;
    pairs.push_back(make_pair(start,end));
  }

  activity_selection(pairs);

  return 0;
}