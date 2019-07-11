/*
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
示例:
输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-right-side-view
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==nullptr)
            return res;//边界条件 空树直接返回
        queue<TreeNode*> q;//辅助队列
        q.push(root);//根节点入队列
        while(!q.empty())//遍历
        {
            int size=q.size();//当前层的节点个数
            for(int i=0;i<size;i++)//遍历当前层每一个节点
            {
                auto t=q.front();//当前节点
                q.pop();//已遍历
                if(i==size-1)
                    res.push_back(t->val);//如果是最后一个节点 即每一层的最右侧节点 保存
                if(t->left!=nullptr)
                    q.push(t->left);//先左
                if(t->right!=nullptr)
                    q.push(t->right);//后右
            }
        }
        return res;
    }
};
