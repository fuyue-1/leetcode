#include<bits/stdc++.h>
using namespace std;
//bfs 广度优先搜索
int grid[100][100],vis[100][100],m,n;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void bfs(int i,int j){
    queue<pair<int,int>> q;
    q.push(make_pair(i,j));
    while(!q.empty()){
        int x=q.front().first,y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int curx=x+dir[i][0],cury=y+dir[i][1];
            if(curx<0||curx>=m||cury<0||cury>=n) continue;
            if(grid[curx][cury]==0) continue;
            if(vis[curx][cury]==1) continue;
            q.push(make_pair(curx,cury));
            vis[curx][cury]=1;
        }
    }
}
int main(){
    int ans=0;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            vis[i][j]=0;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1 && vis[i][j]==0){
                bfs(i,j);
                ans++;
                vis[i][j]=1;
            }
        }
    }
    cout<<ans;
    return 0;
}
