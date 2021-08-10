#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <string>

using namespace std;

int parse(const char *arr, int pos, int len) {
    int ans = 0;
    int t = 1;
    for (int i = pos + len - 1; i >= pos; --i) {
        ans += (arr[i] - '0') * t;
        t *= 10;
    }
    return ans;
}

int main(int argc, const char *argv[]) {
    int n, ans = 0;
    scanf("%d", &n);
    std::string s = "123456789";
    do {
        const char *str = s.c_str();
        for (int i = 1; i <= 7; ++i) {//+号前的串的长度
//            string a = s.substr(0, i);
            int inta = parse(str, 0, i);
            if (inta >= n)break;

            for (int j = 1; j <= 9 - i - 1; ++j) {//+/两个符号之间的串的长度
//                string b = s.substr(i, j);
//                string c = s.substr(i + j);//这是/后面的串
//                int intb = atoi(b.c_str());
//                int intc = atoi(c.c_str());
                int intb = parse(str, i, j);
                int intc = parse(str, i + j, 9 - i - j);
                if (intb % intc == 0 && inta + intb / intc == n)ans++;
            }
        }
    } while (std::next_permutation(s.begin(), s.end()));
    printf("%d\n", ans);
    return 0;
}