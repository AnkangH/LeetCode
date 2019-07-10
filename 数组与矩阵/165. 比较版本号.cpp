/*
比较两个版本号 version1 和 version2。
如果 version1 > version2 返回 1，如果 version1 < version2 返回 -1， 除此之外返回 0。
你可以假设版本字符串非空，并且只包含数字和 . 字符。
 . 字符不代表小数点，而是用于分隔数字序列。
例如，2.5 不是“两个半”，也不是“差一半到三”，而是第二版中的第五个小版本。
你可以假设版本号的每一级的默认修订版号为 0。例如，版本号 3.4 的第一级（大版本）和第二级（小版本）修订号分别为 3 和 4。其第三级和第四级修订号均为 0。
示例 1:
输入: version1 = "0.1", version2 = "1.1"
输出: -1
示例 2:
输入: version1 = "1.0.1", version2 = "1"
输出: 1
示例 3:
输入: version1 = "7.5.2.4", version2 = "7.5.3"
输出: -1
示例 4：
输入：version1 = "1.01", version2 = "1.001"
输出：0
解释：忽略前导零，“01” 和 “001” 表示相同的数字 “1”。
示例 5：
输入：version1 = "1.0", version2 = "1.0.0"
输出：0
解释：version1 没有第三级修订号，这意味着它的第三级修订号默认为 “0”。
提示：
版本字符串由以点 （.） 分隔的数字字符串组成。这个数字字符串可能有前导零。
版本字符串不以点开始或结束，并且其中不会有两个连续的点。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/compare-version-numbers
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int compareVersion(string version1, string version2) {
        int size1=version1.size();
        int size2=version2.size();
        int i=0,j=0;
        while(i<size1&&j<size2)//遍历两个字符串
        {
            string temp1,temp2;//当前数字字符串
            while(version1[i]!='.'&&i<size1)//分割version1
            {
                temp1+=version1[i];
                i++;
            }
            while(version2[j]!='.'&&j<size2)//分割version2
            {
                temp2+=version2[j];
                j++;
            }
            i++;//跳过 '.' 准备下次分割
            j++;//跳过 '.' 准备下次分割
            int a=str2int(temp1);//version1对应数字字符串转数值
            int b=str2int(temp2);//version2对应数字字符串转数值
            if(a<b)
                return -1;//当前位 ver1<ver2 则输出-1
            else if(a>b)
                return 1;//当前位  ver1>ver2 输出1
        }
        //上述while未返回 则说明有一个到达终点 而前面的每一位均相等
        if(i>=size1&&j<size2)//ver1到达终点
        {
            string temp;//数值字符串暂存
            for(j;j<size2;j++)//遍历ver2剩余字符串
            {
                if(version2[j]!='.'&&j<size2)//以'.'分割
                {
                    temp+=version2[j];
                    if(j==size2-1&&str2int(temp)!=0)//最后一个字符 且不为0
                        return -1;
                }
                else
                {
                    if(str2int(temp)!=0)//有一个不为0
                        return -1;//ver1<ver2
                    temp.clear();//暂存变量清空 准备下次判断
                }
            }
            return 0;
        }
        else if(i<size1&&j>=size2)//同理 ver1未到终点而ver2到达终点
        {
            string temp;
            for(i;i<size1;i++)
            {
                if(version1[i]!='.'&&i<size1)
                {
                    temp+=version1[i];
                    if(i==size1-1&&str2int(temp)!=0)
                        return 1;
                }
                else
                {
                    if(str2int(temp)!=0)
                        return 1;
                    temp.clear();
                }
            }
            return 0;
        }
        else
            return 0;
    }
    int str2int(string s)//字符串转int 如1=000001
    {
        int size=s.size();
        int res=0;
        for(int i=0;i<size;i++)//由高位到低位
        {
            res*=10;//进位
            res+=s[i]-'0';//当前位
        }
        return res;
    }
};
