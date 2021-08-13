#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#include <vector>
#include <string>
#include <iostream>

int cut(int aa, int bb, const char *que)
{
    int asd = 0, dd;
    for (int j = aa; j < (aa + bb); j++)
    {
        dd = que[j] - '0';
        asd = (asd * 10 + dd);
    }
    return asd;
}

int main()
{
    int n, i, j, k, cnt = 0, p;
    scanf("%d", &n);
    string a = "123456789";
    const char *que = a.c_str();
    do
    {
        for (i = 1; i < 9; ++i)
        {
            //从0开始截取i长度的a
            p = cut(0, i, que);
            if (p >= n)
            {
                break;
            }
            //检查是否等于n
            for (int j = 1; i + j < 9; ++j)
            {

                int s = cut(i, j, que);
                int q = cut(i + j, 9 - i - j, que);
                if (s / q > n - p)
                    break;
                if (s % q == 0 && (p + s / q) == n)
                    cnt++;
            }
        }
    } while (next_permutation(a.begin(), a.end()));

    printf("%d", cnt);

    return 0;
}
