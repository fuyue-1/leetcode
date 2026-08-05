#include<bits/stdc++.h>
using namespace std;
int main(){
    int m,n;
    cin>>m>>n;
    int dp[100][100];
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0||j==0) dp[i][j]=1;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[m-1][n-1];
    return 0;
}