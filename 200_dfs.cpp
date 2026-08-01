#include<bits/stdc++.h>
using namespace std;
int m,n;
int grid[100][100];
//dfs，一条路走到黑，当前位置是1，发现新岛屿，然后上下左右方向分别找完所有的同伴即为一个完整岛屿
//四个方向都走到尽头，目的是记录岛屿数，岛屿直接淹没变为0
void dfs(int i,int j){
    if(i<0||i>=m||j<0||j>=n||grid[i][j]==0) return;
    grid[i][j]=0;
    dfs(i+1,j);
    dfs(i-1,j);
    dfs(i,j+1);
    dfs(i,j-1); 
}
int main(){
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                ans++;
                dfs(i,j);
            }
        }
    }
    cout<<ans;
    return 0;
}