/*
实现 strStr() 函数。
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2
示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/implement-strstr
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一 暴力法
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack.empty())
            return -1;
        int sizeH=haystack.size();
        int sizeN=needle.size();
        for(int i=0;i<sizeH;i++)
        {
            if(haystack[i]==needle[0])
            {
                if(haystack.substr(i,sizeN)==needle)
                    return i;
            }
        }
        return -1; 
    }
};

//方法二 KMP
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.empty())
            return 0;
        if(haystack.empty())
            return -1;
        int sizeN=needle.size();
        vector<int>next(sizeN+1);
        int i=0,j=-1;
        next[0]=-1;
        while(i<sizeN)//构建next匹配表也就是needle字符串对自身匹配的过程
        {
            if(j==-1||needle[i]==needle[j])
            {
                i++;
                j++;
                next[i]=j;
            }
            else
                j=next[j];
        }
        int sizeH=haystack.size();
        i=0,j=0;
        while(i<sizeH&&j<sizeN)
        {
            if(j==-1||haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            else
                j=next[j];
        }
        if(j==sizeN)//needle最后一个字符也匹配 第一次匹配成功
            return i-j;
        else
            return -1;
    }
};
