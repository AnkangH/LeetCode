/*
给定一个二叉树，返回所有从根节点到叶子节点的路径。
说明: 叶子节点是指没有子节点的节点。
示例:
输入:

   1
 /   \
2     3
 \
  5
输出: ["1->2->5", "1->3"]
解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-paths
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
    vector<string> res;//最终结果
    string interval="->";//间隔符
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==nullptr)
            return res;//空树直接返回
        string temp;
        dfs(temp,root);//回溯法
        return res;
    }
    void dfs(string& temp,TreeNode* root)
    {
        string cur=to_string(root->val);//当前数字转字符串
        int size1=cur.size();//记录长度
        temp+=cur;//添加到当前路径中
        temp+=interval;//添加间隔符
        if(root->left==nullptr&&root->right==nullptr)//叶节点
        {
            int size=temp.size();//当前长度
            res.push_back(temp.substr(0,size-2));//删除最后添加的间隔符
        }
        if(root->left!=nullptr)
            dfs(temp,root->left);//遍历左子树
        if(root->right!=nullptr)
            dfs(temp,root->right);//遍历右子树
        int size=temp.size();//当前长度
        temp=temp.substr(0,size-size1-2);//回溯 删除本轮添加的字符和间隔符
    }
};
