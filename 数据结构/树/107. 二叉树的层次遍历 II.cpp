/*
给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
例如：
给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其自底向上的层次遍历为：
[
  [15,7],
  [9,20],
  [3]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal-ii
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            vector<int> temp;
            for(int i=0;i<size;i++)
            {
                TreeNode* t=q.front();
                q.pop();
                temp.push_back(t->val);//层内从左到右插入 从左到右访问
                if(t->left!=nullptr)
                    q.push(t->left);
                if(t->right!=nullptr)
                    q.push(t->right);
            }
            res.insert(res.begin(),temp);//当前层插入到已有层的前面 实现层序的倒序
        }
        return res;
    }
};
