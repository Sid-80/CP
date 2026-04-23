/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode* ,TreeNode*> parent;
        markParent(root,parent);
        unordered_map<TreeNode*,bool> visited;
        visited[target]=true;
        queue<TreeNode*>q;
        q.push(target);
        int currDist=0;
        while(q.size()!=0)
        {
            int size=q.size();
            if(currDist++ ==k)  break;
            for(int i=0;i<size;i++) 
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !visited[node->left])
                {
                    q.push(node->left);
                    visited[node->left]=true;
                }
                if(node->right && !visited[node->right])
                {
                    q.push(node->right);
                    visited[node->right]=true;
                }
                if(parent[node] && !visited[parent[node]])//important here
                {
                    q.push(parent[node]);
                    visited[parent[node]]=true;
                }
            }
        }
        vector<int> ans;
        while(q.size()!=0)
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent)
    {
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()!=0)
        {   //going level was not necessary just did it for my continuity
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node=q.front();
                q.pop();
                if(node->left)
                {
                    q.push(node->left);
                    parent[node->left]=node;
                }
                if(node->right)
                {
                    q.push(node->right);
                    parent[node->right]=node;
                }
            }
        }
    }
};