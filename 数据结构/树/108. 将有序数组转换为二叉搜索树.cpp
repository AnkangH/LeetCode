/*
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree
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
    int size;
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        size=nums.size();
        return buildTree(nums,0,size-1);
    }
    TreeNode* buildTree(vector<int>& nums,int l,int r)
    {
        int mid=(r-l)/2+l;
        if(r<l)
            return nullptr;//作为叶节点的子节点
        TreeNode* t=new TreeNode(nums[mid]);//当前节点
        t->left=buildTree(nums,l,mid-1);//当前节点的左子节点
        t->right=buildTree(nums,mid+1,r);//当前节点的右子节点
        return t;//返回当前节点
    }
};
