#include<bits/stdc++.h>
using namespace std;

int main(){  
    int n; cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<n;i++) cin>>a[i];
    int tar; cin>>tar;
    unordered_map<int,int>hash;
    for(int i=0;i<n;i++){
        int x=tar-a[i];
        if(hash.find(x)!=hash.end()){
            cout<<a[hash[x]]<<'+'<<a[i]<<'='<<tar<<endl;
        }
        hash[a[i]]=i;
    }
    return 0;  
}