/*
给定两个二进制字符串，返回他们的和（用二进制表示）。
输入为非空字符串且只包含数字 1 和 0。
示例 1:
输入: a = "11", b = "1"
输出: "100"
示例 2:
输入: a = "1010", b = "1011"
输出: "10101"
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/add-binary
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    string addBinary(string a, string b) {
        //为了减少代码数量 使用a作为长度较大的字符串 b做为长度较小的字符串
        int sizea=a.size();
        int sizeb=b.size();
        int sizeMax=max(sizea,sizeb);
        int sizeMin=min(sizea,sizeb);
        if(sizea<sizeb)
            swap(a,b);
        int cof=0;//进位标志
        int i=sizeMax-1,j=sizeMin-1;//末位为最低位对齐
        while(i>=0)
        {
            if(j<0)//b未超出最高位  a[i]+b[j]+cof
                a[i]=add(a[i],'0',cof);
            else//b超出最高位 a[i]+cof
                a[i]=add(a[i],b[j],cof);
            i--;
            j--;
        }
        if(cof!=0)//最高位的进位不为0 前面补1
            a.insert(a.begin(),'1');
        return a;
    }
    char add(char a,char b,int& cof)//模拟两个二进制数字加法 返回值为当前位 cof为进位
    {
        char res;
        if(cof==1)//当前位有进位
        {
            int temp=a-'0'+b-'0';
            if(temp==0)//0+0+1
            {
                res='1';//当前位1
                cof=0;//进位0
            }
            else if(temp==1)//0+1+1
                res='0';//当前位0 进位1
            else if(temp==2)//1+1+1
                res='1';//当前位1 进位1
        }
        else//当前位没有进位
        {
            int temp=a-'0'+b-'0';
            if(temp==0)
                res='0';//当前位0 进位0
            else if(temp==1)
                res='1';//当前位1 进位0
            else
            {
                res='0';//当前位0 
                cof=1;//进位1
            }
        }
        return res;
    }
};
