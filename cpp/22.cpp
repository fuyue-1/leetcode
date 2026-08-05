#include<bits/stdc++.h>
using namespace std;
//用l来记录'（'的个数，ch来记录当前括号的平衡情况
int main(){
    int n;
    cin>>n;

    for(int i=0;i<(1<<2*n);i++){
        int l=0,ch=0;
        string s;
        //一共生成2n个括号,下标到2n-1
        for(int j=2*n-1;j>=0;j--){
            //定义1是'（'，0是'）'
            if(i&(1<<j)){
                s.push_back('(');
                l++;ch++;
            }else{
                s.push_back(')');
                ch--;
            }
            if(ch<0) break;
        }
        if(ch<0 ||l!=n) continue;
        cout<<s<<endl;
    }
    return 0;
}