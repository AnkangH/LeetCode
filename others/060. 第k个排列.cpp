/*
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。
说明：
给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:
输入: n = 3, k = 3
输出: "213"
示例 2:
输入: n = 4, k = 9
输出: "2314"
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/permutation-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    string getPermutation(int n, int k) {
        k--;//使用k-1做整数除法有规律
        int index;//指代当前位在数组中的索引
        string res;
        vector<int> num;
        for(int i=1;i<=n;i++)
            num.push_back(i);//初始值 有序数列1-n
        for(int i=1;i<=n;i++)//共n位数字
        {
            index=k/help(n-i);//求当前位 除(n-i)!
            res+=num[index]+'0';//当前位数字
            num[index]=n+1;//修改使用的数字 防止重复使用 赋值比n大即可
            sort(num.begin(),num.end());//排序 未使用的数字确定先后关系
            k=k-index*help(n-i);//更新index 即小范围内再确定
        }
        return res;
    }
    int help(int n)//计算n的阶乘
    {
        int res=1;
        while(n>0)
        {
            res*=n;
            n--;
        }
        return res;
    }
};
