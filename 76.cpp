#include<bits/stdc++.h>
using namespace std;
int ss[150]={0},tt[150]={0};
int l=0,r=-1,minl=INT_MAX,ansl=-1;
//判断当前窗口是否 完整 覆盖t
bool check(){
    for(int i=(int)'A';i<=(int)'Z';i++){
        if(tt[i]>0 &&ss[i]<tt[i]){
            return false;
        }
    }
    for(int i=(int)'a';i<=(int)'z';i++){
        if(tt[i]>0 &&ss[i]<tt[i]){
            return false;
        }
    }
    return true;
}
int main(){
    string s,t;
    cin>>s>>t;
    int sl=s.length();
    int tl=t.length();
    for(int i=0;i<tl;i++){
        tt[t[i]]++;
    }
    //移动右边界
    while(r<sl){
        r++;
        ss[s[r]]++;
        while(l<=r && check()){
            if(minl>r-l+1){
                minl=r-l+1;
                ansl=l;
            }
            ss[s[l]]--;
            l++;
        } 
    }
    if(ansl==-1){
        cout<<"0";
    }else{
        cout<<s.substr(ansl,minl);
    }
    return 0;
}