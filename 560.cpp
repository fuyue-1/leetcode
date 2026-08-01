#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    vector<int> pre(n+1,0);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+nums[i-1];
    }
    unordered_map<int,int> mp;
    int ans=0;
    for(int i=0;i<=n;i++){
        if(mp.find(pre[i]-k)!=mp.end()){
            ans+=mp[pre[i]-k];
        }
        mp[pre[i]]++;
    }
    cout<<ans;
    return 0;
}