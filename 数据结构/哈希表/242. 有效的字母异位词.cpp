/*
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
示例 1:
输入: s = "anagram", t = "nagaram"
输出: true
示例 2:
输入: s = "rat", t = "car"
输出: false
说明:
你可以假设字符串只包含小写字母。

进阶:
如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
*/



class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> m(26,0);//记录每个单词出现次数
        for(auto p:s)
            m[p-'a']++;//s中出现的字母 次数+1
        for(auto p:t)
            m[p-'a']--;//t中出现的字母  次数-1
        for(auto p:m)
            if(p!=0)//有不可抵消的字母
                return false;//不是异位词
        return true;//是异位词
    }
};
