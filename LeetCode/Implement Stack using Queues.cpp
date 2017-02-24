#include<deque>
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
        queue.push_front(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        queue.pop_front();
    }

    // Get the top element.
    int top() {
        return queue[0];
    }

    // Return whether the stack is empty.
    bool empty() {
        if (queue.empty()) return true;
        return false;
    }
private:
    deque<int> queue;
};

