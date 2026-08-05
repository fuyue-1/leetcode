#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int a[100];
    int pre[100];
    
    //0 n-1
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    //0 
    pre[0]=a[0];
    //1 n-1 当前元素在内的前面的所有数值的乘积
    for(int i=1;i<n;i++){
        pre[i]=a[i]*pre[i-1];
    }
    int r[100];
    r[n-1]=a[n-1];
    //当前元素和之后所有元素的乘积
    for(int j=n-2;j>=0;j--){
        r[j]=r[j+1]*a[j];
    }
    for(int k = 0; k < n; k++){
        long long L = (k == 0) ? 1 : pre[k-1];
        long long R = (k == n-1) ? 1 : r[k+1];
        cout << L * R << " ";
    }
    return 0;
}