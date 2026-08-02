#include<bits/stdc++.h>
using namespace std;
int ans = 0, n;
int col[32], have_queen[32]={0}; // col[i]表示第i行皇后放的列数，have_queen[j]表示第j列是否有皇后

/*  
主对角线（ / ）
所有格子满足：行号 + 列号 = 定值
l1 = i + col[i]
line1[x]：统计这条对角线上皇后个数

副对角线（ \ ）
所有格子满足：行号 - 列号 = 定值
l2 = i - col[i]
i-col[i]可能得到负数，数组下标不能负数！
+9 是偏移量，把所有数值整体向右平移，保证下标≥0。*/

bool check_ans() {
    int line1[32]={0}, line2[32]={0}; // line1[i]表示主对角线i上皇后个数，line2[i]表示副对角线i上皇后个数
    
    for (int i = 0; i < n; ++i) {
        int l1 = i + col[i];
        int l2 = i - col[i] + 9;
        ++line1[l1];
        ++line2[l2];
        if (line1[l1] > 1 || line2[l2] > 1) {
            return false;
        }
    }
    return true;
}

void print_solution()
{
    ans++;
    // 逐行打印棋盘
    for(int r = 0; r < n; r++)
    {
        for(int c = 0; c < n; c++)
        {
            if(col[r] == c)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl; // 每个解之间空一行
}

void dfs(int r) {
    // 终止条件
    if (r == n) {
        if(check_ans()){
            print_solution(); 
        }
    } else {
        // 枚举：尝试把皇后放在第r行第i列
        for (int i = 0; i < n; ++i) {
            if (have_queen[i]) continue; // 当前列已有皇后，跳过
            
            col[r] = i;                 // 记录：第r行皇后放在i列
            have_queen[i] = 1;          // 标记i列被占用
            dfs(r + 1);                 // 递归摆放下一行
            have_queen[i] = 0;          // 【回溯，恢复现场】
        }
    }
}

int main() {
    cin >> n;
    dfs(0);
    return 0;
}