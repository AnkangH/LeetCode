/*
给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c + d 的值与 target 相等？
找出所有满足条件且不重复的四元组。
注意：
答案中不可以包含重复的四元组。
示例：
给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
满足要求的四元组集合为：
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/4sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n;i++){
            if(i>0 &&nums[i]==nums[i-1]){
                continue;
            }
            three_sum(nums, res, n, i+1, target-nums[i], nums[i]);
        }
        return res;
    }
    // 三数之和
    void three_sum(vector<int>& nums, vector<vector<int>>& res, int size, int start_idx, int target, int cur_num){
        for(int i=start_idx;i<size;i++){
            if(i>start_idx && nums[i]==nums[i-1]){
                continue;
            }
            int two_sum_target=target-nums[i];
            int left=i+1, right=size-1;
            while(left<right){
                if(nums[left]+nums[right]==two_sum_target){
                    res.push_back(vector<int>{cur_num, nums[i], nums[left], nums[right]});
                    while(left<right){
                        left+=1;
                        if(nums[left]!=nums[left-1]){
                            break;
                        }
                    }
                    while(left<right){
                        right-=1;
                        if(nums[right]!=nums[right+1]){
                            break;
                        }
                    }
                }
                else if(nums[left]+nums[right]<two_sum_target){
                    left+=1;
                }
                else{
                    right-=1;
                }
            }
        }
    }
};
