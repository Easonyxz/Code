#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#include <vector>
#include<string>


int main()
{

    int year = 1, mouth = 1, day = 1;
    string a, b, c;
    while (mouth > 0 && day > 0) {

        scanf("%d %d", &mouth, &day);
        if (mouth<=0||day<0)return 0;
        year = 1;
        int mouth1 = mouth, day1 = day, year1 = 1;
        int cnt = 48, cnt1 = 60;
        while (year < 3) {
            if (day > 30) { int s = day / 30;mouth += s;day %= 30; }
            if (day < 10) c = "0";
            else c = "";
            if (mouth > 12) { year++;mouth -= 12; }
            if (mouth < 10) b = "0";
            else b = "";
            printf("%d年--%s%d月--%s%d日            ", year, b.c_str(), mouth, c.c_str(), day);
            if (day1 > 30) { int t = day1 / 30;mouth1 += t;day1 %= 30; }
            if (day1 < 10) c = "0";
            else c = "";
            if (mouth1 > 12) { year1++;mouth1 -= 12; }
            if (mouth1 < 10) b = "0";
            else b = "";
            printf("%d年--%s%d月--%s%d日\n", year1, b.c_str(), mouth1, c.c_str(), day1);
            day1 += cnt1;
            day += cnt;
        }
        printf("%d                               %d\n", cnt, cnt1);

    }
    return 0;
}
