/*
给定一个嵌套的整型列表。设计一个迭代器，使其能够遍历这个整型列表中的所有整数。
列表中的项或者为一个整数，或者是另一个列表。
示例 1:
输入: [[1,1],2,[1,1]]
输出: [1,1,2,1,1]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,1,2,1,1]。
示例 2:
输入: [1,[4,[6]]]
输出: [1,4,6]
解释: 通过重复调用 next 直到 hasNext 返回false，next 返回的元素的顺序应该是: [1,4,6]。
*/


class NestedIterator {
public:
    vector<int> nums;//保存所有单个数字
    int cnt;//记录当前指针位置
    int size;//记录数字个数
    NestedIterator(vector<NestedInteger> &nestedList) {
        dfs(nestedList);//根据表单构建所有数字的表
        cnt=-1;//计数起始
        size=nums.size();//数字个数
    }

    int next() {
        cnt++;//迭代器后移
        return nums[cnt];//返回当前数字
    }

    bool hasNext() {
        if(cnt==size-1)
            return false;//最后一个数字
        else
            return true;//非最后一个数字
    }
    void dfs(vector<NestedInteger> &nestedList)
    {
        for(auto p:nestedList)
        {
            if(p.isInteger())
                nums.push_back(p.getInteger());//数字放入数组
            else
                dfs(p.getList());//列表继续dfs直至最后
        }
    }
};
