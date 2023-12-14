/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode*> a;
        stack<ListNode*> b;

        for (ListNode* t = headA; t; t = t->next) a.push(t);
        for (ListNode* t = headB; t; t = t->next) b.push(t);

        ListNode * ans =NULL;

        while(!a.empty() && !b.empty()){
            ListNode * t1 = a.top();
            ListNode * t2 = b.top();
            a.pop();
            b.pop();

            if(t1 != t2) return ans;
            else ans = t1; 
        }

        return ans;

    }
};