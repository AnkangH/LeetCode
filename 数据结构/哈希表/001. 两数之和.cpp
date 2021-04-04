/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/


//时间复杂度O(N)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> dict;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(dict.count(target-nums[i])==0)
                dict[nums[i]]=i;//不构成两数之和 放入哈希表
            else
                return {i,dict.find(target-nums[i])->second};//构成两数之和 返回该组合
        }
        return {};
    }
};

// 2021/4/4复习
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //哈希表查找 时间复杂度o(n)
        map<int, int> exists;
        vector<int> result;
        // 建立哈希表 处理多个相等元素=target/2的边界情况
        for(int i=0;i <nums.size();i++){
            auto itr = exists.find(target-nums[i]);
            if(itr!=exists.end()){
                return vector<int> {i, itr->second};
            }
            exists.insert(pair<int, int>(nums[i],i));
        }
        //下面的遍历也可以放入上面的遍历中 做优化 实际上 如果a+b=target那么无论a b谁在前不影响
        //查a时 b不在， 也可以在查b时 a在这种情况找到该解
        // 对每个元素 哈希表查找target-num
//         for(int i=0;i<nums.size();i++){
//             auto itr=exists.find(target-nums[i]);
//             if(itr!=exists.end()){
//                 return vector<int> {i, itr->second};
//             }
//         }
        return result;
    }
};
/*  1. pair<int, int> a(1,2); 代表初始化时传入的参数 因为pair的构造函数接受两个参数
        pair<int, int> a{1, 2}; 列表初始化
    2. stl相关数据结构的操作 迭代器itr 遍历写法等
*/
