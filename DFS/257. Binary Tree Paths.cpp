/*
Given a binary tree, return all root-to-leaf paths.
Note: A leaf is a node with no children.
Example:
Input:

   1
 /   \
2     3
 \
  5
Output: ["1->2->5", "1->3"]
Explanation: All root-to-leaf paths are: 1->2->5, 1->3
解析： 给定一颗二叉树 返回所有根节点到叶节点的路径。返回值类型为vector<string> 节点值有正有负且有多位，节点值之间添加"->"。
DFS搜索，顺序先左后右。有两个需要注意的问题。
一是当前节点的添加"->"，设置为进入递归后再增加"->"，否则最后返回值会多一个"->"。
二是回溯的问题。左右节点递归返回后，需要顺序执行之后得到语句，此时要把后面节点添加的字符串删去，如果在递归函数中声明变量并保存添加的字符串
长度，那么无法实现回溯，因为后面节点返回后，后面节点函数中保存添加字符串长度的变量就释放了，当前函数中的变量是当前函数中添加字符串的长度。
解决办法是让递归函数有一个返回值，记录递归返回前那一轮中添加的字符串的长度。如-100->20->-50。从-50返回后，应将字符串删去-50，如果不使用返回值，
那么当前函数中的变量记录的是20的长度2而不是-50的长度3，因而无法实现。
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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> str;
        if(root==nullptr)
            return str;
        string temp;
        dfs(root,str,temp);
        return str;
    }
    int dfs(TreeNode* root, vector<string>& arr,string& temp)
    {
        string s=to_string(root->val);
        temp+=s;//记录的应是添加的字符串长度 所以必须用返回值
        //如 100->20 回溯时 如果不用返回值 那么size记录的是100的长度3
        //而不是20的长度2 递归的特性 在递归中声明的函数记录的是当前函数中的值
	    if (root->left == nullptr&&root->right == nullptr)
		    arr.push_back(temp);
	    if (root->left != nullptr)
	    {
		    temp += "->";
		    int length=dfs(root->left, arr, temp);
            //回溯 length是添加的字符串长度 2是符号"->"的长度
		    temp = temp.substr(0, temp.size()- length-2);
	    }
	    if (root->right != nullptr)
	    {
		    temp += "->";
		    int length=dfs(root->right, arr, temp);
            //回溯 length是添加的字符串长度 2是符号"->"的长度
            temp = temp.substr(0, temp.size()- length-2);
	    }
        return s.size();//返回值 当前轮添加的字符串长度
    }
};
