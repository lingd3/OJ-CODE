#include<stack>
class Queue {
public:
    // Push element x to the back of queue.
    void push(int x) {
        firstStack.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        while (!secondStack.empty()) {
             secondStack.pop();
         }
         while (!firstStack.empty()) {
             secondStack.push(firstStack.top());
             firstStack.pop();
         }
         secondStack.pop();
         while (!secondStack.empty()) {
             firstStack.push(secondStack.top());
             secondStack.pop();
         }
    }

    // Get the front element.
    int peek(void) {
        while (!firstStack.empty()) {
             secondStack.push(firstStack.top());
             firstStack.pop();
         }
         int a = secondStack.top();
         while (!secondStack.empty()) {
             firstStack.push(secondStack.top());
             secondStack.pop();
         }
         return a;
    }

    // Return whether the queue is empty.
    bool empty(void) {
        if (firstStack.empty()) return true;
        return false;
    }
private: 
     stack<int> firstStack; 
     stack<int> secondStack;
};





