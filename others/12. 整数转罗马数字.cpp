/*
给定一个1-3999的十进制数字，输出其对应的罗马数字字符串。
*/

class Solution {
public:
    string intToRoman(int num) {
        int val[4];//val[0-3] ~个十百千位 
        for(int i=0;i<4;i++)//获取各个位的十进制数字
        {
            val[i]=num%10;
            num/=10;
        }
        for(int i=0;i<4;i++)
            val[i]=val[i]*pow(10,i);//各位数字复原为几十几百等
        string res;
        res+=tho(val[3]);//获取千位罗马数字
        res+=hun(val[2]);//获取百位罗马数字
        res+=ten(val[1]);//获取十位罗马数字
        res+=one(val[0]);//获取个位罗马数字
        return res;
    }
    string tho(int num)//i=1,2,3、 求1000*i对应的罗马数字
    {
        string res;
        num/=1000;
        if(num<=3)//不会超过3999
            for(int i=0;i<num;i++)
                res+="M";
        return res;
    }
    string hun(int num)//i=1,2,...9 求100*i对应的罗马数字
    {
        string res;
        num/=100;
        if(num<=3)
            for(int i=0;i<num;i++)
                res+="C";
        else if(num==4)
            res="CD";
        else if(num==5)
            res="D";
        else if(num>=6&&num<=8)
        {
            res+="D";
            for(int i=5;i<num;i++)
                res+="C";
        }
        else if(num==9)
            res="CM";
        return res;
    }
    string ten(int num)//i=1,2,...9 求10*i对应的罗马数字
    {
        string res;
        num/=10;
        if(num<=3)
            for(int i=0;i<num;i++)
                res+="X";
        else if(num==4)
            res="XL";
        else if(num==5)
            res="L";
        else if(num>=6&&num<=8)
        {
            res+="L";
            for(int i=5;i<num;i++)
                res+="X";
        }
        else if(num==9)
            res="XC";
        return res;
    }
    string one(int num)//i=1,2,...9 求i对应的罗马数字
    {
        string res;
        if(num<=3)
            for(int i=0;i<num;i++)
                res+="I";
        else if(num==4)
            res="IV";
        else if(num==5)
            res="V";
        else if(num>=6&&num<=8)
        {
            res+="V";
            for(int i=5;i<num;i++)
                res+="I";
        }
        else if(num==9)
            res="IX";
        return res;
    }
};
