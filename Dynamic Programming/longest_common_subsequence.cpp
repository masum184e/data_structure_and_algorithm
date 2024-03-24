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
  for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
      if(str1[i-1]==str2[j-1]){
        arr[i][j]=arr[i-1][j-1]+1;
      }else{
        arr[i][j]=max(arr[i-1][j], arr[i][j-1]);
      }
  
  // Constructing the LCS string
  string lcs_string;
  int i=m,j=n;
  while(i>0 && j>0) {
      if(str1[i-1]==str2[j-1]){
        lcs_string=str1[i-1]+lcs_string;
        i--;
        j--;
      }else if(arr[i-1][j]>arr[i][j-1]){
        i--;
      }else {
        j--;
    }
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

int lcs_length_recursive(string str1, string str2, int m, int n){
  if(m==0 || n==0)return 0;
  else if(str1[m-1]==str2[n-1]){
    return 1+lcs_length_recursive(str1, str2, m-1, n-1);
  }
  else return max(lcs_length_recursive(str1, str2, m-1, n), lcs_length_recursive(str1, str2, m, n-1));
}

string lcs_string_recursive(string str1, string str2, int m, int n) {
    if (m == 0 || n == 0)
        return "";
    else if (str1[m - 1] == str2[n - 1]) {
        string lcs = lcs_string_recursive(str1, str2, m - 1, n - 1);
        return lcs + str1[m - 1];
    }
    else {
        string lcs1 = lcs_string_recursive(str1, str2, m - 1, n);
        string lcs2 = lcs_string_recursive(str1, str2, m, n - 1);
        return (lcs1.length() > lcs2.length()) ? lcs1 : lcs2;
    }
}

int main(){
  string str1,str2;
  cout<<"Enter Your First String: ";
  cin>>str1;
  cout<<"Enter Your Second String: ";
  cin>>str2;
  cout<<endl;

  pair<string, int> response = lcs_memoization(str1, str2);
  cout<<"LCS using Memoization Method :"<<response.first<<endl;
  cout<<"Length of LCS Using Memoization Method: "<<response.second<<endl;

  cout<<endl;

  cout<<"Length of LCS Using Recursion: "<<lcs_length_recursive(str1, str2, str1.length(), str2.length())<<endl;
  cout<<"LCS using Recursion: "<<lcs_string_recursive(str1, str2, str1.length(), str2.length())<<endl;
  
  return 0;
}