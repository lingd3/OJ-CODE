//
//  main.cpp
//  Calculator
//
//  Created by gd on 16/11/8.
//  Copyright (c) 2016年 gd. All rights reserved.
//

#include <iostream>
#include <stack>
#include <queue>
using namespace std;

//string转int
int strToint(string s) {
    int num = 0;
    for (int i = 0; i < s.size(); i++) {
        num = num*10 + s[i]-'0';
    }
    return num;
}

double calculate(string s) {
    //将用户输入的字符串分割，符号和整数分离
    char a[100][8];
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 8; j++) {
            a[i][j] = '\0';
        }
    }
    int count = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < '0' || s[i] > '9') {
            a[count][0] = s[i];
            count++;
        }
        else {
            a[count][0] = s[i];
            int j = i+1, k = 1;
            for (j = i+1; j < s.length(); j++) {
                if (s[j] >= '0' && s[j] <= '9') {
                    a[count][k] = s[j];
                    k++;
                }
                else {
                    break;
                }
            }
            i = j-1;
            count++;
        }
    }
    
    //中缀表达式转为后缀表达式
    queue<string> q;
    stack<string> stack1;
    for (int i = 0; i < count; i++) {
        if (a[i][0] >= '0' && a[i][0] <= '9') {
            q.push(a[i]);
        }
        else if (a[i][0] == '+' || a[i][0] == '-') {
            if (stack1.empty()) stack1.push(a[i]);
            else {
                if (stack1.top() == "*" || stack1.top() == "/") {
                    while (!stack1.empty() && stack1.top() != "(") {
                        string x = stack1.top();
                        q.push(x);
                        stack1.pop();
                    }
                    stack1.push(a[i]);
                }
                else if (stack1.top() == "+" || stack1.top() == "-") {
                    string x = stack1.top();
                    q.push(x);
                    stack1.pop();
                    stack1.push(a[i]);
                }
                else if (stack1.top() == "(") stack1.push(a[i]);
            }
        }
        else if (a[i][0] == '*' || a[i][0] == '/') {
            if (stack1.empty()) stack1.push(a[i]);
            else {
                if (stack1.top() == "+" || stack1.top() == "-") {
                    stack1.push(a[i]);
                }
                else if (stack1.top() == "*" || stack1.top() == "/") {
                    string x = stack1.top();
                    q.push(x);
                    stack1.pop();
                    stack1.push(a[i]);
                }
                else if (stack1.top() == "(") stack1.push(a[i]);
            }
        }
        else if (a[i][0] == '(') stack1.push(a[i]);
        else if (a[i][0] == ')') {
            while (stack1.top() != "(" && !stack1.empty()) {
                string x = stack1.top();
                q.push(x);
                stack1.pop();
            }
            if (stack1.top() == "(") stack1.pop();
        }
    }
    while (!stack1.empty()) {
        if (stack1.top() == "(") {
            stack1.pop();
            continue;
        }
        string x = stack1.top();
        q.push(x);
        stack1.pop();
    }
    
    //计算后缀表达式
    stack<double> stack2;
    while (!q.empty()) {
        if (q.front() == "+") {
            double num1 = stack2.top();
            stack2.pop();
            double num2 = stack2.top();
            stack2.pop();
            double sum = num1 + num2;
            stack2.push(sum);
            q.pop();
        }
        else if (q.front() == "-") {
            double num1 = stack2.top();
            stack2.pop();
            double num2 = stack2.top();
            stack2.pop();
            double minus = num2 - num1;
            stack2.push(minus);
            q.pop();
        }
        else if (q.front() == "*") {
            double num1 = stack2.top();
            stack2.pop();
            double num2 = stack2.top();
            stack2.pop();
            double multiply = num1*num2;
            stack2.push(multiply);
            q.pop();
        }
        else if (q.front() == "/") {
            double num1 = stack2.top();
            stack2.pop();
            double num2 = stack2.top();
            stack2.pop();
            double divide = num2/num1;
            stack2.push(divide);
            q.pop();
        }
        else {
            double num = strToint(q.front());
            stack2.push(num);
            q.pop();
        }
    }
    double w = stack2.top();
    return w;
}

int main(int argc, const char * argv[]) {
    string input;
    while (true) {
        cout << "---------------------------" << endl << "请输入整数的四则运算表达式：" << endl;
        cin >> input;
        double output = calculate(input);
        cout << "运算结果为：" << output << endl;
        cout << "---------------------------" << endl << endl;
    }
    return 0;
}
