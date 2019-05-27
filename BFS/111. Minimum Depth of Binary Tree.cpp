/*
题目：
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.
Example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its minimum depth = 2.
解析：
方法:1：
递归法，根节点的最小深度为min（第1层左子树的深度,第1层右子树的深度）+1，
第一层左子树的深度=min(该左子树根节点的左子树深度，该左子树根节点的右子树深度)+1；
...
递归结束条件，空树深度0.
方法2：
BFS(广度优先搜索)，深度相当于求从根节点出发的最小路径，这里路径定义为节点个数，如上述二叉树最小深度为2-9，节点个数为2，路径长为2。
层序访问二叉树的节点，如果有某个节点没有子节点，那么说明到达最小深度。
*/

//方法一：递归法
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
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int left=minDepth(root->left);
        int right=minDepth(root->right);
        if(left==0||right==0)
            return left+right+1;
        return min(left,right)+1;
    }
};

//方法二 BFS
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
    int minDepth(TreeNode* root) {
        if(root==nullptr)
            return 0;//预判断
        queue<TreeNode*> auxQue;//层序遍历辅助队列
        int res=1;//当前深度1
        auxQue.push(root);//根节点入队列
        while(!auxQue.empty())
        {
            int size=auxQue.size();//当前层的节点个数
            for(int i=0;i<size;i++)//处理当前层
            {
                TreeNode* t=auxQue.front();//当前层当前节点
                auxQue.pop();//当前层当前节点出队列
                if(t->left!=nullptr)
                    auxQue.push(t->left);//左节点入队列
                if(t->right!=nullptr)
                    auxQue.push(t->right);//右节点入队列
                //以上语句为将当前层的下一层所有节点入队列
                //这样循环退出后，队列大小为下一层所有节点数目
                if(t->left==nullptr&&t->right==nullptr)
                    return res;//发现最小深度 BFS退出
            }
            res++;//每遍历完一层 深度+1
        }
        return 0;//满足语法要求，在上述循环中函数已经返回
    }
};
