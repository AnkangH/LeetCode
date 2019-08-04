/*
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
示例：
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：
如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
*/


class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int size2=t.size();
        if(n<size2)
            return "";//边界条件
        unordered_map<char,int> need;//t中所有字母和出现次数
        for(auto p:t)
            need[p]++;//构建哈希表
        unordered_map<char,int> window;//滑动窗口中t出现的所有字母和出现次数
        int l=0,r=0,cnt=0,minLen=INT_MAX,start=0;//左右指针 滑动窗口中满足的字母个数 最小子串的起始位置和长度
        while(r<n)//右指针不到s末尾
        {
            if(need.count(s[r]))//当前字母在t中
            {
                window[s[r]]++;//加到滑动窗口中
                if(window[s[r]]==need[s[r]])//滑动窗口中该字母已满足要求
                    cnt++;//满足要求的字母计数增加
            }
            while(cnt==need.size())//滑动窗口的中字母已满足要求 移动左指针缩小窗口长度
            {
                if(r-l<=minLen)//当前子串满足要求 且长度较短
                {
                    start=l;//记录起点
                    minLen=r-l;//记录长度
                }
                if(need.count(s[l]))//左指针的字母在t中
                {
                    window[s[l]]--;//将窗口中的该字母计数-1
                    if(window[s[l]]<need[s[l]])//如果窗口中该字母的数目小于t中的数目
                        cnt--;//满足要求的字母-1 即当前窗口不能再缩小
                }
                l++;//否则一直缩小窗口
            }
            r++;//移动右指针
        }
        return minLen==INT_MAX?"":s.substr(start,minLen+1);//l-r+1为s[l,r]
    }
};
