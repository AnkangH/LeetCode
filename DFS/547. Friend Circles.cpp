/*
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. 
For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined
a friend circle is a group of students who are direct or indirect friends.
Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and 
jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles 
among all the students.
Example 1:
Input: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
Output: 2
Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. 
The 2nd student himself is in a friend circle. So return 2.
Example 2:
Input: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
Output: 1
Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, 
so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
Note:
N is in range [1,200].
M[i][i] = 1 for all students.
If M[i][j] = 1, then M[j][i] = 1.
解析：给定一个N阶方阵m m[i][j]=1代表i和j是朋友关系，朋友关系可传递，即若0和1是朋友，1和2是朋友，那么0和2是朋友；又0和1是朋友，0和2朋友，那么
1和2是朋友。互相为朋友的同学在一个朋友圈里，判断有多少个朋友圈。
方法一：不相交集类。 
创建N个集类，每个同学在一个集类里，若m[i][j]==1，那么将i所在的集类合并为一个集类。最后，集类的个数即为朋友圈的数目。
注意因为m[i][j]=m[j][i]，又m[i][i]=1，所以从对角线开始，搜索左下角矩阵即可。
方法二：DFS & bool型记录表.
对每个同学，如果有朋友，那么搜索朋友的朋友。边界条件，使用一个bool变量记录每个同学是否已在某个朋友圈里。注意朋友圈只有一个同学的情况，也是一个朋友圈。
对每个同学，搜索一列确定其朋友，再去搜索朋友所在的列，即朋友的朋友。先判断该同学是否在某个朋友圈中，即bool数组的真假，若不在，那么朋友圈数+1，遍历该列确定其朋友，并把所有朋友设为在某个
朋友圈中。
方法三： DFS&修改矩阵
同方法二。但是不利用bool型数组保存每个同学是否在某个朋友圈中，而是利用m[i][i]的0-1来代表是否在某个朋友圈中，从搜索开始，如从i开始按列
搜索，有m[j][i]=1，那么修改m[i][j]=m[j][i]=0防止重复访问，同时将m[j][j]设为0，标志同学j已在某个朋友圈中。这样遍历m[i][i]，若为1，将所有其同学
以及同学的同学设为0，统计m[i][i]中1个个数即可。
*/

//方法一：不相交集类
class Solution {
public:
    int findCircleNum(vector<vector<int>>& m) {
        unordered_map<int,int> union_find;//记录每个同学所在的朋友圈
        int n=m.size();
        if(n==0)
            return 0;
        for(int i=0;i<n;i++)
            union_find[i]=i;//初始化 每个同学在自己的朋友圈
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)//因为是对称矩阵 所以遍历左下角矩阵即可
                if(m[j][i]==1)//j和i是朋友关系
                {
                    int a=union_find.find(i)->second;//j所在的朋友圈a
                    int b=union_find.find(j)->second;//i所在的朋友圈b
                    if(a!=b)//如果j和i不在一个朋友圈
                        for(int k=0;k<n;k++)//遍历每个同学 确定其所在的朋友圈
                            if(union_find[k]==b)//将朋友圈b中的所有同学
                                union_find[k]=a;//其朋友圈改为a，即合并a和b朋友圈为a
                }
        set<int> res;//利用互异性统计朋友圈个数
        for(int i=0;i<n;i++)
            res.emplace(union_find[i]);
        return res.size();
    }
};

//方法二 DFS & bool记录表
class Solution {
public:
    int findCircleNum(vector<vector<int>>& m) {
        int n=m.size();
        if(n==0)
            return 0;
        int res=0;
        vector<bool> find(n,false);//记录该同学是否已在某个朋友圈中
        for(int i=0;i<n;i++)
            if(!find[i])//该同学未在朋友圈
            {
                res++;//朋友圈数目+1
                dfs(m,i,find);//将所有该同学的朋友（的朋友）设为在某个朋友圈中。
            }
        return res;
    }
    void dfs(vector<vector<int>>& m,int k,vector<bool>& find)
    {
        int n=m.size();
        for(int i=0;i<n;i++)//先序搜索该列
            if(m[i][k]==1&&!find[i])//k和i是朋友关系，且i未在某个朋友圈中
            {
                find[k]=true;//设i已在某个朋友圈中
                dfs(m,i,find);//搜索i的朋友
            }
    }
};

//方法三 DFS & 修改矩阵
class Solution {
public:
    int findCircleNum(vector<vector<int>>& m) {
        if(m.empty())
            return 0;
        int n=m.size();;
        int res=0;
        for(int i=0;i<n;i++)
            if(m[i][i]==1)//m[i][i]代表i同学是否在某个朋友圈中
            {
                res++;//如果为1说明不在，因此i和所有i的同学在一个新朋友圈中 朋友圈+1
                dfs(m,i);//将所有i的同学设为0
            }
        return res;
    }
    void dfs(vector<vector<int>>& m,int k)
    {
        int n=m.size();
        for(int i=0;i<n;i++)
            if(m[i][k]==1)//搜索k的同学 
            {
                m[i][k]=0;//将k的同学关系设为0 这样不会再搜索回来
                m[k][i]=0;//k的同学关系设为0 
                m[i][i]=0;//记录k的同学i为已在某个朋友圈中
                dfs(m,i);//搜索k的同学已经k的同学i的同学
            }
    }
};
