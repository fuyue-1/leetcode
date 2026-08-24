#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* dummy = new ListNode(0); // 虚拟头结点
    ListNode* cur = dummy;
    int carry = 0; // 进位

    while(l1 != nullptr || l2 != nullptr || carry != 0){
        int sum = carry;
        if(l1) sum += l1->val;
        if(l2) sum += l2->val;

        carry = sum / 10;
        cur->next = new ListNode(sum % 10);
        cur = cur->next;

        if(l1) l1 = l1->next;
        if(l2) l2 = l2->next;
    }
    return dummy->next;
}

// 根据vector构建链表
ListNode* buildList(const vector<int>& nums){
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for(int x : nums){
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    return dummy->next;
}

// 打印链表
void printList(ListNode* head){
    ListNode* p = head;
    while(p != nullptr){
        cout << p->val;
        if(p->next) cout << " -> ";
        p = p->next;
    }
    cout << endl;
}

int main(){
    vector<int> a,b;
    int x;

    while(cin >> x){
        if(x == -1) break;
        a.push_back(x);
    }

    while(cin >> x){
        if(x == -1) break;
        b.push_back(x);
    }

    ListNode* l1 = buildList(a);
    ListNode* l2 = buildList(b);

    ListNode* ans = addTwoNumbers(l1,l2);
    printList(ans);

    return 0;
}