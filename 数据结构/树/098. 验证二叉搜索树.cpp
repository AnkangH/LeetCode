/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。
假设一个二叉搜索树具有如下特征：
节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:
输入:
    2
   / \
  1   3
输出: true
示例 2:
输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    int pre;//前值
    bool res=true;//返回值
    bool first=true;//标记首次访问最左侧叶节点
    bool isValidBST(TreeNode* root) {
        preOrder(root);
        return res;
    }
    void preOrder(TreeNode* root)
    {
        if(root==nullptr)
            return;//边界条件
        preOrder(root->left);//左子树
        if(first)//访问到最左侧叶节点时 
        {
            pre=root->val;//将其值作为比较的起始值
            first=false;//标记首次访问
        }
        else//非首次访问
        {
            if(root->val<=pre)//若当前值不比上个值大
                res=false;//不是二叉搜索树
            else//否则
                pre=root->val;// 更新前值 继续比较
        }
        if(!res)
            return;//若不符合 提前退出
        preOrder(root->right);//搜索右子树
    }
};
