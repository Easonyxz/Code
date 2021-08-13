#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
//给定 n 节台阶，每次可以走一步或走两步，求一共有多少种方式可以走完这些台阶。
/*
这是十分经典的斐波那契数列题。定义一个数组 dp，dp[i] 表示走到第 i 阶的方法数。因为
我们每次可以走一步或者两步，所以第 i 阶可以从第 i-1 或 i-2 阶到达。换句话说，走到第 i 阶的
方法数即为走到第 i-1 阶的方法数加上走到第 i-2 阶的方法数。这样我们就得到了状态转移方程
dp[i] = dp[i-1] + dp[i-2]。注意边界条件的处理。
*/
int main()
{
    int n;
    scanf("%d",&n);
    if (n <= 2) {printf("%d",n);return 0;};
long long pre2 = 1, pre1 = 2, cur;
for (int i = 2; i < n; ++i) {
cur = pre1 + pre2;
pre2 = pre1;
pre1 = cur;
}
  printf("%lld",cur);

    return 0;
}