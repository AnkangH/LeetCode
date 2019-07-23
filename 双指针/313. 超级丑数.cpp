/*
编写一段程序来查找第 n 个超级丑数。
超级丑数是指其所有质因数都是长度为 k 的质数列表 primes 中的正整数。
示例:
输入: n = 12, primes = [2,7,13,19]
输出: 32 
解释: 给定长度为 4 的质数列表 primes = [2,7,13,19]，前 12 个超级丑数序列为：[1,2,4,7,8,13,14,16,19,26,28,32] 。
说明:

1 是任何给定 primes 的超级丑数。
 给定 primes 中的数字以升序排列。
0 < k ≤ 100, 0 < n ≤ 106, 0 < primes[i] < 1000 。
第 n 个超级丑数确保在 32 位有符整数范围内。
*/


class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m=primes.size();
        vector<int> idx(m,0);//记录与primes[i]相乘的丑数在丑数序列中的索引
        vector<int> ugly(n,1);//丑数序列 第一个丑数为1
        for(int i=1;i<n;i++)//求后面n-1个丑数
        {
            vector<int> can(m,0);//m个可能的丑数
            int minVal=INT_MAX;//记录最小值
            for(int j=0;j<m;j++)//当前所有丑数可能值
            {
                can[j]=ugly[idx[j]]*primes[j];
                minVal=min(minVal,can[j]);//取最小的丑数作为当前丑数
            }
            for(int j=0;j<m;j++)
                if(can[j]==minVal)
                    idx[j]++;//指向丑数序列中的下一个丑数
            ugly[i]=minVal;//当前丑数
        }
        return ugly[n-1];//第n个丑数
    }
};
