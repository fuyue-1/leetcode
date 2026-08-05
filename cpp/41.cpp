#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[100];
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<1||a[i]>n){
            a[i]=0;
        }
    }
    for(int i=1;i<=n;i++){
        while(a[i]!=0 && a[i]!=i && a[i]!=a[a[i]]) {
            swap(a[i],a[a[i]]);
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=i){
            cout<<i<<" ";
            return 0;
        }
    }

    return 0;
}