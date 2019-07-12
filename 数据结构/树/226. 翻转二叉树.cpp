/*
翻转一棵二叉树。
示例：
输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：
     4
   /   \
  7     2
 / \   / \
9   6 3   1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/invert-binary-tree
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
    TreeNode* invertTree(TreeNode* root) {
        if(root==nullptr)
            return root;//边界条件 空树直接返回
        queue<TreeNode*> q;//辅助队列实现层序遍历
        q.push(root);//根节点入队列
        while(!q.empty())//遍历所有节点
        {
            TreeNode* t=q.front();//当前节点
            q.pop();
            TreeNode* temp=t->left;//保存左节点
            t->left=t->right;//修改左节点
            t->right=temp;//修改右节点
            if(t->left!=nullptr)
                q.push(t->left);//非空左子节点入队列
            if(t->right!=nullptr)
                q.push(t->right);//非空右子节点入队列
        }
        return root;//翻转完成
    }
};
