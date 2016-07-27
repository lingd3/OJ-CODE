//
//  main.cpp
//  q
//
//  Created by gd on 16/7/25.
//  Copyright (c) 2016年 gd. All rights reserved.
//


//考察布尔代数知识
//sum = a^b
//carry = (a&b) << 1
#include <iostream>
using namespace std;

int getSum(int a, int b) {
    if (b == 0) return a;
    int sum = a ^ b;
    int carry = (a & b) << 1;
    return getSum(sum, carry);
}

int main(int argc, const char * argv[]) {
    int a, b;
    cin >> a >> b;
    cout << getSum(a, b) << endl;
    return 0;
}
