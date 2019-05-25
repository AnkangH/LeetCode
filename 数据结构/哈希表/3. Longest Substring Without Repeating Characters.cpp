/*
题目：
Given a string, find the length of the longest substring without repeating characters.
Example 1:
Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:
Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:
Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
解析：
给定一个字符串，求不重复字符的最大子字符串（子串为连续序列）长度。
思路1：穷举法。当子串size=字符串size时，只有一种子串；当子串size=字符串size-1时，有两种。遍历并对每个子串判断是否有重复字符。复杂度O(N*N*),超时。
思路2: 因为要判断字符串中是否有重复字符，所以需要哈希表。维护一个大小变化的哈希表，如当有重复元素k出现时，将原哈希表中k之前的所有字符删除，注意这里
在k之前指的是插入哈希表的顺序，由于有序表只能按数值排序，无序表无任何顺序，因此将哈希表中的value设为遍历数组时，该字符的索引，通过索引大小，来判断
插入哈希表的先后顺序。哈希表的大小即为遍历到当前字符时，无重复子串的大小，再用一个变量记录哈希表大小的最大值即为所求的结果。
如abcabcbb
i=0     hash=a      sum=1   res=1
i=1     hash=ab     sum=2   res=2
i=2     hash=abc    sum=3   res=3
i=3     str[3]=a,a插入时，哈希表中已有a，将所有a之前的字符删除 hash=bca sum=3 res=3;
再如 acbbacets
当str[3]=b，b插入时表中已有b，将b之前的所有元素删除，hash=b
如上文所言，哈希表无序，因此要将value值设为字符对应在字符串中的索引，这样当str[3]=b插入时，先判断哈希表中有无该字符，
查到该字符有，且value=2（遍历上个b时，在字符串中的索引）。因此遍历哈希表，将所有value<=2的元素全部删除，再将str[3]=b插入哈希表。
*/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty())
            return 0;//预判断 空字符串返回0
        int size=s.size();
        unordered_map<char,int> m;//辅助哈希表 key储存字符，value为在字符串中的索引 即插入哈希表的先后顺序
        int sum=0;//记录当前哈希表大小即为无重复子串的当前数目
        int res=0;//保存最大值
        for(int i=0;i<size;i++)//遍历字符串
        {
            if(m.count(s[i])==0)//该字符串未出现过
            {
                m[s[i]]=i;//记录该字符插入顺序
                sum=m.size();
                res=max(sum,res);//注意若不使用sum 此处应将m.size()转换为int型再与res取最大值
            }
            else//该字符出现过
            {
                int k=m.find(s[i])->second;//求该字符插入哈希表的顺序
                auto itr=m.begin();
                while(itr!=m.end())
                {
                     if(itr->second<k)//删除所有比该字符先插入哈希表的字符
                        itr=m.erase(itr);//itr在erase后会释放，所以erase之后要给itr赋值 而不能使用itr++
                    else
                        itr++;//未释放itr时可使用itr++指向下一个元素
                }
                m[s[i]]=i;//保存当前字符插入哈希表的顺序
            }
        }
        return res;//返回最大无重复子串长度
    }
};
