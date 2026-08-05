struct ListNode{
    int val;
    ListNode * next;
    ListNode ():val(x),next(nullptr){}
    ListNode (int x):val(x),next(nullptr){}
    ListNode (int x,ListNode * next):val(x),next(next){}
};
ListNode * reverse(ListNode * node){
    ListNode * curr=head;
    ListNode * prev=nullptr;
    while(curr!=nullptr){
        ListNode * nextp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextp;
    }
    return prev;
}