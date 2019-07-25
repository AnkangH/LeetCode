/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
示例 1:
输入: [10,2]
输出: 210
示例 2:
输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
*/


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);//按照前后放置 数值较大排序
        string res;
        for(auto p:nums)
            res+=to_string(p);//可以组成的最大数字
        if(res[0]=='0')
            return "0";//"0000"转为0
        return res;
    }
    static bool cmp(int a,int b)
    {
        string s1=to_string(a)+to_string(b);//a在b前
        string s2=to_string(b)+to_string(a);//a在b后
        return atol(s1.c_str())>atol(s2.c_str());//字符串可能超int型 所以使用long比较大小
    }
};
