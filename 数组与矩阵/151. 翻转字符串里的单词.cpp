/*
给定一个字符串，逐个翻转字符串中的每个单词。
示例 1：
输入: "the sky is blue"
输出: "blue is sky the"
示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
说明：
无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/reverse-words-in-a-string
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    string reverseWords(string s) {
        string res;//反转结果
        int size=s.size();
        string temp;//保存一个单词
        for(int i=size-1;i>=0;i--)//从后向前遍历
        {
            if(s[i]==' '&&!temp.empty())//遇到空格 且单词非空
            {
                reverse(temp.begin(),temp.end());//反转当前单词
                temp+=' ';//增加一个空格
                res+=temp;//保存当前单词到最终结果
                temp.clear();//清空当前单词
            }
            else if(s[i]!=' ')//非空格字符
            {
                temp+=s[i];//放入当前单词暂存
                if(i==0)//当前是非空格字符 且到达字符串头
                {
                    reverse(temp.begin(),temp.end());//反转当前单词
                    res+=temp;//放入结果 不增加空格
                }
            }
        }
        int sizeRes=res.size();
        if(res[sizeRes-1]==' ')//因为字符串头可能为很多空格 这样最后一个添加的单词会多一个空格
            res.pop_back();//如果反转结果最后为空格 将其删除
        return res;
    }
};
