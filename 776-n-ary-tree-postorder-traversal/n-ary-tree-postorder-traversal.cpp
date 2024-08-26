/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root, vector<int> & ans){
        if(!root) return;

        vector<Node*> childs = root->children;

        for(int i = 0;i < childs.size();i++){
            solve(childs[i], ans);
            ans.push_back(childs[i]->val);
        }
        return;

    }

    vector<int> postorder(Node* root) {
        vector<int> ans;
        solve(root, ans);
        if(root) ans.push_back(root->val);
        return ans;
    }
};