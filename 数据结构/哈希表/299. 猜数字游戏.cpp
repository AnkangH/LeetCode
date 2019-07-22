/*
你正在和你的朋友玩 猜数字（Bulls and Cows）游戏：你写下一个数字让你的朋友猜。每次他猜测后，你给他一个提示，告诉他有多少位数字和确切位置都猜对了
（称为“Bulls”, 公牛），有多少位数字猜对了但是位置不对（称为“Cows”, 奶牛）。你的朋友将会根据提示继续猜，直到猜出秘密数字。
请写出一个根据秘密数字和朋友的猜测数返回提示的函数，用 A 表示公牛，用 B 表示奶牛。
请注意秘密数字和朋友的猜测数都可能含有重复数字。
示例 1:
输入: secret = "1807", guess = "7810"
输出: "1A3B"
解释: 1 公牛和 3 奶牛。公牛是 8，奶牛是 0, 1 和 7。
示例 2:
输入: secret = "1123", guess = "0111"
输出: "1A1B"
解释: 朋友猜测数中的第一个 1 是公牛，第二个或第三个 1 可被视为奶牛。
说明: 你可以假设秘密数字和朋友的猜测数都只包含数字，并且它们的长度永远相等。
*/


//利用长度为10的两个数组记录出现次数 时间复杂度O(n)
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0,cows=0;
        int n=secret.size();
        vector<int> s(10,0);//secret中非公牛的数字及个数
        vector<int> g(10,0);//guess中非公牛的数字及个数
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
                bulls++;
            else
            {
                s[secret[i]-'0']++;//secret中非公牛的数字及个数
                g[guess[i]-'0']++;//guess中非公牛的数字及个数
            }
        }
        for(int i=0;i<10;i++)
            cows+=min(s[i],g[i]);//取相同数字出现的最小值
        string res;//返回结果
        res+=to_string(bulls);
        res+='A';
        res+=to_string(cows);
        res+='B';
        return res;
    }
};


//利用长度为n的数组记录数字出现次数和索引 时间复杂度O(2n)
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0,cows=0;
        unordered_map<char,int> m;//记录非公牛的所有数字出现次数
        int n=secret.size();
        vector<bool> known(n,false);//记录guess中非公牛的位置
        for(int i=0;i<n;i++)
        {
            if(secret[i]==guess[i])
                bulls++;
            else
            {
                m[secret[i]]++;
                known[i]=true;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!known[i])
                continue;//公牛位置跳过
            if(m.count(guess[i])!=0&&m[guess[i]]>0)//非公牛位置 在secret中有相同数字 且仍有未与guess组成cows的数字
            {
                m[guess[i]]--;//secret数字次数-1
                cows++;
            }
        }
        string res;
        res+=to_string(bulls);
        res+='A';
        res+=to_string(cows);
        res+='B';
        return res;
    }
};
