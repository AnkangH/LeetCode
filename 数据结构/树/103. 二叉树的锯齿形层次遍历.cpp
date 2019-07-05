/*
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
例如：
给定二叉树 [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：
[
  [3],
  [20,9],
  [15,7]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        bool dir=false;//标记当前层的访问顺序
        vector<vector<int>> res;
        if(root==nullptr)
            return res;//预处理 空树直接返回
        queue<TreeNode*> q;//辅助队列 模拟节点的先入先出
        q.push(root);//根节点入队列
        while(!q.empty())//访问每层节点
        {
            int size=q.size();//当前层节点的个数
            vector<int> temp;//当前层节点值的序列
            for(int i=0;i<size;i++)//访问当前层每个节点
            {
                TreeNode* t=q.front();
                q.pop();
                if(dir)
                    temp.insert(temp.begin(),t->val);//倒序访问 放到前面
                else
                    temp.push_back(t->val);//顺序访问 放到后面
                if(t->left!=nullptr)
                    q.push(t->left);//先入左子树
                if(t->right!=nullptr)
                    q.push(t->right);//再入右子树
            }
            res.push_back(temp);//当前层节点值序列
            dir=!dir;//访问顺序取反 下次的顺序与本次不同
        }
        return res;
    }
};
