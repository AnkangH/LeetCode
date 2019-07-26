/*
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
示例:
输入: [5,2,6,1]
输出: [2,1,1,0] 
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.
*/


class Solution {
public:
    struct TreeNode
    {
        int val;
        int count;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x)
        {
            val=x;
            count=0;//记录该节点左子树的节点个数
            left=nullptr;
            right=nullptr;
        }
    };
    TreeNode* root=nullptr;
    vector<int> countSmaller(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int> res(n);
        for(int i=n-1;i>=0;i--)
            res[i]=insertTreeNode(nums[i]);//从右向左插入
        return res;
    }
    int insertTreeNode(int val)
    {
        int cnt=0;
        if(root==nullptr)
            root=new TreeNode(val);
        else
        {
            TreeNode* cur=root;//根节点开始 使用副本寻找插入点
            while(1)
            {
                if(cur->val<val)//待插入的节点值比当前值大 应放到右子树
                {
                    cnt=cnt+cur->count+1;//cur节点左子树的节点个数+ cur节点
                    if(cur->right==nullptr)
                    {
                        cur->right=new TreeNode(val);//该节点为空 插入新节点
                        break;//退出
                    }
                    else
                        cur=cur->right;//该节点存在 移动至该节点
                }
                else//待插入的节点值小于等于当前值 应放到左子树
                {
                    cur->count++;//经过的路径 其左子树节点个数+1
                    if(cur->left==nullptr)
                    {
                        cur->left=new TreeNode(val);//该节点为空 插入新节点
                        break;//蕊初
                    }
                    else
                        cur=cur->left;//该节点非空  移动至该节点
                }
            }
        }
        return cnt;//返回向右移动时 经过的节点及其左子树个数
    }
};
