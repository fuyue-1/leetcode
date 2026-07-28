struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NUll){}
};
ListNode *get(ListNode * A,ListNode * B){
    if(A==nullptr|| B=nullptr) return nullptr;
    ListNode *p=A;
    ListNode *q=B;
    while(p!=q){
        p=p==nullptr?B:p->next;
        q=q==nullptr?A:q->next;
    }
    return p;
}
