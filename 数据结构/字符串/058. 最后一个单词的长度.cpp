/*
给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
如果不存在最后一个单词，请返回 0 。
说明：一个单词是指由字母组成，但不包含任何空格的字符串。
示例:
输入: "Hello World"
输出: 5
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/length-of-last-word
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.empty())
            return 0;
        int size=s.size();
        int res=0;
        for(int i=size-1;i>=0;i--)//从后向前
            if(s[i]!=' ')//找到首个字母
            {
                while(i>=0&&s[i]!=' ')//进入循环 往前判断当前字符直至空格或字符串开始
                {
                    res++;//单词包含字母数目增加
                    i--;//向前继续判断
                }
                break;//找到最后一个单词 退出
            }
        return res;//返回结果
    }
};
