/*
@Copyright:LintCode
@Author:   linqiao
@Problem:  http://www.lintcode.com/problem/min-stack
@Language: C++
@Datetime: 17-02-27 09:37
*/

class MinStack {
private:
    stack<int> s;
    stack<int> mins;
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
        if (s.size() == 0) {
            s.push(number);
            mins.push(number);
        }
        else if (mins.top() <= number) {
            s.push(number);
            mins.push(mins.top());
        }
        else if (mins.top() > number) {
            s.push(number);
            mins.push(number);
        }
    }

    int pop() {
        // write your code here
        int n = s.top();
        s.pop();
        mins.pop();
        return n;
    }

    int min() {
        // write your code here
        return mins.top();
    }
};
