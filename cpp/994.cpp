#include<bits/stdc++.h>
using namespace std;
int grid[100][100];
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
int main(){
    int m;
    int n;
    int fresh=0,state=0;
    queue<pair<int,int>> q[2];
    cin>>m>>n;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
            if(grid[i][j]==1) fresh++;
            if(grid[i][j]==2) q[state].push(make_pair(i,j));
        }
    }
    if(fresh==0){
        cout<<0;
        return 0;
    }
    int ans=0;
    //说明还有橘子可以感染
    while(!q[0].empty()||!q[1].empty()){
        //进入新一轮感染
        ans++;
        while(!q[state].empty()){
            int x=q[state].front().first,y=q[state].front().second;
            q[state].pop();
            for(int i=0;i<4;i++){
                int curx=x+dir[i][0],cury=y+dir[i][1];
                if(curx<0||curx>=m||cury<0||cury>=n) continue;
                if(grid[curx][cury]==1) {
                    //标记为腐烂，防止重复bfs
                    grid[curx][cury]=2;
                    //扔进另一个队列，下一轮由它进行感染
                    q[state^1].push(make_pair(curx,cury));
                    fresh--;
                }
            }
        }
        state^=1;
    }
    if(fresh>0) cout<<-1<<endl;
    else cout<<ans-1;
    return 0;
}