/*
题目：
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where 
different letters represent different tasks. Tasks could be done without original order. 
Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.
However, there is a non-negative cooling interval n that means between two same tasks, there must be at least
n intervals that CPU are doing different tasks or just be idle.
You need to return the least number of intervals the CPU will take to finish all the given tasks.
Example:
Input: tasks = ["A","A","A","B","B","B"], n = 2
Output: 8
Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
Note:
The number of tasks is in the range [1, 10000].
The integer n is in the range [0, 100].
解析：
给定一个由'A'-'Z'组成的字符串，以及一个正整数n，字符表示不同任务，n表示每一个任务执行后的冷却期，即同一个任务至少要相隔n个才可以。
如果当前没有任务可执行时，需要执行idle操作。求执行完所有任务的最少时间。
数目多的任务所需要的总冷却时间长，因此需要先执行数目多的任务，如果冷却期结束，应当先执行当前任务数最多的任务。
因此基本思路时，降序排序，从第一个开始执行至n+1个任务，此时第一个任务周期的冷却期结束，又可以执行n+1个任务。在每个任务周期开始前将
任务以剩余执行总数降序排序，并选取前n+1个任务执行。注意当当前任务都在冷却期内时，需要执行idle操作，即如果遍历任务降序，需要执行的任务
总数不足n+1且仍有任务需要执行时，本周期的执行时间为n+1，当本周期时间为t<n+1且没有待执行任务时，本周期执行时间为t。
*/
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> taskMap;//每个字符出现的次数
        int sizeTask=tasks.size();
        for(int i=0;i<sizeTask;i++)
            taskMap[tasks[i]]++;//待执行任务及任务数目
        vector<pair<char,int>> mapOrder;//保存任务数降序排序的任务序号
        //保存任务降序序号
        for(int i=0;i<26;i++)
        {
            if(taskMap.count(i+'A')!=0)
                 mapOrder.push_back(pair<char,int>{i+'A',taskMap[i+'A']});
            else
                 mapOrder.push_back(pair<char,int>{i+'A',0});
        }
        //降序排序
        sort(mapOrder.begin(),mapOrder.end(),cmp);
        int res=0;//记录程序总运行时间
        while(taskMap.size()!=0)
        {
            int size=0;
            for(int i=0;i<26;i++)
            {
                if(taskMap.count(mapOrder[i].first)!=0)
                {
                    size++;
                    taskMap[mapOrder[i].first]--;
                    if(taskMap[mapOrder[i].first]==0)
                        taskMap.erase(mapOrder[i].first);
                    if(size==n+1)
                        break;
                }
            }
            if(size<n+1&&!taskMap.empty())
                size=n+1;
            res+=size;
            mapOrder.clear();
            for(int i=0;i<26;i++)
            {
            if(taskMap.count(i+'A')!=0)
                 mapOrder.push_back(pair<char,int>{i+'A',taskMap[i+'A']});
            else
                 mapOrder.push_back(pair<char,int>{i+'A',0});
            }
            sort(mapOrder.begin(),mapOrder.end(),cmp);
        }
        return res;
    }
    static bool cmp(pair<char,int> a,pair<char,int> b)
    {
        return a.second>b.second;
    }
};
