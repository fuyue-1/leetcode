#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    vector<int> memo(n+1,0);
    memo[1]=1;
    memo[2]=2;
    for(int i=3;i<=n;i++){
        memo[i]=memo[i-1]+memo[i-2];
    }
    cout<<memo[n];
    return 0;
}