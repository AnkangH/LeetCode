/*
设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/min-stack
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/


class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s.push(x);
        if(s_min.empty())
            s_min.push(x);//最小栈空 直接入栈
        else
            if(x<=s_min.top())//小于等于最小栈的栈顶（最小值）
                s_min.push(x);//入最小值栈
    }
    
    void pop() {
        if(s.top()==s_min.top())//是最小值
        {
            s.pop();//标准栈出栈
            s_min.pop();//最小栈出栈
        }
        else
            s.pop();//否则只标准栈出栈
    }
    
    int top() {
        return s.top();//返回标准栈栈顶
    }
    
    int getMin() {
        return s_min.top();//返回最小栈栈顶
    }
private:
    stack<int> s,s_min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
