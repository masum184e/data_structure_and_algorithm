#include <bits/stdc++.h>
using namespace std;

pair<string, int> lcs_memoization(string str1, string str2){

  // LENGTH OF EACH STRING
  int m,n;
  m=str1.length();
  n=str2.length();
  
  // MEMOIZATION ARRAY
  int arr[m+1][n+1];

  // INITIALIZING THE ARRAY WITH ZEROS
  for(int i=0;i<=m;i++)
    for(int j=0;j<=n;j++)
      arr[i][j]=0;

  // FILLING THE MEMOIZATOIN ARRAY WITH BOTTOM UP APPROACH AND GETTING THE LCS
  string lcs_string;
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
      if(str1[i-1]==str2[j-1]){
        lcs_string.push_back(str1[i-1]);
        arr[i][j]=arr[i-1][j-1]+1;
      }else{
        arr[i][j]=max(arr[i-1][j], arr[i][j-1]);
      }

  // DISPLAYING THE MEMOIZATION ARRAY
  cout<<"Memoization Table:"<<endl;
  for(int i=0;i<=m;i++){
    for(int j=0;j<=n;j++)cout<<arr[i][j]<<" ";
    cout<<endl;
  }

  // LCS AND LENGTH OF LCS
  return make_pair(lcs_string, arr[m][n]);
}

int lcs_recursive(string str1, string str2, int m, int n, string lcs_string){
  if(m==0 || n==0)return 0;
  else if(str1[m-1]==str2[n-1]){
    lcs_string+=str1[m-1];
    return 1+lcs_recursive(str1, str2, m-1, n-1, lcs_string);
  }
  else return max(lcs_recursive(str1, str2, m-1, n, lcs_string), lcs_recursive(str1, str2, m, n-1, lcs_string));
}

int main(){
  string str1,str2;
  cout<<"Enter Your First String: ";
  cin>>str1;
  cout<<"Enter Your Second String: ";
  cin>>str2;
  cout<<endl;

  pair<string, int> response = lcs_memoization(str1, str2);
  cout<<"Length of LCS Using Memoization Method: "<<response.first<<endl;
  cout<<"LCS using Memoization Method :"<<response.second<<endl;

  cout<<endl;

  string lcs_string="";
  cout<<"Length of LCS Using Recursion: "<<lcs_recursive(str1, str2, str1.length(), str2.length(), lcs_string)<<endl;
  cout<<"LCS using Recursion: "<<lcs_string<<endl;
  return 0;
}