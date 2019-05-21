/*
题目：
Given the root node of a binary search tree (BST) and a value to be inserted into the tree, insert the value into the BST. 
Return the root node of the BST after the insertion. It is guaranteed that the new value does not exist in the original BST.
Note that there may exist multiple valid ways for the insertion, as long as the tree remains a BST after insertion. 
You can return any of them.
For example, 
Given the tree:
        4
       / \
      2   7
     / \
    1   3
And the value to insert: 5
You can return this binary search tree:
         4
       /   \
      2     7
     / \   /
    1   3 5
This tree is also valid:
         5
       /   \
      2     7
     / \   
    1   3
         \
          4
解析：给定一棵二叉搜索树，将给定值插入到该二叉搜索树中。给定值不在树中。
根据二叉树的搜索过程，当搜索到某一节点，判断节点值与搜索值的大小，判断下一步搜索左子树还是右子树时，
若应搜索左子树，但左子树为空，则将该值插入到此处，同理若应搜索右子树，但是右子树为空，则应将节点插入到此处。
循环条件同二叉搜索树的搜索，t不为空，同时，插入节点后应break退出循环。
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* t=root;//当前节点，不对树根节点操作，这样插入后返回原树的根节点root即可
        while(t!=NULL)//在二叉搜索树中搜索val值
        {
            if(t->val<val)//节点值小于目标值 搜索右子树
            {
                if(t->right!=NULL)//若右子树存在 继续重复搜索过程
                    t=t->right;
                else
                {
                    t->right= new TreeNode(val);//右子树不存在 说明此处为节点插入位置
                    break;//插入节点并退出循环
                }
            }
            
            else//因为题目限定了val不在树中 所以只有大于和小于两种情况 当节点值大于搜索值时 搜索左子树
            {
                if(t->left!=NULL)//若左子树非空 则继续搜索过程
                    t=t->left;
                else//若左子树空 
                {
                    t->left=new TreeNode(val);//将节点插入到此处
                    break;//退出搜索过程
                }
            }
        }
        return root;//没有对树的原根节点操作 所以返回树的原根节点即是返回整棵树
    }
};
