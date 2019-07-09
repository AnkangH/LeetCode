/*
给定一个数组，将数组中的元素向右移动 k 个位置，其中 k 是非负数。
示例 1:
输入: [1,2,3,4,5,6,7] 和 k = 3
输出: [5,6,7,1,2,3,4]
解释:
向右旋转 1 步: [7,1,2,3,4,5,6]
向右旋转 2 步: [6,7,1,2,3,4,5]
向右旋转 3 步: [5,6,7,1,2,3,4]
示例 2:
输入: [-1,-100,3,99] 和 k = 2
输出: [3,99,-1,-100]
解释: 
向右旋转 1 步: [99,-1,-100,3]
向右旋转 2 步: [3,99,-1,-100]
说明:
尽可能想出更多的解决方案，至少有三种不同的方法可以解决这个问题。
要求使用空间复杂度为 O(1) 的 原地 算法。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rotate-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//O（logN）
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty())
            return;
        int size=nums.size();
        k=k%size;//每size次旋转 数组复原 因此只需旋转k%size次
        k=size-k;//前k个需要旋转到后面
        reverse(nums,0,k-1);//前k个反转
        reverse(nums,k,size-1);//后size-k个反转
        reverse(nums,0,size-1);//整个数组反转
    }
    void reverse(vector<int>& nums,int start,int end)//反转数组索引start到end的元素
    {
        while(start<end)//交换nums[start]与nums[end]的数值
        {
            int temp=nums[start];//暂存
            nums[start]=nums[end];//交换
            nums[end]=temp;//交换
            start++;//左指针移动
            end--;//右指针移动
        }
    }
};

//O（N） 每个在前的元素顺序移动到后面 时间复杂度很差
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(nums.empty())
            return;
        int size=nums.size();
        k=k%size;
        auto itr=nums.begin();
        int cnt=1;
        while(cnt<=size-k)
        {
            int temp=*nums.begin();
            itr=nums.erase(nums.begin());
            nums.push_back(temp);
            cnt++;
        }
    }
};
