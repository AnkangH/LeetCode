/*
给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
例如:
给定二叉树: [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：
[
  [3],
  [9,20],
  [15,7]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-level-order-traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root==nullptr)
            return res;//预处理 空树直接返回
        queue<TreeNode*> q;//辅助队列 先入先出
        q.push(root);//根节点入队列
        while(!q.empty())//遍历每一层
        {
            int size=q.size();//本层的节点个数
            vector<int> temp;//本层的节点顺序
            for(int i=0;i<size;i++)//遍历本层每个节点
            {
                TreeNode* t=q.front();//当前节点
                q.pop();
                temp.push_back(t->val);//保存值
                if(t->left!=nullptr)
                    q.push(t->left);//左子树入队列
                if(t->right!=nullptr)
                    q.push(t->right);//右子树入队列
            }
            res.push_back(temp);//本层的节点顺序
        }
        return res;
    }
};
