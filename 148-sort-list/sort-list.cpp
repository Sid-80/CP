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
    ListNode* mergeList(ListNode * p1, ListNode * p2){
        ListNode * tmp = new ListNode(0);
        ListNode * curr = tmp;

        while(p1 != nullptr && p2 != nullptr){
            if(p1->val <= p2->val){
                curr->next = p1;
                p1 = p1->next;
            }else{
                curr -> next = p2;
                p2 = p2->next;
            }
            curr = curr -> next;
        }


        if(p1 != nullptr){
            curr->next = p1;
            p1 = p1->next;
        }else{
            curr -> next = p2;
            p2 = p2->next;
        }

        return tmp->next;
    }

    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;

        // Finding Mid
        ListNode * tmp = nullptr;
        ListNode * slow = head;
        ListNode * fast = head;

        while(fast != nullptr && fast->next != nullptr){
            tmp = slow;
            slow = slow->next; 
            fast = fast->next->next; 
        }

        tmp->next = NULL;

        ListNode * p1 = sortList(head);
        ListNode * p2 = sortList(slow);

        return mergeList(p1,p2);
    }
};