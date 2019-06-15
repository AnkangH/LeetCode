/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
示例 1:
输入: ["flower","flow","flight"]
输出: "fl"
示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-common-prefix
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";//预判断
        int size=strs.size();
        string temp=strs[0];
        for(int i=1;i<size;i++)//找输入字符串数组中 长度最短的字符串
        {
            int sizeNow=strs[i].size();
            int sizeTemp=temp.size();
            if(sizeNow<sizeTemp)
                temp=strs[i];
        }
        int sizeMin=temp.size();
        vector<int> map(sizeMin,size);//记录每个字符的公共个数 
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<sizeMin;j++)
            {
                if(strs[i][j]!=temp[j])//每个字符串的当前字符与最短字符串当前字符不相同
                    map[j]--;//公共字符串数目-1
            }
        }
        int index=sizeMin;
        for(int i=0;i<sizeMin;i++)//找最后一个公共字符所在的位置
        {
            if(map[i]==size)
                index=i;
            else
                break;
         }
        if(index==sizeMin)//无公共字符
            return "";
        else
            return temp.substr(0,index+1);//返回最短字符串从开始到最后一个公共字符的字符串
    }
};
