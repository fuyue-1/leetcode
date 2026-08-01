#include<bits/stdc++.h>
using namespace std;
int cnt[512]={0};
int main(){
    string s;
    cin>>s;
    int ans=0;
    int l=0,r=0;
    cnt[s[0]]++;
    while(r<s.length()-1){
        r++;
        cnt[s[r]]++;
        if(cnt[s[r]]>1){
            while(l<r && cnt[s[r]]>1){
                cnt[s[l]]--;
                l++;
            }
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}