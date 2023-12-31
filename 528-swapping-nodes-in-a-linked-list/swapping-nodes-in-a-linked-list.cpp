/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* start = head;
        int cnt  = 0;

        ListNode * n1,* n2;

        while(start != NULL){
            cnt++;
            if(cnt == k){
                n1 = start;
            }
            start = start->next;
        }

        cnt = cnt - k;
        start = head;

        while(start!= NULL && cnt != 0){
            start = start->next;
            cnt--;
        }

        n2 = start;
        int t = n1->val;
        n1->val = n2->val;
        n2->val = t;

        return head;
    }
};