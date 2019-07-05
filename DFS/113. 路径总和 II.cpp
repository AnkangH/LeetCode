/*
给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
说明: 叶子节点是指没有子节点的节点。
示例:
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1
返回:
[
   [5,4,11,2],
   [5,8,4,5]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum-ii
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
    vector<vector<int>> res;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if(root==nullptr)
            return res;//dfs子程序默认root合法 所以先判断root是否合法
        vector<int> temp;
        dfs(root,temp,sum);//回溯
        return res;//返回值
    }
    void dfs(TreeNode* root,vector<int>& temp,int sum)
    {
        temp.push_back(root->val);//添加当前节点
        if(sum==root->val&&root->left==nullptr&&root->right==nullptr)//和相等 且最后一个是叶节点
            res.push_back(temp);
        if(root->left!=nullptr)//因为有负数 所以不考虑提前剪枝
            dfs(root->left,temp,sum-root->val);//搜索左子树
        if(root->right!=nullptr)
            dfs(root->right,temp,sum-root->val);//搜索右子树
        temp.pop_back();//回溯 删除本轮添加的节点
    }
};
