/*
给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

示例 1:
输入: word1 = "horse", word2 = "ros"
输出: 3
解释: 
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

示例 2:
输入: word1 = "intention", word2 = "execution"
输出: 5
解释: 
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/edit-distance
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1==word2)
            return 0;//相同单词 不需变换
        int m=word1.size();//单词1长度
        int n=word2.size();//单词2长度
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));//word1前i个转换为word2前j个所需最少操作
        dp[0][0]=0;//dp起始值
        for(int i=1;i<=m;i++)
            dp[i][0]=i;//删除word1前i个 共i次
        for(int i=1;i<=n;i++)
            dp[0][i]=i;//word1添加word2前i个 共i次
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            {
                int a=dp[i-1][j]+1;//由dp[i-1][j]->dp[i][j] 即删除word1[i-1] 次数+1
                int b=dp[i][j-1]+1;//由dp[i][j-1]->dp[i][j] 在word1[i-1]后面添加word2[j-1] 次数+1
                int c;//由dp[i-1][j-1]->dp[i][j]
                if(word1[i-1]==word2[j-1])//由dp[i-1][j-1]->dp[i][j] 次数+0  注意索引对齐 word[i]->i+1
                    c=dp[i-1][j-1];
                else
                    c=dp[i-1][j-1]+1;//修改word1[i-1]=word2[j-1] 次数+1
                dp[i][j]=min(a,min(b,c));//取当前修改次数的最小值
            }
        return dp[m][n];
    }
};



//2021.4.11
class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()==0){
            return word2.size();
        }
        if(word2.size()==0){
            return word1.size();
        }
        //dp[i][j]为s1(0,i)->s2(0,j)所需的最小变换次数
        //dp[i][j]=     min( dp[i-1][j] i-1->j（i位置的字符多余）删除word1[i]即可
        //                   dp[i][j-1] i->j-1 （说明i字符不够，在i位置后面增加一个字符串）令word1[i+1]=word2[j]
        //                   dp[i-1][j-1] i-1能到j-1 如果word1[i]!=word2[j] 修改word1[i]==word2[j]即可 否则不需改动
        int m=word1.size();
        int n=word2.size();
        //word1前i个变为空字符串 需要变i次 指删除i次word1字符操作
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=0;i<=m;i++){
            dp[i][0]=i;
        }
        //word2前i个字符变为空字符 需要变i次 指删除i个word2字符操作 等价于word1增加i个字符
        for(int i=0;i<=n;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=min(dp[i-1][j], dp[i][j-1]) + 1;
                    dp[i][j]=min(dp[i][j], dp[i-1][j-1]);
                    // std::cout<<"eq,i="<<i<<",j="<<j<<",dp[i][j]="<<dp[i][j]<<std::endl;
                }
                else{
                    dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
                    dp[i][j]=min(dp[i][j],dp[i-1][j-1]) + 1;
                    // std::cout<<"neq,i="<<i<<",j="<<j<<",dp[i][j]="<<dp[i][j]<<std::endl;
                }
            }
        return dp[m][n];
    }
};
