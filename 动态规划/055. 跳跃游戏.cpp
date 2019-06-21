/*
给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个位置。
示例 1:
输入: [2,3,1,1,4]
输出: true
解释: 从位置 0 到 1 跳 1 步, 然后跳 3 步到达最后一个位置。
示例 2:
输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/jump-game
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//动态规划 逆推法
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int size=nums.size();
        if(size==1)
            return true;
        int gap=1;//gap初始值 倒数第二个数字跳到最后一个数字的最小gap
        for(int i=size-2;i>=1;i--)//从倒数第二个开始遍历到第二个数字
        {
            if(nums[i]>=gap)//能够到达 
                gap=1;//最后的数字向前移动 即当前数字作为最后一个数字
            else
                gap++;//最后的数字不移动 要到达不能通过当前数字 必须从当前数字的前一个跳过当前数字到达最后的数字
        }
        if(nums[0]>=gap)//一直递推到第一个数字 如果第一个数字的值大于等于gap 则可以到达
            return true;
        else
            return false;//否则不能到达
    }
};

//dfs方法  超时
/*
    //dfs的解决方法 case通过100/101个 考虑为什么时间复杂度这么差
    //对于其后的数字 都要dfs（nums[i]）次，如9 9 9 9 9 则需dfs（9*9*9*9*9）次
    //而且不能提前退出 所以时间复杂度太大
    bool canJump(vector<int>& nums) {
        return dfs(nums,0);
    }
    bool dfs(vector<int>& nums,int index)
    {
        int size=nums.size();
        if(index>=size-1)
            return true;
        if(nums[index]==0)
            return false;
        bool res=false;
        for(int i=1;i<=nums[index];i++)
            res=res||dfs(nums,index+i);
        return res;
    }*/
