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


    int getIndex(vector<int> in, int ele){
        for(int i = 0; i < in.size();i++){
            if(in[i] == ele) return i;
        }
        return -1; 
    }

    TreeNode* solve(
        vector<int> inorder, 
        vector<int> postorder,
        int& postIn,
        int inStart,
        int inEnd
    ){

        if(postIn < 0 || inStart > inEnd) return NULL;

        int ele = postorder[postIn--];
        int pos = getIndex(inorder, ele);

        TreeNode* root = new TreeNode(ele);


        root->right = solve(inorder,postorder,postIn,pos+1,inEnd);
        root->left = solve(inorder,postorder,postIn,inStart,pos-1);
        

        return root;
    }



public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        
        int postIndex = postorder.size() - 1;

        TreeNode*  ans = solve(inorder, postorder, postIndex, 0, inorder.size() - 1);

        return ans;

    }
};