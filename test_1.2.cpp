//
// Created by cedar on 2020/7/20.
//
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
using namespace std;

int main() {
    string user_name;       //用户的名字
    int usr_value;          //用户回答的数值
    int num_tries = 0;      //用户回答的次数
    int num_right = 0;      //用户答对的次数
    double usr_score = 0.0; //用户得到的评分
    bool next_seq = true;   //显示下一组数列
    bool go_for_it = true;  //用户想再猜一次
    char usr_rsp;           //用户回答Y/N

    const int seq_size = 18;
    int elem_vals[seq_size] = {
            1,2,3,  3,4,7,  2,5,12,
            3,6,10, 4,9,16, 5,12,22
    };
    vector<int> elem_seq(elem_vals, elem_vals+seq_size);    //利用已初始化的array作为该vector的初值

    const int max_seq = 6;
    string seq_names[max_seq] = {
            "Fibonacci",
            "Lucas",
            "Pell",
            "Triangular",
            "Square",
            "Pentagonal"
    };

    cout << "请输入你的名字：";
    cin >> user_name;
    ifstream infile("seq_data.txt");
    if (!infile)
        cout << "您是新用户\n";
    else {
        string name;
        int nt;
        int nr;
        //读取文件的每一行 name num_ties num_right,直到文件末尾
        while (infile >> name) {
            infile >> nt >> nr;
            if (name==user_name) {
                cout << "欢迎" << user_name <<"回来"
                     << "\n你当前的分数是" << 1.0*nr/nt << "\n";
                num_tries = nt;
                num_right = nr;
            }
            else
                cout << "您是新用户\n";
        }
    }
    int cur_tuple = 0;      //元素下标
    while (next_seq == true && cur_tuple < seq_size) {
        go_for_it = true;   //重置->用户想再猜一次默认值
        //为用户显示序列
        cout << "序列的前两个元素为："
             << elem_seq[cur_tuple] << ','
             << elem_seq[cur_tuple+1]
             << "\n下一个元素是什么呢？";
            cin >> usr_value;
            num_tries++;
        if (usr_value == elem_seq[cur_tuple+2]) {
            num_right++;
            cout << "第一次就正确了呢！"
                 << elem_seq[cur_tuple+2]
                 << "正是" << seq_names[cur_tuple/3] << "序列的下一个元素\n";
        }
        while (( usr_value != elem_seq[cur_tuple+2] ) && ( go_for_it == true )) {
            cout << "输入错误，是否再次尝试？Y/N";
            cin >> usr_rsp;
            if (usr_rsp=='N' || usr_rsp=='n')
                go_for_it = false;
            else {
                cout << "别灰心！下一个元素是什么呢？";
                cin >> usr_value;
                num_tries++;
                if (usr_value == elem_seq[cur_tuple+2]) {
                    num_right++;
                    cout << "终于正确了！"
                         << elem_seq[cur_tuple+2]
                         << "正是" << seq_names[cur_tuple/3] << "序列的下一个元素\n";
                    break;
                }
            }
        }

        vector<int> Fibonacci, Lucas, Pell, Triangular, Square, Pentagonal;
        const int seq_cnt = 6;
        vector<int> *seq_addrs[seq_cnt] = {
                &Fibonacci, &Lucas, &Pell, &Triangular, &Square, &Pentagonal
        };
        //随机选择下一个序列
        vector<int> *current_vec = 0;
        srand(seq_cnt);
        int idx = rand() % seq_cnt;
        current_vec = seq_addrs[idx];
        //换一种序列
        cout << "想尝试另一种序列吗？Y/N";
        cin >> usr_rsp;
        if (usr_rsp=='N' || usr_rsp=='n')
            next_seq = false;
        else
            cur_tuple += 3;
    }
    //计算得分
    usr_score = (1.0*num_right/num_tries)*100;
    cout << user_name << "的的得分为：" << usr_score;
    //保存结果，追加到末尾
    ofstream outfile("seq_data.txt", ios_base::app);
    if (!outfile) {
        cerr << "不能保存数据\n";
    } else {
        outfile << user_name << ' '
                << num_tries << ' '
                << num_right << endl;
    }
    return 0;
}

