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
解析：对于二叉搜索树，节点值唯一，且左侧节点数值小于右侧节点数值。
方法一：使用递归方法。
比较当前节点，若为空，则返回空；若值小于目标值，则查找右树，若大于目标值，则查找左树，否则两值相等，返回该节点。
注意因为在递归中没有修改或保存数值，所以四种情况都由return语句完成递归。因为是if else if所以每种情况都必须有显式返回值。
如果函数原型的参数可以增加，那么用一个Treenode*记录当前节点，而不用return语句。
先查找左子树还是右子树对程序没有影响，因为查找左右子树是由节点值和目标值的大小关系确定的。
方法二：迭代方法。
搜索终止的条件时搜索到叶结点或者有某节点匹配。因为节点没有回溯，所以递归与循环执行的操作实际相同。
用一个TreeNode*记录最终结果，如果匹配则将匹配节点赋值给它。并根据节点值与目标值确定下一步搜索左子树还是右子树。
//方法一 递归法
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
//方法二：迭代法
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
        if(root==NULL)
            return NULL;//预判断 防止空指针造成崩溃 实际上while中有对输入为空的判断 因此这句可去掉
        TreeNode* res=NULL;//记录返回值 若无匹配则返回NULL
        TreeNode* t=root;//记录当前头 不修改输入
        while(t!=NULL)
        {
            if(t->val<val)
                t=t->right;//节点值小于目标值 向右（节点值增大）搜索
            else if(t->val>val)
                t=t->left;//节点值大于目标值 向左（节点值减小）搜索
            else
            {
                res=t;
                break;//若节点匹配 则应退出循环 否则会一直在此处死循环
            }
        }
        return res;
    }
};
