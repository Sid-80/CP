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

/*
    if k % len == 0 then return head
    it will help us when k is greather than len to get the minimum rotaions required and skip the repeating rotation 
    for example if len = 5 and k = 5 no meaning in rotating 
*/

class Solution {

    ListNode* NthNode(ListNode* head, int k){
        int cnt = 1;
        while(head != NULL){
            if(cnt == k) return head;
            cnt++;
            head = head->next;
        }
        return head;
    }

public:
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == NULL || k == 0) return head;

        ListNode * tail = head;
        int len = 1;

        while(tail->next != NULL){
            len++;
            tail = tail->next;
        }

        k = k % len;

        if (k == 0) return head;

        tail->next = head;

        ListNode* newHead = NthNode(head,len-k);

        head = newHead->next;

        newHead->next = NULL;

        return head;
    }
};