/*
给出一个完全二叉树，求出该树的节点个数。
说明：
完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。
若最底层为第 h 层，则该层包含 1~ 2h 个节点。
示例:
输入: 
    1
   / \
  2   3
 / \  /
4  5 6
输出: 6
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/count-complete-tree-nodes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//递归解法
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
    int countNodes(TreeNode* root) {
        if(root==nullptr)
            return 0;//空指针返回0
        return countNodes(root->left)+countNodes(root->right)+1;//左侧节点个数+右侧节点个数+根节点
    }
};


//迭代解法
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
    int countNodes(TreeNode* root) {
        int res=0;
        if(root==nullptr)
            return res;//边界条件
        queue<TreeNode*> q;//辅助队列
        q.push(root);
        while(!q.empty())
        {
            int size=q.size();
            res+=size;//加当前层节点数
            for(int i=0;i<size;i++)
            {
                TreeNode* t=q.front();//当前节点
                q.pop();//出队列
                if(t->left!=nullptr)
                    q.push(t->left);//放入左节点
                if(t->right!=nullptr)
                    q.push(t->right);//放入右节点
            }
        }
        return res;
    }
};
