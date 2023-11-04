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

    int getIndex(vector<int> in,int ele){
        for(int i = 0; i < in.size();i++){
            if(in[i] == ele){
                return i;
            }
        }
        return -1;
    }

    TreeNode* solve(vector<int> preorder, 
                vector<int> inorder, 
                int& preIndex, 
                int inStart, 
                int inEnd, 
                int n
            ){
        //basecase
        if(preIndex >= n || inStart > inEnd ) return nullptr;

        int ele = preorder[preIndex++];
        int pos = getIndex(inorder,ele);
        TreeNode* node = new TreeNode(ele);

        node->left = solve(preorder,inorder,preIndex,inStart,pos-1,n);
        node->right = solve(preorder,inorder,preIndex,pos+1,inEnd,n);

        return node;

    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;

        
        TreeNode* ans = solve(preorder,inorder,preIndex,0,inorder.size()-1,inorder.size());
        return ans;
    }
};