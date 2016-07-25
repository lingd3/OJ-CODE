#include<stack>
class MinStack {
public:
    MinStack() {
        size = 0;
    }
    void push(int x) {
        a[size] = x;
        size++;
        if (s.empty()) s.push(x);
        else {
            if (x <= s.top()) s.push(x);
        }
    }

    void pop() {
        if (top() == s.top()) s.pop();
        size--;
    }

    int top() {
        return a[size-1];
    }

    int getMin() {
        int a = s.top();
        return a;
    }
private:
    int a[100000];
    int size;
    stack<int> s;
};
