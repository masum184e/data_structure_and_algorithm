#include <bits/stdc++.h>
using namespace std;
#define int long long int

pair<int, int> binary2D_iterative(vector<vector<int>> mat, int item){
    int row, col, left, right, mid, midElement;
    row=mat.size(), col=mat[0].size(),left=0, right=row*col-1;

    while(left<=right){
        mid=left+(right-left)/2;
        
        midElement=mat[mid/col][mid%col];
        if(midElement==item)return {mid/col, mid%col};
        else if(midElement<item)left=mid+1;
        else if(midElement>item)right=mid-1;

    }

    return {-1, -1};
}

int32_t main(){
    // ios_base::sync_with_stdio(false);cin.tie(NULL);

    int row, col, search_item;
    cout<<"Enter Number of Row    : ";cin>>row;
    cout<<"Enter Number of Column : ";cin>>col;
    vector<vector<int>> mat(row,vector<int>(col));

    cout<<"Enter The Elements of The Array: ";
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            cin>>mat[i][j];
    
    cout<<"Enter Search Element From The Array: ";
    cin>>search_item;

    pair<int, int> found=binary2D_iterative(mat, search_item);
    cout<<search_item<<" found at row "<<found.first<<" column "<<found.second<<endl;

    return 0;
}