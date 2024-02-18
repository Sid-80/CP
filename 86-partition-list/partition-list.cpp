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
    ListNode* partition(ListNode* head, int x) {
        ListNode* h1 = new ListNode();
        ListNode* temp1 = h1;
        ListNode* h2 = new ListNode();
        ListNode* temp2 = h2;

        while(head!=NULL){
            if(head->val < x){
                temp1->next = head;
                temp1 = temp1->next;
            }else{
                temp2->next = head;
                temp2 = temp2->next;
            }
            head=head->next;
        }

        if(h1->next == NULL) return h2->next;

        temp1->next = h2->next;
        temp2->next = NULL;

        return h1->next;

    }
};