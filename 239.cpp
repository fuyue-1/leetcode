#include<bits/stdc++.h>
using namespace std;
int main(){
    int a[1000];
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    multiset<int,greater<int>> s;
    for(int i=0;i<k;i++){
        s.insert(a[i]);
    }
    cout<<*s.begin()<<" ";
    for(int i=k;i<n;i++){
        s.erase(s.find(a[i-k]));
        s.insert(a[i]);
        cout<<*s.begin()<<" ";
    }
    return 0;
}