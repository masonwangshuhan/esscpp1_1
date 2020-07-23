//
// Created by cedar on 2020/7/22.
//
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    ifstream infile("text.txt");
    if (!infile) {
        cerr << "不能打开文件";
        return -1;
    }
    string word;
    vector<string> text;
    while (infile >> word) {
        text.push_back(word);
    }
    cout << "未排序的文本是：\n";
    for (int i = 0; i < text.size(); ++i) {
        cout << text[i] << ' ';
    }
    cout << endl;

    ofstream outfile("text.txt");
    if (!outfile) {
        cerr << "不能打开文件";
        return -2;
    }
    //排序操作
    sort(text.begin(), text.end());
    outfile << "排序后的文本是：\n";
    for (int j = 0; j < text.size(); ++j) {
        outfile << text[j] << ' ';
    }
    outfile << endl;

    return 0;
}
