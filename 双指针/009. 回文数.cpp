/*
判断一个整数是否是回文数。回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。
示例 1:
输入: 121
输出: true
示例 2:
输入: -121
输出: false
解释: 从左向右读, 为 -121 。 从右向左读, 为 121- 。因此它不是一个回文数。
示例 3:
输入: 10
输出: false
解释: 从右向左读, 为 01 。因此它不是一个回文数。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


//方法一: 使用to_string(),对字符串进行判断
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)//负数一定是非回文
            return false;//预判断 可以将很大的负数提前排除 减少时间复杂度
        string str=to_string(x);//int转字符串
        int r=str.size()-1;//右指针
        int l=0;//左指针
        while(l<r)
        {
            if(str[l]!=str[r])//判断相同字符
                return false;//有一不同即为非回文
            l++;
            r--;
        }
        return true;//若上述未返回false 则为回文
    }
};

//方法二： 对数值进行判断
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        vector<int> dec;//保存每一位的十进制数字
        while(x>0)//求每一位十进制数字 若是回文 那么高低位交换不影响
        {
            dec.push_back(x%10);
            x/=10;
        }
        int size=dec.size();
        int l=0,r=size-1;//双指针判断是否对称
        while(l<r)
        {
            if(dec[l]!=dec[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
};
