/*
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
示例:
输入: [0,1,0,3,12]
输出: [1,3,12,0,0]
说明:
必须在原数组上操作，不能拷贝额外的数组。
尽量减少操作次数。
*/


//方法1 删除0元素 在数组后面添加0 时间复杂度  O(KlogN+K)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        auto itr=nums.begin();//删除元素 使用迭代器遍历
        int cnt=0;//记录0的个数
        while(itr!=nums.end())//遍历数组
        {
            if(*itr==0)//0
            {
                itr=nums.erase(itr);//删除0 迭代器后移
                cnt++;//计数增加
            }
            else
                itr++;//非0 迭代器后移
        }
        for(int i=0;i<cnt;i++)
            nums.push_back(0);//在数组后添加0
    }
};


//方法2 双指针方法 时间复杂度O(n+k)
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx=0;//非零元素的索引
        int n=nums.size();
        for(auto p:nums)//遍历数组
            if(p!=0)
            {
                nums[idx]=p;//非零元素放到正确位置
                idx++;//非零元素索引后移
            }
        for(int i=idx;i<n;i++)
            nums[i]=0;//后面的k个元素置为0
    }
};
