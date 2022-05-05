class MyStack {
    public:
    queue<int> q1, q2;
    int Top;
    MyStack() {}
    void push(int x) {
        q1.push(x); Top=x;
    }
    int pop() {
        while(q1.size() != 1) {
            Top=q1.front(); q1.pop(); 
            q2.push(Top);
        }
        int x=q1.front(); q1.pop();
        swap(q1,q2);
        return x;
    }
    int top() {
        return Top;
    }
    bool empty() {
        return (q1.size()==0 && q2.size()==0);
    }
};