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
方法一：每次选取执行任务前对待执行任务排序 选取前n+1个执行 除非执行到最后一轮 否则不够n+1的执行idle补足n+1
方法二：只关心待执行任务的数目，使用大顶堆，将待执行任务的数目全部入堆，每轮从堆中pop出n+1次堆顶，记录pop()出的数目-1,本轮结束后将pop()出的
数目-1（即本轮执行的任务，执行一次后剩余cur-1次待执行）push进堆，这样避免了重复选取同一个任务。在取堆顶时要检查堆是否为空。
*/
//方法一 重复排序
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
            for(int i=0;i<26;i++)//每一轮选取
            {
                if(taskMap.count(mapOrder[i].first)!=0)//从次数多的开始选取
                {
                    size++;//记录本轮已执行任务
                    taskMap[mapOrder[i].first]--;//更新剩余执行次数
                    if(taskMap[mapOrder[i].first]==0)
                        taskMap.erase(mapOrder[i].first);//当剩余执行次数为0时，删除该任务
                    if(size==n+1)//到达冷却时间 退出本轮 
                        break;
                }
            }
            if(size<n+1&&!taskMap.empty())
                size=n+1;//只要不是最后一轮 那么本轮执行时间必为n+1
            res+=size;
            mapOrder.clear();//清空待执行任务的次数排序序列 为更新做准备
            for(int i=0;i<26;i++)
            {
            if(taskMap.count(i+'A')!=0)
                 mapOrder.push_back(pair<char,int>{i+'A',taskMap[i+'A']});//剩余待执行次数入队列
            else
                 mapOrder.push_back(pair<char,int>{i+'A',0});
            }
            sort(mapOrder.begin(),mapOrder.end(),cmp);//排序 剩余执行次数多的在前 优先执行
        }
        return res;
    }
    static bool cmp(pair<char,int> a,pair<char,int> b)
    {
        return a.second>b.second;//以pair的第二个参数 降序排序
    }
};

//方法二 大顶堆
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> taskCount(26,0);//每个任务出现次数初始化为0
        int res=0;//总执行时间
        //0-‘A’ 15-‘Z’
        for(auto p:tasks)
            taskCount[p-'A']++;//记录每个任务的执行次数
        priority_queue<int> heap;//大顶堆
        for(auto p:taskCount)
            if(p!=0)
                heap.push(p);//待执行次数不为0的每个次数入堆
        vector<int> temp;//记录出堆的任务剩余待执行次数
        while(!heap.empty())//堆空代表所有任务都执行完
        {
            int size=0;//记录本轮执行的任务数
            for(int i=0;i<=n;i++)//每轮的冷却时间 保证冷却时间过后 数目最多的优先执行
            {
                if(!heap.empty())//检查堆非空
                {
                    int cur=heap.top()-1;//取当前待执行次数最多的任务执行 更新剩余待执行次数
                    if(cur!=0)
                        temp.push_back(cur);//仍需执行的次数暂时保存
                    size++;//本轮已执行的任务数目
                    heap.pop();//执行完堆顶任务后，堆顶任务出堆，防止在一轮中重复选取
                }
            }
            if(!temp.empty())//有待执行任务
            {
                for(auto p:temp)
                    heap.push(p);//待执行任务的待执行次数入堆
                temp.clear();//清空待执行任务序列 为下次保存做准备
            }
            if(size<n+1&&!heap.empty())
                size=n+1;//只要不是最后一轮 那么本轮执行的数目必为n+1 要么待执行的任务数目多于n+1 要么用idle补足
            res+=size;//总执行时间更新
        }
        return res;//返回值
    }
};
