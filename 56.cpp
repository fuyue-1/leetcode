#include<bits/stdc++.h>
using namespace std;
int ans[100][2];
struct PAIR{
    int x,y;
    bool operator<(const PAIR &a)const{
        if(x==a.x) return y<a.y;
        return x<a.x;
    }
}a[1005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
    }
    sort(a,a+n);
    int m=0;
    int l=a[0].x,r=a[0].y;
    for(int i=1;i<n;i++){
        if(a[i].x<=r){
            r=max(a[i].y,r);
        }else{
            m++;
            ans[m][0]=l;
            ans[m][1]=r;
            l=a[i].x;
            r=a[i].y;
        }
    }
    m++;
    ans[m][0]=l;
    ans[m][1]=r;
    for(int k=1;k<=m;k++){
        cout<<ans[k][0]<<' '<<ans[k][1]<<endl;
    }
    return 0;
}