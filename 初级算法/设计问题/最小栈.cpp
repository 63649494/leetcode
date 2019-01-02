/* 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。

push(x) -- 将元素 x 推入栈中。
pop() -- 删除栈顶的元素。
top() -- 获取栈顶元素。
getMin() -- 检索栈中的最小元素。
示例:

MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2. */

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top()) s2.push(x);
    }
    
    void pop() {
        if (s1.top() == s2.top()) s2.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
    }
private:
    stack<int> s1, s2;
};

/* 错误解法：
//元素要少于date[]的长度
class MinStack {
public:
        int date[10];
        int tail;
    
    MinStack() {
        int date[10];
        int tail=-1;
    }
    
    void push(int x) {
        tail=tail+1;
        date[tail]=x;
    }
    
    void pop() {
       tail--;
    }
    

    int getMin() {
        int min=date[0];
        for(int i=1;i<=tail;i++)
            min=min<date[i]?min:date[i];
        return min;
    }
    
    int top() {
        return date[tail];
    }
    
};

/*

 
 
//元素只能是小于10的整数
 class MinStack {
public:
        int date=0;
        int tail;
    
    MinStack() {
        int date;
        int tail=-1;
    }
    
    void push(int x) {
        cout<<"push "<<date<<"  "<<tail<<"\n";
        tail=tail+1;
        date=date*10+x;
    }
    
    void pop() {
        
        cout<<"pop "<<date<<"\n";
        date=date/10;
        tail--;
    }
    

    int getMin() {
        cout<<"gmin "<<date<<"\n";
        if(date/10==0){
            //前几位为零的情况
            int a=date;
            int count=0;
            while(a!=0)
            {
            a/=10;
            count++;
            }
            cout<<"count="<<count<<"\n";
            if(count<tail)
                if(date>=0)
                    return 0;
            return date;
        }
            
        int date1=date;
        int min=date1%10;
        for(int i=1;i<=tail;i++){
            date1=date1/10;
            min=min<date1%10?min:date1%10;
        }
        

            
        return min;
    }
    
    int top() {
        cout<<"top "<<date<<"\n";
        return date%10;
    }
    
};

 */ 