/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int,multiset<int>>> nodes; // <lvl, <hd,valueOfNode>> multiset to get sorted order
        queue<pair<TreeNode*, pair<int,int>>> q1;
        
        // if(!root) return ans;
        //consider root at 0 on number line ansd At the start level is 0.
        q1.push(make_pair(root,make_pair(0,0)));

        while(!q1.empty()){
            pair<TreeNode*, pair<int,int>> temp = q1.front();
            q1.pop();
            TreeNode* tNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            nodes[hd][lvl].insert(tNode->val);

            if(tNode->right)
                q1.push(make_pair(tNode->right, make_pair(hd+1, lvl+1)));
            if(tNode->left)
                q1.push(make_pair(tNode->left, make_pair(hd-1, lvl+1)));

        }
        

        vector<vector<int>> ans;
        for(auto itr1:nodes){
            vector<int> temp;
            for(auto itr2:itr1.second){
                temp.insert(temp.end(),itr2.second.begin(),itr2.second.end());
            }
            ans.push_back(temp);
        }
        return ans;
    }   
};