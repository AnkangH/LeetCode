/*
题目：
Given a sorted array consisting of only integers where every element appears exactly twice except for one element 
which appears exactly once. Find this single element that appears only once.
Example 1:
Input: [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:
Input: [3,3,7,7,10,11,11]
Output: 10
Note: Your solution should run in O(log n) time and O(1) space.
解析：
有序数组中，只有一个数字出现了一次，其他数字均出现了两次。找出这个只出现了一次的数组。
有序数组的查找，想到折半查找法。判断出现次数，想到哈希表。
因为题目要求时间复杂度O(longn)，空间复杂度O(1),因此只能使用折半查找法。
对输入数据进行分析。
[1,1,2,3,3,4,4,8,8]
l=0，r=8，共9个数字。mid=4为偶数，且mid将数组分为前后两部分，两部分的数目均为偶数。那么如果
nums[mid]=nums[mid-1]，说明前部分与nums[mid]不同的数字只有奇数个，则要查找的数字必在前部分。
同理若nums[mid]==nums[mid+1],则说明要查找的数字在后部分。若nums[mid]!=nums[mid-1]&&
nnums[mid]!=nums[mid+1]，说明nums[mid]就是只出现了一次的数字。
[3,3,7,7,10,11,11]
l=0,r=6,共7个数字，mid=3为奇数，此时若nums[mid]==nums[mid]-1，则前面部分剩余偶数个数字，要查找的数字
一定在后半部分，同理若nums[mid]==nums[mid+1]，说明后部分剩余偶数个，要查找的数字一定在前半部分。
边界条件 当mid==0时，说明nums[0]为只出现一次的数字，同理当mid=size-1时，说明nums[size-1]为只出现了一次
的数字。
边界条件是否带=号，更新条件是mid+1还是mid可以通过特殊值的方式确定。这里因为分析结束，通过几个特殊case即可确定
边界条件和更新条件的正确性。
*/
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1;//数组第一个元素和最后一个元素的索引
        while(l<=r)//[1,1,2]特殊case确定 l=r=2时才能使mid=2
        {
            int mid=l+(r-l)/2;//折半
            if(mid==0)
                return nums[mid];//边界条件
            if(mid==nums.size()-1)
                return nums[mid];//边界条件
            if(mid%2==1)//mid为奇数
            {
                if(nums[mid]==nums[mid-1])
                    l=mid+1;//在后半部
                else if(nums[mid]==nums[mid+1])
                    r=mid-1;//在前半部
                else
                    return nums[mid];//说明该数字只出现一次
            }
            if(mid%2==0)//mid为偶
            {
                 if(nums[mid]==nums[mid-1])
                    r=mid-1;//在前半部分
                else if(nums[mid]==nums[mid+1])
                    l=mid+1;//在后半部分
                else
                    return nums[mid];//说明该数字只出现一次
            }
        }
        return 0;//函数必须要有返回值，在case满足的情况下上述代码必已经返回，所以这句不会执行，只是满足语法要求。
                 //同时此处可设置特殊返回值，指代case不正确，如数组数目非奇数等。
    }
};
