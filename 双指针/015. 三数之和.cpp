/*
给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/


//双指针解法 判断当前组合是否重复
class Solution {
public:
    int n;
    vector<int> last;//保留上一个组合
    vector<vector<int>> res;//可能组合
    vector<vector<int>> threeSum(vector<int>& nums) {
        n=nums.size();
        if(n<3)
            return res;//数字数目小于3 返回空
        sort(nums.begin(),nums.end());//排序
        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;//相同数字的组合相同 跳过
            twoSum(nums,i);
        }
        return res;
    }
    void twoSum(vector<int>&nums,int index)//寻找两数之和等于-nums[index]
    {
        int target=-nums[index];//当前目标值
        int l=index+1,r=n-1;//向后查找 跳过一些重复值
        while(l<r)
        {
            int cur=nums[l]+nums[r];
            if(cur<target)
                l++;
            else if(cur>target)
                r--;
            else
            {
                vector<int> cur={nums[index],nums[l],nums[r]};//当前组合
                if(res.empty()||!isSameVector(last,cur))//组合为空或者不与上一个组合相同
                {
                    res.push_back(cur);//放入组合
                    last=cur;//更新上一个组合
                }
                l++;
                r--;
            }
        }
    }
    bool isSameVector(vector<int>& a,vector<int>& b)//判断两个三数组合是否相同
    {
        if(a[0]==b[0]&&a[1]==b[1]&&a[2]==b[2])
            return true;
        return false;
    }
};


//双指针解法  使用set将重复组合删去
class Solution {
public:
    int n;
    set<vector<int>> s;//集合  只保留不重复组合
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        n=nums.size();
        if(n<3)
            return res;//数组个数小于3 退出
        sort(nums.begin(),nums.end());//排序
        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            twoSum(nums,i);//对当前数字寻找两数之和
        }
        for(auto p:s)
            res.push_back(p);//从集合中取出所有互异集合
        return res;
    }
    void twoSum(vector<int>&nums,int index)//寻找两数之和=-nums[index]
    {
        int target=-nums[index];
        int l=index+1,r=n-1;
        while(l<r)
        {
            int cur=nums[l]+nums[r];
            if(cur<target)
                l++;
            else if(cur>target)
                r--;
            else
            {
                s.insert({nums[index],nums[l],nums[r]});//可能组合放入集合中
                l++;
                r--;
            }
        }
    }
};


//双指针 移动指针去重
class Solution {
public:
    vector<vector<int>> res;
    int n;
    vector<vector<int>> threeSum(vector<int>& nums) {
        n=nums.size();
        if(n<3)
            return res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(i>0&&nums[i]==nums[i-1])
                continue;
            twoSum(nums,i);
        }
        return res;
    }
    void twoSum(vector<int>& nums,int index)
    {
        int target=-nums[index];
        int l=index+1;
        int r=n-1;
        while(l<r)
        {
            while(l>index+1&&nums[l]==nums[l-1])//跳过重复组合
            {
                l++;
                if(l==r)
                    return;
            }
            while(r<n-1&&nums[r]==nums[r+1])//跳过重复组合
            {
                r--;
                if(l==r)
                    return;
            }
            int cur=nums[l]+nums[r];
            if(cur<target)
                l++;
            else if(cur>target)
                r--;
            else
            {
                res.push_back({nums[index],nums[l],nums[r]});
                l++;
                r--;
            }
        }
    }
};

//2021.4.17 同上
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // 排序后双指针查找和为nums[i]
        // 排序后 相同数值跳过 且查找范围为(i+1,n) 即每个数字只找右侧（比自己大的数值）
        // 从而去重 以及减少查找次数
        sort(nums.begin(), nums.end());
        int n=nums.size();
        vector<vector<int>> res;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int target = -nums[i];
            int left=i+1;
            int right=n-1;
            while(left<right){
                //找到一组答案
                if(nums[left]+nums[right]==target){
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    // left向右找第一个不等于当前nums[left]的值
                    while(left<right){
                        left+=1;
                        if(nums[left]!=nums[left-1]){
                            break;
                        }
                    }
                    // right向左找 第一个不等于当前nums[right]的值
                    while(left<right){
                        right-=1;
                        if(nums[right]!=nums[right+1]){
                            break;
                        }
                    }
                }
                // 当前和小于目标值 左指针右移 增大和
                else if(nums[left]+nums[right]<target){
                    left+=1;
                }
                // 当前和大于目标值 右指针左移 减小和
                else{
                    right-=1;
                }
            }
        }
        return res;
    }
};
