/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    TreeNode xParent = null, yParent = null; 
    int xDepth = -1, yDepth = -1;

    public boolean isCousins(TreeNode root, int x, int y) {
        solve(root,x,y,0,null);
        
        return (xParent != yParent && xDepth == yDepth) ? true : false;
    }

    public void solve(TreeNode root, int x, int y, int depth, TreeNode parent){
        if(root == null) return;

        if(x == root.val){
            xParent = parent;
            xDepth = depth;
        }else if(y == root.val){
            yParent = parent;
            yDepth = depth;
        }

        solve(root.left,x,y,depth+1,root);
        solve(root.right,x,y,depth+1,root);
    }
}