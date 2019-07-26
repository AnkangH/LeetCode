/*
给定一个非空二叉树，返回其最大路径和。
本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
示例:
输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7

输出: 42
*/


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
    int res=INT_MIN;
    int maxPathSum(TreeNode* root) {
        maxSubPath(root);//最大路径和可以看作是某个节点出发 左右子树最大路径之后
        return res;
    }
    int maxSubPath(TreeNode* root)//返回root为根节点的左右子树最大路径 包含root
    {
        if(root==nullptr)
            return 0;
        int left=max(0,maxSubPath(root->left));//左子树的最大路径和
        int right=max(0,maxSubPath(root->right));//右子树的最大路径和
        res=max(res,root->val+left+right);//保存当前节点作为根节点的左右路径和
        return max(left,right)+root->val;//返回当前节点作为根节点的左右子树最大路径
    }
};
