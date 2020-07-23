//
// Created by cedar on 2020/7/22.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
//    //方式1
//    vector<int> ivec;
//    int ival;
//    cout << "请输入一串整数：";
//    while (cin >> ival) {
//        if (ival == -1) break;  //-1作为结束
//        ivec.push_back( ival );
//    }
//    //计算总和，一一累加vector当中的元素
//    int sum = 0;
//    for (int i = 0; i < ivec.size(); ++i)
//        sum += ivec[i];
//    int average = sum/ivec.size();
//    cout << ivec.size() << "个元素的和是" << sum
//         << "，平均数是" << average;

    //方式2
    const int array_size = 128;
    int a[array_size];
    int val = 0, cnt = 0;
    cout << "请输入一串整数：";
    while (cin >> val && cnt < array_size) {
        if (val==-1) break;
        a[cnt++] = val;
    }
    int sum = 0;
    for (int i = 0; i < cnt; ++i) {
        sum += a[i];
    }
    int average = sum/cnt;
    cout << cnt << "个元素的和是" << sum
         << "，平均数是" << average;
    return 0;
}
