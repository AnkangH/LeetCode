/*
我们从一块字母板上的位置 (0, 0) 出发，该坐标对应的字符为 board[0][0]。
在本题里，字母板为board = ["abcde", "fghij", "klmno", "pqrst", "uvwxy", "z"].
我们可以按下面的指令规则行动：
如果方格存在，'U' 意味着将我们的位置上移一行；
如果方格存在，'D' 意味着将我们的位置下移一行；
如果方格存在，'L' 意味着将我们的位置左移一列；
如果方格存在，'R' 意味着将我们的位置右移一列；
'!' 会把在我们当前位置 (r, c) 的字符 board[r][c] 添加到答案中。
返回指令序列，用最小的行动次数让答案和目标 target 相同。你可以返回任何达成目标的路径。
示例 1：
输入：target = "leet"
输出："DDR!UURRR!!DDD!"
示例 2：
输入：target = "code"
输出："RR!DDRR!UUL!R!"
提示：
1 <= target.length <= 100
target 仅含有小写英文字母。
*/


class Solution {
public:
    unordered_map<char,vector<int>> m;//字母和其矩阵索引
    string alphabetBoardPath(string target) {
        vector<vector<char>> board(6,vector<char>(5));//字母矩阵
        for(int i=0;i<6;i++)
            for(int j=0;j<5;j++)
            {
                if(i==5&&j>0)
                    break;
                board[i][j]='a'+i*5+j;//放置字母
                m[board[i][j]]={i,j};//将字母的索引放入哈希表
            }
        string res;//路径 起点为a
        if(target.empty())
            return res;//边界条件 字符串空 返回空路径
        int n=target.size();//字符串长度
        if(target[0]=='z')//首字母为z 
        {
            res+=path('a','u');//先从a移动到u 
            res+='D';//再从u向下一步
            res+='!';//选取当前字母
        }
        else//首字母不为z
        {
            res+=path('a',target[0]);//求a到首字母的路径
            res+='!';//选取当前字母
        }
        for(int i=1;i<n;i++)//遍历剩余字符串的字母
        {
            if(target[i-1]==target[i])
                res+='!';//重复字母 因为已经到达该处 直接选取字母即可
            else if(target[i-1]=='z')//起点为z
            {
                res+='U';//先向上移动到u
                res+=path('u',target[i]);//再从u移动到终点字母
                res+='!';//选取字母
            }
            else if(target[i]=='z')//终点为z
            {
                res+=path(target[i-1],'u');//先从起点移动到u
                res+='D';//再从u向下移动一步到z
                res+='!';//选取字母
            }
            else//起点和终点均不包含z
            {
                res+=path(target[i-1],target[i]);//从起点移动到终点
                res+='!';//选取字母
            }
        }
        return res;
    }
    string path(char a,char b)
    {
        vector<int> pa=m.find(a)->second;//起点字母的索引
        vector<int> pb=m.find(b)->second;//终点字母的索引
        string res;
        int x=pb[0]-pa[0];//x方向距离
        int y=pb[1]-pa[1];//y方向距离
        for(int i=0;i<abs(x);i++)//先移动至同一行 行和列的先后顺序没有要求
        {
            if(x<0)
                res+='U';//向上
            else
                res+='D';//向下
        }
        for(int i=0;i<abs(y);i++)//再移动至同一列
        {
            if(y<0)
                res+='L';//向左
            else
                res+='R';//向右
        }
        return res;
    }
};
