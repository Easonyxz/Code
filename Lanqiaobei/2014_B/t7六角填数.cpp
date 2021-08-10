//
// Created by zhengwei.
//
/*
标题：六角填数

    如图【1.png】所示六角形中，填入1~12的数字。

    使得每条直线上的数字之和都相同。

    图中，已经替你填好了3个数字，请你计算星号位置所代表的数字是多少？

请通过浏览器提交答案，不要填写多余的内容。
 */

#include <iostream>
#include <vector>

using namespace std;

void check(vector<int> v);

int main(int argc, const char *argv[]) {
    vector<int> v;
    v.push_back(2);
    for (int i = 4; i <= 7; ++i) {
        v.push_back(i);
    }
    for (int i = 9; i <= 12; ++i) {
        v.push_back(i);
    }

    do {
        check(v);
    } while (next_permutation(v.begin(), v.end()));

    return 0;
}

void check(vector<int> v) {
    int r1 = 1 + v[0] + v[3] + v[5];
    int r2 = 1 + v[1] + v[4] + v[8];
    int r3 = 8 + v[0] + v[1] + v[2];
    int r4 = 11 + v[3] + v[6];
    int r5 = 3 + v[2] + v[4] + v[7];
    int r6 = v[5] + v[6] + v[7] + v[8];

    if (r1 == r2 && r2 == r3 && r3 == r4 && r4 == r5 && r5 == r6) {
        for (int i = 0; i < 9; ++i) {
            cout << v[i] << " " << endl;
        }
    }
}