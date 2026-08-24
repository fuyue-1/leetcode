#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeRecursive(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    if (list1->val > list2->val) {
        list2->next = mergeRecursive(list1, list2->next);
        return list2;
    } else {
        list1->next = mergeRecursive(list1->next, list2);
        return list1;
    }
}

/*
ListNode* mergeIterative(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* cur = &dummy;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            cur->next = list1;
            list1 = list1->next;
        } else {
            cur->next = list2;
            list2 = list2->next;
        }
        cur = cur->next;
    }
    
    if (list1 != nullptr) cur->next = list1;
    if (list2 != nullptr) cur->next = list2;

    return dummy.next;
}
*/

int main()
{
    // build list1
    ListNode* h1 = nullptr;
    ListNode* tail = nullptr;
    int num;
    while (cin >> num && num != -1) {
        if (h1 == nullptr) {
            h1 = new ListNode(num);
            tail = h1;
        } else {
            tail->next = new ListNode(num);
            tail = tail->next;
        }
    }

    // build list2
    ListNode* h2 = nullptr;
    tail = nullptr;
    while (cin >> num && num != -1) {
        if (h2 == nullptr) {
            h2 = new ListNode(num);
            tail = h2;
        } else {
            tail->next = new ListNode(num);
            tail = tail->next;
        }
    }

    // use recursive version
    ListNode* res = mergeRecursive(h1, h2);
    // switch to iterative: uncomment function above, then use:
    // ListNode* res = mergeIterative(h1, h2);

    // print result
    for (ListNode* p = res; p != nullptr; p = p->next) {
        cout << p->val << " ";
    }
    cout << endl;

    return 0;
}