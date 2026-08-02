#include<bits/stdc++.h>
using namespace std;
int a[100];
int ans[100];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    stack<int> s;
    for(int i=0;i<n;i++){
        while(!s.empty() && a[s.top()]<a[i]){
            ans[s.top()]=i-s.top();
            s.pop();
        }
        s.push(i);
    }
    for(int j=0;j<n;j++){
        cout<<ans[j]<<" ";
    }
    return 0;
}