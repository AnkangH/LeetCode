/*
给定两个二叉树，编写一个函数来检验它们是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
示例 1:

输入:       1         1
          / \       / \
         2   3     2   3

        [1,2,3],   [1,2,3]
输出: true
示例 2:
输入:      1          1
          /           \
         2             2

        [1,2],     [1,null,2]

输出: false
示例 3:
输入:       1         1
          / \       / \
         2   1     1   2

        [1,2,1],   [1,1,2]
输出: false
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/same-tree
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==nullptr&&q==nullptr)
            return true;//都为空 返回true
        else if(p==nullptr||q==nullptr)
            return false;//否则有一个为空 返回false
        queue<TreeNode*> q1,q2;//辅助队列 层序遍历
        q1.push(p);
        q2.push(q);
        while(!q1.empty())
        {
            TreeNode* temp1=q1.front();
            q1.pop();
            TreeNode* temp2=q2.front();
            q2.pop();
            if(temp1->val!=temp2->val)
                return false;//当前节点值不等 返回false
            //左右子树结构不同 返回false
            if(temp1->left==nullptr&&temp2->left!=nullptr)
                return false;
            if(temp1->left!=nullptr&&temp2->left==nullptr)
                return false;
            if(temp1->right==nullptr&&temp2->right!=nullptr)
                return false;
            if(temp1->right!=nullptr&&temp2->right==nullptr)
                return false;
            //放入非空子节点 继续遍历
            if(temp1->left!=nullptr)
                q1.push(temp1->left);
            if(temp1->right!=nullptr)
                q1.push(temp1->right);
            if(temp2->left!=nullptr)
                q2.push(temp2->left);
            if(temp2->right!=nullptr)
                q2.push(temp2->right);
        }
        return true;//未返回false 则两树相同
    }
};
