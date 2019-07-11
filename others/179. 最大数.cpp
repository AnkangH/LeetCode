/*
给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
示例 1:
输入: [10,2]
输出: 210
示例 2:
输入: [3,30,34,5,9]
输出: 9534330
说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/largest-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);//使用自定义排序函数进行排序
        string res;
        for(auto p:nums)
            //res+=int2str(p);//int转字符串 组合最后的较大数字
            res+=to_string(p);
        if(res[0]=='0')//首位为0
            res="0";//合法化 全为0
        return res;
    }
    static bool cmp(int a,int b)//快排使用的比较函数
    {
        string s1=to_string(a)+to_string(b);//a在前
        string s2=to_string(b)+to_string(a);//b在前
        return atol(s1.c_str())>atol(s2.c_str());//返回字符串形式较大的数字
    }
};


//使用自定义 int2str str2int
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),cmp);//使用自定义排序函数进行排序
        string res;
        for(auto p:nums)
            res+=int2str(p);//int转字符串 组合最后的较大数字
        if(res[0]=='0')//首位为0
            res="0";//合法化 全为0
        return res;
    }
    static bool cmp(int a,int b)//快排使用的比较函数
    {
        string s1=int2str(a)+int2str(b);//a在前
        string s2=int2str(b)+int2str(a);//b在前
        return str2int(s1)>str2int(s2);//返回字符串形式较大的数字
    }
    static long str2int(string s)//string 转int 为防止求和时超范围 返回long
    {
        long res=0;
        for(auto p:s)
        {
            res*=10;
            res+=p-'0';
        }
        return res;
    }
    static string int2str(int x)//int转string
    {
        string res;
        if(x==0)
            return "0";
        while(x>0)
        {
            res.insert(res.begin(),x%10+'0');
            x/=10;
        }
        return res;
    }
    
};
