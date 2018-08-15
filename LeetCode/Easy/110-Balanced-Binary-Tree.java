/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public int getDepth(TreeNode node, int depth) {
        if(node == null) {
            return depth;
        } else {
            int leftDepth = getDepth(node.left, depth + 1);
            int rightDepth = getDepth(node.right, depth + 1);
            return Math.max(leftDepth, rightDepth);
        }
    }
    public boolean checkSubtree(TreeNode node) {
        if(node.left == null && node.right == null) {
            return true;
        } else {
            if(node.left == null) {
                return getDepth(node.right, 0) <= 1;
            } else if(node.right == null) {
                return getDepth(node.left, 0) <= 1;
            } else {
                int leftDepth = getDepth(node.left, 0);
                int rightDepth = getDepth(node.right, 0);
                if(Math.abs(leftDepth - rightDepth) <= 1) {
                    return checkSubtree(node.left) && checkSubtree(node.right);
                } else {
                    return false;
                }
            }
        }
    }
    public boolean isBalanced(TreeNode root) {
        if(root == null) {
            return true;
        } else {
            return checkSubtree(root);
        }
    }
}
