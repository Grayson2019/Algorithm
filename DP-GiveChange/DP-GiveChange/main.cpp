//
//  main.cpp
//  DP-GiveChange
//
//  Created by 杨浩 on 2019/4/11.
//  Copyright © 2019 Grayson. All rights reserved.
//

#include <iostream>
using namespace std;

int recursion(int j, int totalNum, int d[][2], int n)
{
    if (j <= 0) {
        return totalNum;
    }
    while (n > -1) {
        if (d[n][0] > j) {
            n--;
        } 
    }
    
    if (d[n][0] <= j) {
        j -= d[n][0];
    }
}
int main(int argc, const char * argv[]) {
    std::cout << "\n";
    int n; //面额张数
    cout << "请输入面额张数n:\n";
    cin >> n;
    cout << "请输入面额金额d[0] to d[n-1]:\n";
    int d[n][2];
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) {
        cin >> d[i][0];
    }
    
    for (int j = 0; j < 30; j++) {
        int totalNum = 0;
        recursion(j, totalNum, d, n);
    }
    
    return 0;
}
