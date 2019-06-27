/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
你可以假设 nums1 和 nums2 不会同时为空。
示例 1:
nums1 = [1, 3]
nums2 = [2]
则中位数是 2.0
示例 2:
nums1 = [1, 2]
nums2 = [3, 4]
则中位数是 (2 + 3)/2 = 2.5
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/median-of-two-sorted-arrays
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();//数组1的大小
        int n=nums2.size();//数组2的大小
        int mid1,mid2;//记录合并后数组最中间两个数字的索引 若合并后数组大小为奇数 则只使用mid1
        int i=0,j=0;//i遍历nums1 j遍历nums2
        int res=0;//记录中间数字的值
        int cnt=0;//记录合并后数组的当前索引
        if((m+n)%2==0)//偶数个 找最中间两个数
        {
            mid1=(m+n)/2-1;//最中间两个数的前一个
            mid2=(m+n)/2;//最中间两个数的后一个
            while(i<=m&&j<=n)//遍历数组1和数组2每一个数字
            {
                if(cnt>mid2)
                    break;//找到最中间两个数 后面的不执行
                if(i==m)//数组1遍历完 顺序遍历数组2
                {
                    if(cnt==mid1||cnt==mid2)//找到合并后数组中间的数字
                        res+=nums2[j];//记录数值
                    j++;//数组2继续遍历
                }
                else if(j==n)//数组2遍历完 顺序遍历数组1
                {
                    if(cnt==mid1||cnt==mid2)//找到合并后数组中间的数字
                        res+=nums1[i];//记录数值
                    i++;//数组1继续遍历
                }
                else//数组1和2的索引都合法 比较其值的大小
                {
                    if(nums1[i]<nums2[j])//小数做为合并后数组的当前数值
                    {
                        if(cnt==mid1||cnt==mid2)//判断索引是否为中位
                            res+=nums1[i];
                        i++;
                    }
                    else
                    {
                        if(cnt==mid1||cnt==mid2)
                            res+=nums2[j];
                        j++;
                    }
                }
                cnt++;//更新合并后数组的当前索引
            }
            return res/2.0;//返回最中间两个数字的平均值
        }
        else//奇数个
        {
            mid1=(m+n)/2;
            while(i<=m&&j<=n)
            {
                if(cnt>mid1)
                    break;
                if(i==m)
                {
                    if(cnt==mid1)
                        res+=nums2[j];
                    j++;
                }
                else if(j==n)
                {
                    if(cnt==mid1)
                        res+=nums1[i];
                    i++;
                }
                else
                {
                    if(nums1[i]<nums2[j])
                    {
                        if(cnt==mid1)
                            res+=nums1[i];
                        i++;
                    }
                    else
                    {
                        if(cnt==mid1)
                            res+=nums2[j];
                        j++;
                    }
                }
                cnt++;
            }
        }
        return res;//返回最中间数字
    }
};
