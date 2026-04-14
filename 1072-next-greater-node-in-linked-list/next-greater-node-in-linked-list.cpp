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
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int,int>> st;

        ListNode* tmp = head;

        int itr = 0;

        while(tmp->next != nullptr){
            itr++;
            tmp = tmp->next;
        }

        vector<int> ans(itr + 1, 0);

        tmp = head;
        int itr2 = 1;

        st.push({0, tmp->val});

        tmp = tmp->next;

        while(tmp != nullptr){
            while(!st.empty() && st.top().second < tmp->val){
                // cout<<st.top().second<<endl;
                ans[st.top().first] = tmp->val;
                st.pop();
            }

            st.push({itr2, tmp->val});
            tmp = tmp->next;
            itr2++;
        }

        return ans;
    }
};