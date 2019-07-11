/*
编写一个算法来判断一个数是不是“快乐数”。
一个“快乐数”定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，然后重复这个过程直到这个数变为 1，也可能是无限循环但始终变不到 1。
如果可以变为 1，那么这个数就是快乐数。
示例: 
输入: 19
输出: true
解释: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/happy-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,bool> m;
        while(n!=1)//平方和为1
        {
            int temp=0;//重新计算平方和
            while(n>0)
            {
                temp+=(n%10)*(n%10);//当前位的平方
                n/=10;//获取下一位
            }
            n=temp;//赋值 准备下次循环
            if(m.count(temp)==0)//第一次出现
                m[temp]=true;//标记该数字
            else//当前数字出现过一次 那么会一直死循环
                return false;//不能到达平方和为1 返回false
        }
        return true;//res==1退出，所以是快乐数
    }
};
