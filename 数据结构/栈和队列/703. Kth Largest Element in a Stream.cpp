/*
题目：
Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, 
not the kth distinct element.
Your KthLargest class will have a constructor which accepts an integer k and an integer array nums, which contains initial 
elements from the stream. For each call to the method KthLargest.add, return the element representing the kth largest element 
in the stream.
Example:
int k = 3;
int[] arr = [4,5,8,2];
KthLargest kthLargest = new KthLargest(3, arr);
kthLargest.add(3);   // returns 4
kthLargest.add(5);   // returns 5
kthLargest.add(10);  // returns 5
kthLargest.add(9);   // returns 8
kthLargest.add(4);   // returns 8
Note: 
You may assume that nums' length ≥ k-1 and k ≥ 1.
解析：给定一个有序数组，设计一个函数，可以进行增加数值操作，返回增加数值后的数组中第k大的元素。
即便思路是使用一个数组保存数组中前k大的元素，因此第k大元素小的数值不会对后续产生影响。开始时想用数组和sort操作，但是当k值非常大时，
sort每次都需要对数组所有元素排序。
较好地方法是使用堆（优先队列），可以维持一个大小为k的小顶堆，这样堆顶元素即为数组中第k大的元素。要注意，创建数组时，第k大元素可能不存在。因为数组
的长度>=k-1，当数组长度=k-1时，如数组两个元素，那么k可以是3，此时数组只有两个元素，不存在第三大元素。但是执行一次add之后，必存在第k大元素。使用
一个flag标志数组是否存在第k大元素。
*/
class KthLargest {
    priority_queue<int,vector<int>, greater<> > qMin;//维持一个大小为k的小顶堆 顶堆为第k大元素
    int flag=0;//标志初始化时，数组是否存在第k大元素
public:
    KthLargest(int k, vector<int>& nums) {
        int size=nums.size();
        if(size>k-1)//初始化时 数组存在第k大元素
        {
            for(int i=0;i<size;i++)
            {
                if(i<=k-1)//arr[0]-arr[k-1]共k个值
                    qMin.push(nums[i]);//前k个元素入堆
                else//当k的大小为k值，保证堆的大小为k
                {
                    qMin.push(nums[i]);
                    qMin.pop();
                }
            }
            flag=1;
        }
        else//若初始化时，数组元素数目少，此时不存在第k大元素 数组元素全部入堆
            for(int i=0;i<size;i++)
                qMin.push(nums[i]);
    }
    int add(int val) {
        if(flag==0)//初始化时，不存在第k大元素，即堆的大小不为k
        {
            qMin.push(val);
            flag=1;
        }
        else//否则 维持堆的大小为k
        {
            qMin.push(val);
            qMin.pop();
        }
        return qMin.top();//返回堆顶元素即可
    }
};
/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
