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
方法一：不相交集类。 创建N个集类，每个同学在一个集类里，若m[i][j]==1，那么将i所在的集类合并为一个集类。最后，集类的个数即为朋友圈的数目。
注意因为m[i][j]=m[j][i]，又m[i][i]=1，所以从对角线开始，搜索左下角矩阵即可。
方法二：dfs，从同学0开始，若有朋友arr,则顺序搜索arr中个每个同学的朋友,搜索到的矩阵元素均在一个朋友圈中。
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
