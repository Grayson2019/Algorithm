//
//  main.cpp
//  DP-GiveChange
//
//  Created by 杨浩 on 2019/4/11.
//  Copyright © 2019 Grayson. All rights reserved.
//

#include <iostream>
using namespace std;
// 根据状态转换方程d(i)=d(i-vj)+1得到的函数
int stateTransition(int j, int a, int storeRecord[][5])
{
    int b;
    b = j - a;
    storeRecord[j][0] = j;
    storeRecord[j][1] = storeRecord[b][1] + 1;
    storeRecord[j][2] = storeRecord[b][2];
    storeRecord[j][3] = storeRecord[b][3];
    storeRecord[j][4] = storeRecord[b][4];
    return storeRecord[j][1];
}

// 主函数
int main(int argc, const char * argv[]) {
    std::cout << "\n";
    int n; // 面额张数
    cout << "请输入面额张数n:\n";
    cin >> n;
    
    cout << "请输入面额金额d[0] to d[n-1]:\n";
    int d[n]; // 存储面额金额的数组
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }
    // 存储每一个j对应的
    int storeRecord[31][5];
    memset(storeRecord, 0, sizeof(storeRecord));

    cout << "零钱    张数    各面额的张数\n";
    // 自底向上（1～30）
    for (int j = 1; j < 31; j++) {
        // 从大到小遍历面额数组d[n]
        for (int i = n - 1; i > -1; i--) {
            // 判断当前j是否大于或等于当前面额
            if (j >= d[i]) {
                // 当前j大于或等于当前面额
                // 继续判断当前i是否等于最大面额对应数组的i
                if (i == n-1) {
                    // 当前i等于最大面额对应数组的i
                    // 需要考虑两种情况
                    // 第一种情况是先减去面额最大的
                    // 第二种情况是先减去面额第二大的
                    // 然后再比较两种情况对应状态转换方程返回的需要总张数
                    // 采用需要总张数少的情况
                    if (stateTransition(j, d[i], storeRecord) <= stateTransition(j, d[i-1], storeRecord)) {
                        stateTransition(j, d[i], storeRecord);
                        // 当采用第一种情况时，需要将storeRecord中记录最大面额需要张数的值+1
                        storeRecord[j][4]++;
                        // 判断j>=10单纯为了让输出格式化
                        if (j >= 10) {
                            cout << "j=" << j << "    "<< storeRecord[j][1] << "    " <<  "d[1]=" << storeRecord[j][2] << " " << "d[2]=" << storeRecord[j][3] << " " << "d[3]=" << storeRecord[j][4];
                            cout << "\n";
                        }else{
                            cout << "j=" << j << "     "<< storeRecord[j][1] << "    " <<  "d[1]=" << storeRecord[j][2] << " " << "d[2]=" << storeRecord[j][3] << " " << "d[3]=" << storeRecord[j][4];
                            cout << "\n";
                        }
                        
                    }else{
                        // 当采用第二种情况时，需要将storeRecord中记录第二大面额需要张数的值+1
                        stateTransition(j, d[i-1], storeRecord);
                        storeRecord[j][3]++;
                        if (j >= 10) {
                            cout << "j=" << j << "    "<< storeRecord[j][1] << "    " <<  "d[1]=" << storeRecord[j][2] << " " << "d[2]=" << storeRecord[j][3] << " " << "d[3]=" << storeRecord[j][4];
                            cout << "\n";
                        }else{
                            cout << "j=" << j << "     "<< storeRecord[j][1] << "    " <<  "d[1]=" << storeRecord[j][2] << " " << "d[2]=" << storeRecord[j][3] << " " << "d[3]=" << storeRecord[j][4];
                            cout << "\n";
                        }
                    }

                }else{
                    // 当前i不等于最大面额对应数组的i
                    // 只需要考虑面额最小的和面额第二大的情况
                    stateTransition(j, d[i], storeRecord);
                    if (i == 1){
                        // 当先剪去面额第二大的数时，需要将storeRecord中记录第二大面额需要张数的值+1
                        storeRecord[j][3]++;
                        cout << "j=" << j << "     "<< storeRecord[j][1] << "    " << "d[1]=" << storeRecord[j][2] << " " << "d[2]=" << storeRecord[j][3] << " " << "d[3]=" << storeRecord[j][4];
                        cout << "\n";
                    }else if (i == 0){
                        // 当先剪去面额最小的数时，需要将storeRecord中记录最小面额需要张数的值+1
                        storeRecord[j][2]++;
                        cout << "j=" << j << "     "<< storeRecord[j][1] << "    " << "d[1]=" << storeRecord[j][2] << " " << "d[2]=" << storeRecord[j][3] << " " << "d[3]=" << storeRecord[j][4];
                        cout << "\n";
                    }
                }
                break;
            }
        }
    }
    return 0;
}
