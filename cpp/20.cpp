#include<bits/stdc++.h>
using namespace std;
int main(){
    string s; cin>>s;
    stack<char> st;
    unordered_map<char,char> ls={{'}','{'},{')','('},{']','['}};
    for(char c:s){
        if(ls.count(c)){
            if(st.empty()||st.top()!=ls[c]) return 0;
            st.pop();
        }else{
            st.push(c);
        }
    }
    cout<<"True";
    return 0;
}