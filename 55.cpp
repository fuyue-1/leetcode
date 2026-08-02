#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int a[1000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mx=0;
    for(int i=0;i<n;i++){
        if(i>mx) {cout<<"false"; return 0;}
        mx=max(mx,a[i]+i);
        if(mx>=n-1) {cout<<"true"; return 0;}
    }
    cout<<"false";
    return 0;
}