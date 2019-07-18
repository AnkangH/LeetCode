/*
编写一个程序，找出第 n 个丑数。
丑数就是只包含质因数 2, 3, 5 的正整数。
示例:
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  
1 是丑数。
n 不超过1690。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/ugly-number-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> ugly(n,1);//丑数数组 第一个丑数为1
        vector<int> idx(3,0);//丑数数组的下标
        for(int i=1;i<n;i++)
        {
            int a=ugly[idx[0]]*2;//第一个索引指向的丑数*2
            int b=ugly[idx[1]]*3;//第二个索引指向的丑数*3
            int c=ugly[idx[2]]*5;//第三个索引指向的丑数*5
            int cur=min(a,min(b,c));//取最小值作为当前丑数
            //跳过重复的数字 比如2*3 3*2 这样在6使用之后 3*i不会再出现6
            //当前和相等的数字 其索引都要指向丑数数组中的下一个数字
            if(cur==a)
                idx[0]++;
            if(cur==b)
                idx[1]++;
            if(cur==c)
                idx[2]++;
            ugly[i]=cur;//当前丑数
        }
        return ugly[n-1];
    }
};
