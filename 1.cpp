#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<int> twosum(vector<int> & nums, int target){
    unordered_map<int,int> hash;
    for(int i=0;i<nums.size();i++){
        int com=target-nums[i];
        if(hash.find(com)!=hash.end()){
            return {hash[com],i};
        }
        hash[nums[i]]=i;
    }
    return {};
}
int main(){
    vector<int> nums;
    int x;
    while(cin>>x){
        nums.push_back(x);
        if(cin.peek()=='\n'){
            break;
        }
    }
    int target;
    cin>>target;
    vector<int> ans=twosum(nums,target);
    cout<<'['<<ans[0]<<','<<ans[1]<<']'<<endl;
    return 0;
}