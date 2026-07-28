# leetcode Hot 100
# 1.两数之和【哈希表】
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案，并且你不能使用两次相同的元素。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
# ans:
```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //空哈希表
        unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++){
            int com=target-nums[i];
            //find去找key，找到答案直接返回
            if(hash.find(com)!=hash.end()){
                return {hash[com],i};
            }
            hash[nums[i]]=i;
        }
        return {};
    }
};
```
# 141.环形链表[快慢指针]
给你一个链表的头节点 head ，判断链表中是否有环。

如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。仅仅是为了标识链表的实际情况。

如果链表中存在环 ，则返回 true 。 否则，返回 false 。

示例 1：

![NO1](./img/141_2.png)

输入：head = [3,2,0,-4], pos = 1
输出：true
解释：链表中有一个环，其尾部连接到第二个节点。

示例 2：

![NO2](./img/141_1.png)

输入：head = [1,2], pos = 0
输出：true
解释：链表中有一个环，其尾部连接到第一个节点。
```cpp
/*
快慢指针
1.设置指针：
    ￮设置两个指针，一个称为慢指针（slow），另一个称为快指针（fast）。
    ￮它们都从链表的头节点（head）开始。
2.移动规则：
    ￮慢指针每次向前移动一步（slow = slow.next）。
    ￮快指针每次向前移动两步（fast = fast.next.next）。
3.判断逻辑：
    ￮如果链表中没有环： 快指针会首先到达链表的末尾（即 fast 或 fast.next 变成 null）。在这种情况下，我们可以确定链表不是环形链表，返回 false。
    ￮如果链表中有环：
        ▪想象在一个圆形跑道上，一个跑得快的人（快指针）和一个跑得慢的人（慢指针）。
        ▪由于快指针移动速度是慢指针的两倍，当它们都进入环后，快指针最终一定会追上慢指针。
        ▪当 slow 和 fast 最终相遇（即 slow == fast）时，我们可以确定链表是环形链表，返回 true。*/
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==nullptr || head->next==nullptr)return false;
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) return true;
        }
        return false;
    }
};
```
# 160.相交链表【双指针法】
![NO1](./img/160_1.png)
![NO1](./img/160_2.png)
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 /*思路是
•LA=a+c
•LB=b+c
目标：找到相交点 C。
方法：创建两个指针 pA 和 pB，分别从链表 A 和链表 B 的头节点开始遍历。
1.第一轮遍历：
pA 走完链表 A 后（走到 null），将其重新指向链表 B 的头节点。
pB 走完链表 B 后（走到 null），将其重新指向链表 A 的头节点。
2.第二轮遍历：
￮在它们重新指向后，让它们继续向前移动。
关键洞察：当 pA 重新指向 B 链表，且 pB 重新指向 A 链表时：
•指针 pA 走过的总距离是：LA+LB=(a+c)+b
•指针 pB 走过的总距离是：LB+LA=(b+c)+a
由于 a+c+b=b+c+a，所以两个指针走过的总距离是相等的。*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==nullptr ||headB==nullptr) return nullptr;
        ListNode * p=headA;
        ListNode * q=headB;
        while(p!=q){
            p=p==nullptr?headB:p->next;
            q=q==nullptr?headA:q->next;

        }
        /*•如果链表相交，它们最终会在相交节点处相遇。
          •如果链表不相交（即 c=0），它们会同时在两个链表的末尾 null 处相遇（因为 LA+LB 仍然等于 LB+LA），这时返回 null。*/
        return p;
    }
};
```