/*
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。
示例：
给定二叉树 [3,9,20,null,null,15,7]，
    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/maximum-depth-of-binary-tree
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
    int maxDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int depth=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())//遍历每层节点
        {
            int size=q.size();//当前层的节点个数
            for(int i=0;i<size;i++)//访问每个节点
            {
                TreeNode* t=q.front();//当前节点
                q.pop();
                if(t->left!=nullptr)
                    q.push(t->left);//下一层的左节点
                if(t->right!=nullptr)
                    q.push(t->right);//下一层的右节点
            }
            depth++;//当前层数
        }
        return depth;
    }
};
