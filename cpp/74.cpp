#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n,t;
    cin>>m>>n>>t;
    int a[m][n];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int mid=0,l1=0,l2=0,r1=m-1,r2=n-1;
    int row=0;
    //先找行
    while(l1<=r1){
        mid=(l1+r1)/2;
        if(a[mid][0]<=t){
            row=max(row,mid);
            l1=mid+1;
        }else {
            r1=mid-1;
        }
    }
    //再找列
    while(l2<=r2){
        mid=(l2+r2)/2;
        if(a[row][mid]<t){
            l2=mid+1;
        }else if(a[row][mid]>t){
            r2=mid-1;
        }else{
            cout<<"true";
            return 0;
        }
    }
    cout<<"false";
    return 0;
}