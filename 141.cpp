#include<bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode * next;
    ListNode (int x):val(x),next(nullptr){}
};
bool has(ListNode * head){
    if(head==nullptr || head->next==nullptr){
        return false;
    }
    ListNode * fast=head;
    ListNode * slow=head;
    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(slow==fast) return true;
    }
    return false;
}
int main(){
    vector<int> nums;
    char ch;
    int tmp;
    cin>>ch;
    while(cin>>tmp){
        nums.push_back(tmp);
        cin>>ch;
        if(ch==']'){
            break;
        }
    }
    int pos;
    cin>>pos;
    ListNode * head=new ListNode(nums[0]);
    vector<ListNode*> nodes;
    nodes.push_back(head);
    ListNode *p=head;
    for(int i=1;i<nums.size();i++){
        p->next=new ListNode(nums[i]);
        p=p->next;
        nodes.push_back(p);
    }
    if(pos!=-1) p->next=nodes[pos];
    bool ans=has(head);
    cout<<boolalpha<<ans<<endl;
    return 0;
}
```
