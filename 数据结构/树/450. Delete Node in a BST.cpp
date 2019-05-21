/*
题目：
Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.
Note: Time complexity should be O(height of tree).
Example:
root = [5,3,6,2,4,null,7]
key = 3
    5
   / \
  3   6
 / \   \
2   4   7

Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
    5
   / \
  4   6
 /     \
2       7
Another valid answer is [5,2,6,null,4,null,7].
    5
   / \
  2   6
   \   \
    4   7
解析：给定一颗二叉搜索树，删除指定节点。时间复杂度O（n）的留待以后补充。
这里使用非递归的方法。将二叉搜索树转换为序列，判断该节点是否在序列中，若在，从序列中删除该值，重建二叉树。
否则返回原二叉树。注意当序列只有一个元素且要删除该值时，判断序列为空，则说明应该返回空树。
这种方法不是很好，因为对于任意一个值key，最好的情况是该值不在二叉搜索树中。最坏的情况是在二叉搜索树中，需要重建整个二叉树。
一种思路是对于二叉树中要删除的节点，标记它。对于二叉搜索树的查找，只有在该值存在且无标记时，返回true。若该值不在二叉树中或是
该值有标记，那么返回false。
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr)
            return root;
        vector<int>arr;
        layerOrder(root,arr);
        int size=arr.size();
        auto pt=arr.begin();
        for(pt;pt!=arr.end();pt++)//判断key值是否在二叉搜索树中
        {
            if(*pt==key)
                break;
        }
        if(pt!=arr.end())//说明key值在树中
        {
            arr.erase(pt);//删除该值
            return buildTree(arr);//重建二叉树
        }
        else
            return root;//该值不在二叉树中，未对二叉树进行任何操作。
    }
    void layerOrder(TreeNode* root,vector<int>&arr)//返回层次遍历
    {
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode* temp=que.front();
            arr.push_back(temp->val);
            que.pop();
            if(temp->left!=nullptr)
                que.push(temp->left);
            if(temp->right!=nullptr)
                que.push(temp->right);
        }
    }
    TreeNode* buildTree(vector<int> arr)//按照数组重建二叉树。实际是对已有二叉搜索树的搜索。
    {
        if(arr.empty())
            return nullptr;
        int size=arr.size();
        TreeNode* root=new TreeNode(arr[0]);
        for(int i=1;i<size;i++)
        {
            TreeNode* t=root;
            while(t!=nullptr)
            {
                if(t->val>arr[i])
                {
                    if(t->left!=nullptr)
                        t=t->left;
                    else
                    {
                        t->left=new TreeNode(arr[i]);
                        break;
                    }
                }
                if(t->val<arr[i])
                {
                    if(t->right!=nullptr)
                        t=t->right;
                    else
                    {
                        t->right=new TreeNode(arr[i]);
                        break;
                    }
                }
            }
        }
        return root;
    }
};
