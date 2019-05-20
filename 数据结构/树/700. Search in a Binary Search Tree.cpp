/*
题目：
Given the root node of a binary search tree (BST) and a value. You need to find the node in the BST that the node's 
value equals the given value. Return the subtree rooted with that node. If such node doesn't exist, you should return NULL.
For example, 
Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to search: 2
You should return this subtree:
      2     
     / \   
    1   3
In the example above, if we want to search the value 5, since there is no node with value 5, we should return NULL.
Note that an empty tree is represented by NULL, therefore you would see the expected output (serialized tree format) as [], not null.
解析：使用递归方法。对于二叉搜索树，节点值唯一，且左侧节点数值小于右侧节点数值。
比较当前节点，若为空，则返回空；若值小于目标值，则查找右树，若大于目标值，则查找左树，否则两值相等，返回该节点。
注意因为在递归中没有修改或保存数值，所以四种情况都由return语句完成递归。
先查找左子树还是右子树对程序没有影响，因为查找左右子树是由节点值和目标值的大小关系确定的。
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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL)//未找到
            return NULL;
        else if(root->val<val)//节点值小于目标值，查找右子树
            return searchBST(root->right,val);
        else if(root->val>val)//节点值大于目标值，查找左子树
            return searchBST(root->left,val);
        else//节点值等于目标值，返回该节点
            return root;
    }
};
