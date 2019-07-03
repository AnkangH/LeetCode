/*
格雷编码是一个二进制数字系统，在该系统中，两个连续的数值仅有一个位数的差异。
给定一个代表编码总位数的非负整数 n，打印其格雷编码序列。格雷编码序列必须以 0 开头。
示例 1:
输入: 2
输出: [0,1,3,2]
解释:
00 - 0
01 - 1
11 - 3
10 - 2
对于给定的 n，其格雷编码序列并不唯一。
例如，[0,2,3,1] 也是一个有效的格雷编码序列。
00 - 0
10 - 2
11 - 3
01 - 1
示例 2:
输入: 0
输出: [0]
解释: 我们定义格雷编码序列必须以 0 开头。
     给定编码总位数为 n 的格雷编码序列，其长度为 2n。当 n = 0 时，长度为 20 = 1。
     因此，当 n = 0 时，其格雷编码序列为 [0]。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/gray-code
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

//方法一 公式法
class Solution {
public:
    vector<int> grayCode(int n) {
        //g(i)=i^(i/2)
        vector<int> res;
        for(int i=0;i<(1<<n);i++)//0~2exp(n)-1
            res.push_back(i^(i>>2));
        return res;
    }
    
};


//方法二 回溯法 注意使用二进制每一位不同的数字来构建枝 这样大大减小规模
class Solution {
public:
    int total=0;
    int numN=0;
    vector<int> res;
    vector<int> grayCode(int n) {
        if(n==0)
            return {0};
        numN=n;//n的数值 为了降低时间复杂度 使用全局变量
        total=1<<n;//总的数字 2exp(n)个
        vector<int> temp;
        vector<bool> known(total,false);
        dfs(temp,known,0);
        return res;
    }
    bool dfs(vector<int>& temp,vector<bool>& known,int index)
    {
        temp.push_back(index);
        int size=temp.size();
        if(size==total)//得到一个结果
        {
            res=temp;
            return true;
        }
        known[index]=true;//标记已使用该数字
        vector<int> nxt=help(index);//构建n个枝
        bool flag=false;
        for(int i=0;i<numN;i++)
            if(!known[nxt[i]])//对未使用的枝进行dfs
            {
                flag=flag||dfs(temp,known,nxt[i]);
                if(flag)
                    return true;//获取一条路径后提前退出
            }
        if(!flag)//该路径不符合
        {
            known[index]=false;//回溯已读标记
            temp.pop_back();//回溯路径
        }
        return flag;
        
    }
    vector<int> help(int a)//对于整数a和位数n，构建n个二进制每一位不同的数字
    {
        vector<int> res;
        int temp=a;
        for(int i=0;i<numN;i++)
        {
            if(temp&1==1)//第i位为1
                res.push_back(a-(1<<i));
            else//第i位为0
                res.push_back(a+(1<<i));
            temp=temp>>1;
        }
        return res;
    }
};
