/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:
输入: "race a car"
输出: false
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())
            return true;//空字符串也是回文串
        int size=s.size();
        int l=0,r=size-1;//左右指针起点分别在首尾
        while(l<=r)
        {
            while(!isLegal(s[l])&&l<r)//l<r 所以最终l=r 不会出现越界
                l++;//跳过不合法的字符
            while(!isLegal(s[r])&&l<r)
                r--;//跳过不合法字符
            if(!(s[l]==s[r]||isSameChar(s[l],s[r])))//字符相同 或者是相同字母的大小写
                return false;
            l++;//移动左指针
            r--;//移动右指针
        }
        return true;
    }
    bool isLegal(char s)//判断当前字符是否合法
    {
        if(s-'0'>=0&&s-'0'<=9)
            return true;//数字 合法
        else if(s-'a'>=0&&s-'a'<=25)
            return true;//小写字母 合法
        else if(s-'A'>=0&&s-'A'<=25)
            return true;//大写字母 合法
        else
            return false;//其他 非法
    }
    bool isSameChar(char a,char b)//判断两个字母是否是相同字母 或相同字母的大小写
    {
        if((a-'0'>=0&&a-'0'<=9)||(b-'0'>=0&&b-'0'<=9))
            return false;//排除合法字符中的数字
        else if(a-'a'==b-'a'||a-'A'==b-'a'||a-'a'==b-'A')//字母相同或者大小写相同
            return true;
        else
            return false;
    }
};
