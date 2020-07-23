#include <iostream>
#include <string>
using namespace std;

int main() {
    string first_name, last_name;
    cout << "依次输入你的名字和姓氏：";
    cin >> first_name   //名字
        >> last_name;   //姓氏
    cout << '\n'
        << "Hello, "
        << first_name << ' ' << last_name
        << " ...and goodbye!\n" << endl;
    return 0;
}
