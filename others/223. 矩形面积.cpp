/*
在二维平面上计算出两个由直线构成的矩形重叠后形成的总面积。
每个矩形由其左下顶点和右上顶点坐标表示，如图所示。
示例:
输入: -3, 0, 3, 4, 0, -1, 9, 2
输出: 45
说明: 假设矩形面积不会超出 int 的范围。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/rectangle-area
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        if(A<=E&&B<=F&&G<=C&&H<=D)//包含
            return (C-A)*(D-B);//返回大矩形面积
        else if(A>=E&&B>=F&&G>=C&&H>=D)//包含
            return (G-E)*(H-F);//返回大矩形面积
        else if(E>=C||A>=G||B>=H||F>=D)//不想交
            return (C-A)*(D-B)+(G-E)*(H-F);//返回面积之和
        else//相交
            return (C-A)*(D-B)+(G-E)*(H-F)-(min(C,G)-max(A,E))*(min(D,H)-max(B,F));//两矩形面积之和减去重合面积
    }
};
