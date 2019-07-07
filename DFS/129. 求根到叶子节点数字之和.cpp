/*
给定一个二叉树，它的每个结点都存放一个 0-9 的数字，每条从根到叶子节点的路径都代表一个数字。例如，从根到叶子节点路径 1->2->3 代表数字 123。
计算从根到叶子节点生成的所有数字之和。说明: 叶子节点是指没有子节点的节点。
示例 1:
输入: [1,2,3]
    1
   / \
  2   3
输出: 25
解释:
从根到叶子节点路径 1->2 代表数字 12.
从根到叶子节点路径 1->3 代表数字 13.
因此，数字总和 = 12 + 13 = 25.
示例 2:
输入: [4,9,0,5,1]
    4
   / \
  9   0
 / \
5   1
输出: 1026
解释:
从根到叶子节点路径 4->9->5 代表数字 495.
从根到叶子节点路径 4->9->1 代表数字 491.
从根到叶子节点路径 4->0 代表数字 40.
因此，数字总和 = 495 + 491 + 40 = 1026.
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sum-root-to-leaf-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//方法一 不使用回删的回溯法 使用当前更新后的变量副本进行下次dfs
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
    int res=0;
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)
            return 0;//预处理 空树返回0
        dfs(root,0);//dfs
        return res;//返回值
    }
    void dfs(TreeNode* root,int sum)//不回删的回溯 使用副本进行dfs
    {
        sum*=10;//十进制进位
        sum+=root->val;//当前位
        if(root->left==nullptr&&root->right==nullptr)
            res+=sum;//到达叶节点 保存当前和
        if(root->left!=nullptr)
            dfs(root->left,sum);//若有左子树 遍历左子树
        if(root->right!=nullptr)
            dfs(root->right,sum);//若有右子树 遍历右子树
    }
};


//方法二 使用回删的回溯法 退出当函数时 复原变量为进入时的值
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
    int res=0;
    int sumNumbers(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int temp=0;
        dfs(root,temp);
        return res;
    }
    void dfs(TreeNode* root,int& sum)//使用引用而不是副本进行dfs
    {
        sum*=10;//十进制进位
        sum+=root->val;//加当前值
        if(root->left==nullptr&&root->right==nullptr)
            res+=sum;//到达叶节点 保存当前和
        if(root->left!=nullptr)
            dfs(root->left,sum);//左子树非空 遍历左子树
        if(root->right!=nullptr)
            dfs(root->right,sum);//右子树非空 遍历右子树
        sum-=root->val;//回删当前个位
        sum/=10;//回删十位
    }
};
