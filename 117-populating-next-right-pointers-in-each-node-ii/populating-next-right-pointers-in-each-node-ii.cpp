/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {

        if(!root) return root;

        queue<pair<int,Node*>> q;
        q.push({1,root});

        while(!q.empty()){

            int curlvl = q.front().first;
            Node* front = q.front().second;
            q.pop();
            
            Node* newNext = q.front().second;
            int nextlvl = q.front().first;

            if(curlvl == nextlvl){
                front->next = newNext;
            }

            if(front->left != nullptr && front){
                q.push({curlvl + 1, front->left});
            }

            if(front->right != nullptr && front){
                q.push({curlvl + 1, front->right});
            }
        }

        return root;
    }
};