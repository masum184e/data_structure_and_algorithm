#include <bits/stdc++.h>
using namespace std;
#define ll long long int

double unimodal(double a, double b, double c, double x){
    return a*(x*x)+b*x+c;
}

double ternary_search_iterative(double a, double b, double c){
    double left=-1e5, right=1e5;
    while((right-left)>=1e-9){
        double mid1=left+(right-left)/3.0;
        double mid2=right-(right-left)/3.0;
        
        double f_mid1 = unimodal(a, b, c, mid1);
        double f_mid2 = unimodal(a, b, c, mid2);

        if(f_mid2>f_mid1)right=mid2;
        else if(f_mid2<f_mid1)left=mid1;
        else{
            left=mid1;
            right=mid2;
        }
    }

    return left;
}

double ternary_search_recursive(double a, double b, double c, double left, double right){
    if((right-left)<1e-9){
        return left;
    }

    double mid1=left+(right-left)/3.0;
    double mid2=right-(right-left)/3.0;
        
    double f_mid1 = unimodal(a, b, c, mid1);
    double f_mid2 = unimodal(a, b, c, mid2);

    if(f_mid1>f_mid2)return ternary_search_recursive(a, b, c, mid1, right);
    else return ternary_search_recursive(a, b, c, left, mid2);

}

int main(){
    double a,b,c;
    
    cout<<"Enter The Value Of a: ";cin>>a; 
    cout<<"Enter The Value Of b: ";cin>>b; 
    cout<<"Enter The Value Of c: ";cin>>c; 

    cout<<endl<<"Your Unimodal Equaton: "<<a<<"x^2"<<"+("<<b<<")x+"<<"("<<c<<")"<<endl<<endl;
    cout<<fixed<<setprecision(9)<<"Iterative Result: "<<ternary_search_iterative(a, b, c)<<endl;
    cout<<fixed<<setprecision(9)<<"Recursive Result: "<<ternary_search_recursive(a, b, c, -1e5, 1e5);

    return 0;
}