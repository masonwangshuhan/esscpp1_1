//
// Created by cedar on 2020/7/21.
//
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int ival = 1024;
    int *pi = &ival;
    const int seq_size = 5;

    vector<int> Fibonacci, Lucas, Pell, Triangular, Square, Pentagonal;
//    vector<int> *pv = 0;
//    pv = &Fibonacci;
//    pv = &Lucas;
//    ...
    const int seq_cnt = 6;
    vector<int> *seq_addrs[seq_cnt] = {
            &Fibonacci, &Lucas, &Pell, &Triangular, &Square, &Pentagonal
    };
    vector<int> *current_vec = 0;
    for (int idx=0; idx<seq_cnt; idx++) {
        current_vec = seq_addrs[idx];

    }

    return 0;
}

