/*
给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第k小的元素。
请注意，它是排序后的第k小元素，而不是第k个元素。
示例:
matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,
返回 13。
说明: 
你可以假设 k 的值永远是有效的, 1 ≤ k ≤ n2 。
*/


//堆解法。
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        //全部元素入堆 维持一个大小为k的大顶堆 则堆顶为第k小元素
        priority_queue<int> st;
        for(auto p:matrix)
            for(auto pp:p)
            {
                int n=st.size();
                if(n<k)
                    st.push(pp);
                else
                {
                    st.push(pp);//k+1个元素
                    st.pop();//堆顶出堆 剩余k个小元素
                }
            }
        return st.top();
    }
};


//二分查找
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        int l=matrix[0][0];//最小值
        int r=matrix[m-1][n-1];//最大值
        while(l<=r)
        {
            int mid=(r-l)/2+l;
            int cnt=0;
            for(int i=0;i<m;i++)
                for(int j=0;j<n&&matrix[i][j]<=mid;j++)//等于号保证mid在矩阵中
                    cnt++;
            if(cnt<k)
                l=mid+1;
            else
                r=mid-1;
        }
        return l;
    }
};
